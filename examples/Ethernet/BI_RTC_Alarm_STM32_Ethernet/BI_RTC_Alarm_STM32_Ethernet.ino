/****************************************************************************************************************************
  BI_RTC_Alarm_STM32_Ethernet.ino

  Self-adjusting clock for one time zone using Built-in STM32 RTC

  For AVR, ESP8266/ESP32, SAMD21/SAMD51, nRF52, STM32, WT32_ETH01 boards

  Based on and modified from Arduino Timezone Library (https://github.com/JChristensen/Timezone)
  to support other boards such as ESP8266/ESP32, SAMD21, SAMD51, Adafruit's nRF52 boards, etc.

  Copyright (C) 2018 by Jack Christensen and licensed under GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

  Built by Khoi Hoang https://github.com/khoih-prog/Timezone_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/
/****************************************************************************************************************************
  STM32 has five clock sources: HSI, HSE, LSI, LSE, PLL.
  
  (1) HSI is a high-speed internal clock, RC oscillator, with a frequency of 8MHz and low accuracy.
  (2) HSE is a high-speed external clock, which can be connected with quartz/ceramic resonator or external clock source. 
      Its frequency range is from 4MHz to 16MHz.
  (3) LSI is a low-speed internal clock, RC oscillator, with a frequency of 40 kHz, providing a low-power clock. 　
  (4) LSE is a low-speed external clock connected to 32.768 kHz quartz crystal.
  (5) PLL is the frequency doubling output of PLL, and its clock input source can be HSI/2, HSE or HSE/2. 
      Frequency doubling can be chosen as 2 to 16 times, but the maximum output frequency should not exceed 72MHz.
      
  The system clock SYSCLK can be derived from three clock sources:
  (1) HSI oscillator clock
  (2) HSE oscillator clock
  (3) PLL Clock
  STM32 can choose a clock signal to output to MCO foot (PA8), and can choose 2-frequency, HSI, HSE, or system clock for PLL output.
  Before any peripheral can be used, its corresponding clock must be enabled first.
 *****************************************************************************************************************************/
 
#include "defines.h"

#define TIMEZONE_GENERIC_VERSION_MIN_TARGET      "Timezone_Generic v1.10.1"
#define TIMEZONE_GENERIC_VERSION_MIN             1010001

//////////////////////////////////////////

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <Timezone_Generic.h>           // https://github.com/khoih-prog/Timezone_Generic

#include <STM32RTC.h>

/* Get the rtc object */
STM32RTC& rtc = STM32RTC::getInstance();

//////////////////////////////////////////

#define USING_INITIALIZED_TZ      false   //true

#if USING_INITIALIZED_TZ
  // US Eastern Time Zone (New York, Detroit,Toronto)
  TimeChangeRule myDST = {"EDT", Second, Sun, Mar, 2, -240};    // Daylight time = UTC - 4 hours
  TimeChangeRule mySTD = {"EST", First,  Sun, Nov, 2, -300};    // Standard time = UTC - 5 hours
  Timezone myTZ(myDST, mySTD);
#else
  // Allow a "blank" TZ object then use begin() method to set the actual TZ.
  // Feature added by 6v6gt (https://forum.arduino.cc/index.php?topic=711259)
  Timezone myTZ ;
  TimeChangeRule myDST;
  TimeChangeRule mySTD;
#endif

// If TimeChangeRules are already stored in EEPROM, comment out the three
// lines above and uncomment the line below.
//Timezone myTZ(100);       //assumes rules stored at EEPROM address 100

TimeChangeRule *tcr;        //pointer to the time change rule, use to get TZ abbrev

//////////////////////////////////////////

char timeServer[]         = "time.nist.gov";  // NTP server
unsigned int localPort    = 2390;             // local port to listen for UDP packets

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message
const int UDP_TIMEOUT     = 2000;     // timeout in miliseconds to wait for an UDP packet to arrive

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

// send an NTP request to the time server at the given address
void sendNTPpacket(char *ntpSrv)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)

  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(ntpSrv, 123); //NTP requests are to port 123

  Udp.write(packetBuffer, NTP_PACKET_SIZE);

  Udp.endPacket();
}

void update_RTC(unsigned long epoch)
{
  // Update RTC
  Serial.println("\nUpdating Time for STM32 RTC");

  // STM32 RTC clock starts from 01/01/2000 if not set. No battery-backed RTC.
  // STM32 RTC specific code

  // Can use either one of these functions
  
  // 1. The best way to set from epoch
  rtc.setEpoch(epoch);
  
  // 2. you can also use the harder way
  // Get the time_t from epoch
  //time_t epoch_t = epoch;
  //rtc.setTime(hour(epoch_t), minute(epoch_t), second(epoch_t));
  //rtc.setDate(weekday(epoch_t), day(epoch_t), month(epoch_t), year(epoch_t));
}

void alarmMatch(void *data)
{
  UNUSED(data);
  Serial.println("*****RTC ALARM ACTIVATED*****");
  Serial.println("*****RTC ALARM ACTIVATED*****");
}

void setRTC_Alarm(unsigned long epochAlarm)
{
  rtc.attachInterrupt(alarmMatch);

  // Alarm at epochAlarm
  rtc.setAlarmEpoch(epochAlarm, rtc.MATCH_DHHMMSS);

  // Display Alarm time from RTC
  Serial.println("=======RTC ALARM SET========");

  // STM32 RTC specific code
  time_t utcAlarm   = epochAlarm;
  time_t localAlarm = myTZ.toLocal(utcAlarm, &tcr);
  //////

  printDateTime(utcAlarm, "UTC");
  printDateTime(localAlarm, tcr -> abbrev);
  Serial.println("============================");
}

void getNTPTime(void)
{
  static bool gotCurrentTime = false;

  // Just get the correct ime once
  if (!gotCurrentTime)
  {
    sendNTPpacket(timeServer); // send an NTP packet to a time server
    // wait to see if a reply is available
    delay(1000);

    if (Udp.parsePacket())
    {
      Serial.println(F("Packet received"));
      // We've received a packet, read the data from it
      Udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

      //the timestamp starts at byte 40 of the received packet and is four bytes,
      // or two words, long. First, esxtract the two words:

      unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
      unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
      // combine the four bytes (two words) into a long integer
      // this is NTP time (seconds since Jan 1 1900):
      unsigned long secsSince1900 = highWord << 16 | lowWord;
      Serial.print(F("Seconds since Jan 1 1900 = "));
      Serial.println(secsSince1900);

      // now convert NTP time into everyday time:
      Serial.print(F("Unix time = "));
      // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
      const unsigned long seventyYears = 2208988800UL;
      // subtract seventy years:
      unsigned long epoch = secsSince1900 - seventyYears;

      // print Unix time:
      Serial.println(epoch);
      
      // Get the time_t from epoch
      time_t epoch_t = epoch;

      // set the system time to UTC
      // warning: assumes that compileTime() returns US EDT
      // adjust the following line accordingly if you're in another time zone
      setTime(epoch_t);

      update_RTC(epoch);

      // Set test alarm after 30s
      setRTC_Alarm(epoch + 30L);
       
      // print the hour, minute and second:
      Serial.print(F("The UTC time is "));       // UTC is the time at Greenwich Meridian (GMT)
      Serial.print((epoch  % 86400L) / 3600); // print the hour (86400 equals secs per day)
      Serial.print(':');

      if (((epoch % 3600) / 60) < 10)
      {
        // In the first 10 minutes of each hour, we'll want a leading '0'
        Serial.print('0');
      }
      Serial.print((epoch  % 3600) / 60); // print the minute (3600 equals secs per minute)
      Serial.print(':');

      if ((epoch % 60) < 10)
      {
        // In the first 10 seconds of each minute, we'll want a leading '0'
        Serial.print('0');
      }
      Serial.println(epoch % 60); // print the second

      gotCurrentTime = true;
    }
    else
    {
      // wait ten seconds before asking for the time again
      delay(10000);
    }
  }
}

//////////////////////////////////////////

// format and print a time_t value, with a time zone appended.
void printDateTime(time_t t, const char *tz)
{
  char buf[32];
  char m[4];    // temporary storage for month string (DateStrings.cpp uses shared buffer)
  strcpy(m, monthShortStr(month(t)));
  sprintf(buf, "%.2d:%.2d:%.2d %s %.2d %s %d %s",
          hour(t), minute(t), second(t), dayShortStr(weekday(t)), day(t), m, year(t), tz);
  Serial.println(buf);
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  delay(200);

  Serial.print(F("\nStart BI_RTC_Alarm_STM32_Ethernet on ")); Serial.print(BOARD_NAME);
  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);
  Serial.println(TIMEZONE_GENERIC_VERSION);
  
#if defined(TIMEZONE_GENERIC_VERSION_MIN)
  if (TIMEZONE_GENERIC_VERSION_INT < TIMEZONE_GENERIC_VERSION_MIN)
  {
    Serial.print("Warning. Must use this example on Version equal or later than : ");
    Serial.println(TIMEZONE_GENERIC_VERSION_MIN_TARGET);
  }
#endif

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)

  ET_LOGWARN3(F("Board :"), BOARD_NAME, F(", setCsPin:"), USE_THIS_SS_PIN);

  ET_LOGWARN(F("Default SPI pinout:"));
  ET_LOGWARN1(F("MOSI:"), MOSI);
  ET_LOGWARN1(F("MISO:"), MISO);
  ET_LOGWARN1(F("SCK:"),  SCK);
  ET_LOGWARN1(F("SS:"),   SS);
  ET_LOGWARN(F("========================="));

  // For other boards, to change if necessary
  #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
    // Must use library patch for Ethernet, Ethernet2, EthernetLarge libraries
    Ethernet.init (USE_THIS_SS_PIN);
   
  #elif USE_CUSTOM_ETHERNET
    // You have to add initialization for your Custom Ethernet here
    // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
    //Ethernet.init(USE_THIS_SS_PIN);
  
  #endif  //( ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
#endif

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(Ethernet.localIP());

#if !(USING_INITIALIZED_TZ)

  // Can read this info from EEPROM, storage, etc
  String tzName = "EDT/EST" ;

  // Time zone rules can be set as below or dynamically built, say through a configuration
  //  interface, or fetched from eeprom, flash etc.

  if ( tzName == "EDT/EST" )
  {
    // America Eastern Time
    myDST = (TimeChangeRule) {"EDT",  Second, Sun, Mar, 2, -240};    // Daylight time = UTC - 4 hours
    mySTD = (TimeChangeRule) {"EST",  First,  Sun, Nov, 2, -300};     // Standard time = UTC - 5 hours
  }
  else if ( tzName == "CET/CEST" ) 
  {
    // central Europe
    myDST = (TimeChangeRule) {"CEST", Last, Sun, Mar, 2, 120};
    mySTD = (TimeChangeRule) {"CET",  Last, Sun, Oct, 3, 60};
  }
  
  else if ( tzName == "GMT/BST" ) 
  {
    // UK
    myDST = (TimeChangeRule) {"BST",  Last, Sun, Mar, 1, 60};
    mySTD = (TimeChangeRule) {"GMT",  Last, Sun, Oct, 2, 0};
  }

  myTZ.init( myDST, mySTD ) ;
  
#endif

  Udp.begin(localPort);

  // STM32 RTC specific code
  // Select RTC clock source: LSI_CLOCK, LSE_CLOCK or HSE_CLOCK.
  // By default the LSI is selected as source.
  //rtc.setClockSource(STM32RTC::LSE_CLOCK);
  rtc.begin(); // initialize RTC 24H format
  //////
}

void loop()
{
  // Get time from NTP once, then update RTC
  // You certainly can make NTP check every hour/day to update RTC ti have better accuracy
  getNTPTime();

  // Display time from RTC
  Serial.println("============================");

  // STM32 RTC specific code
  time_t utc = rtc.getEpoch();
  time_t local = myTZ.toLocal(utc, &tcr);
  //////
  
  printDateTime(utc, "UTC");
  printDateTime(local, tcr -> abbrev);
  
  delay(10000);
}
