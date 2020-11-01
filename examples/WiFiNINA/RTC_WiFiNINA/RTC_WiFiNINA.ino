/****************************************************************************************************************************
  RTC_WiFiNINA.ino

  Self-adjusting clock for one time zone using an external DS3231 RTC
  
  For AVR, ESP8266/ESP32, SAMD21/SAMD51, nRF52, STM32 boards

  Based on and modified from Arduino Timezone Library (https://github.com/JChristensen/Timezone)
  to support other boards such as ESP8266/ESP32, SAMD21, SAMD51, Adafruit's nRF52 boards, etc.

  Copyright (C) 2018 by Jack Christensen and licensed under GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

  Built by Khoi Hoang https://github.com/khoih-prog/Timezone_Generic
  Licensed under MIT license
  Version: 1.2.6

  Version Modified By  Date      Comments
  ------- -----------  ---------- -----------
  1.2.4   K Hoang      17/10/2020 Initial porting to support SAM DUE, SAMD21, SAMD51, nRF52, ESP32/ESP8266, STM32, etc. boards
                                  using SPIFFS, LittleFS, EEPROM, FlashStorage, DueFlashStorage.
  1.2.5   K Hoang      28/10/2020 Add examples to use STM32 Built-In RTC.
  1.2.6   K Hoang      01/11/2020 Allow un-initialized TZ then use begin() method to set the actual TZ (Credit of 6v6gt)
 *****************************************************************************************************************************/

#include "defines.h"

#include <Timezone_Generic.h>             // https://github.com/khoih-prog/Timezone_Generic

#include <DS323x_Generic.h>               // https://github.com/khoih-prog/DS323x_Generic

DS323x rtc;

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

TimeChangeRule *tcr;        //pointer to the time change rule, use to get TZ abbrev

//////////////////////////////////////////

int status = WL_IDLE_STATUS;      // the Wifi radio's status

char timeServer[]         = "time.nist.gov";  // NTP server
unsigned int localPort    = 2390;             // local port to listen for UDP packets

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message
const int UDP_TIMEOUT     = 2000;     // timeout in miliseconds to wait for an UDP packet to arrive

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;

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

      // Update RTC
      // Can use either one of these functions
      
      // 1) DateTime(tmElements_t). Must create tmElements_t if not present
      //tmElements_t tm;
      //breakTime(epoch_t, tm);
      //rtc.now( DateTime(tm) );
      
      // 2) DateTime(year, month, day, hour, min, sec)
      //rtc.now( DateTime(year(epoch_t), month(epoch_t), day(epoch_t), hour(epoch_t), minute(epoch_t), second(epoch_t) ) );

      // 3) DateTime (time_t)
      //rtc.now( DateTime(epoch_t) );

      // 4) DateTime(unsigned long epoch). The best and easiest way
      rtc.now( DateTime(epoch) );
       
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

  Serial.print("\nStart RTC_WiFiNINA on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));

  Wire.begin();

  // check for the presence of the shield
#if USE_WIFI_NINA
  if (WiFi.status() == WL_NO_MODULE)
#else
  if (WiFi.status() == WL_NO_SHIELD)
#endif
  {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  }

#if USE_WIFI_NINA
  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println(F("Please upgrade the firmware"));
  }
#endif

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED)
  {
    Serial.print(F("Connecting to WPA SSID: "));
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(WiFi.localIP());

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

  rtc.attach(Wire);
}

void loop()
{
  // Get time from NTP once, then update RTC
  // You certainly can make NTP check every hour/day to update RTC ti have better accuracy
  getNTPTime();

  // Display time from RTC
  DateTime now = rtc.now();

  Serial.println("============================");

  time_t utc = now.get_time_t();
  time_t local = myTZ.toLocal(utc, &tcr);
  
  printDateTime(utc, "UTC");
  printDateTime(local, tcr -> abbrev);
  
  delay(10000);
}
