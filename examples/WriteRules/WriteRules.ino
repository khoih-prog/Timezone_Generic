/****************************************************************************************************************************
  WriteRules.ino

  Write TimeChangeRules to EEPROM.

  For AVR, ESP8266/ESP32, SAMD21/SAMD51, nRF52, STM32, WT32_ETH01 boards

  Based on and modified from Arduino Timezone Library (https://github.com/JChristensen/Timezone)
  to support other boards such as ESP8266/ESP32, SAMD21, SAMD51, Adafruit's nRF52 boards, etc.

  Copyright (C) 2018 by Jack Christensen and licensed under GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

  Built by Khoi Hoang https://github.com/khoih-prog/Timezone_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#if (ESP8266 || ESP32)
  #define USE_LITTLEFS      true
  #define USE_SPIFFS        false
#endif

#define TZ_DBG_PORT         Serial
#define _TZ_LOGLEVEL_       1

#define TIMEZONE_GENERIC_VERSION_MIN_TARGET      "Timezone_Generic v1.10.1"
#define TIMEZONE_GENERIC_VERSION_MIN             1010001

//////////////////////////////////////////

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <Timezone_Generic.h>           // https://github.com/khoih-prog/Timezone_Generic

#define USING_INITIALIZED_TZ      false   //true

#if USING_INITIALIZED_TZ
  // US Eastern Time Zone (New York, Detroit,Toronto)
  TimeChangeRule myDST = {"EDT", Second, Sun, Mar, 2, -240};    // Daylight time = UTC - 4 hours
  TimeChangeRule mySTD = {"EST", First,  Sun, Nov, 2, -300};    // Standard time = UTC - 5 hours
  Timezone *myTZ;
#else
  // Allow a "blank" TZ object then use begin() method to set the actual TZ.
  // Feature added by 6v6gt (https://forum.arduino.cc/index.php?topic=711259)
  Timezone *myTZ;
  TimeChangeRule myDST;
  TimeChangeRule mySTD;
#endif

#ifndef LED_BUILTIN
  #define LED_BUILTIN       13
#endif

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  delay(200);

  Serial.print(F("\nStart WriteRules on "));

#if defined(ARDUINO_BOARD)
  Serial.println(ARDUINO_BOARD);
#elif defined(BOARD_NAME)
  Serial.println(BOARD_NAME);
#else
  Serial.println();
#endif

  Serial.println(TIMEZONE_GENERIC_VERSION);
  
#if defined(TIMEZONE_GENERIC_VERSION_MIN)
  if (TIMEZONE_GENERIC_VERSION_INT < TIMEZONE_GENERIC_VERSION_MIN)
  {
    Serial.print("Warning. Must use this example on Version equal or later than : ");
    Serial.println(TIMEZONE_GENERIC_VERSION_MIN_TARGET);
  }
#endif

#if (USING_INITIALIZED_TZ)

  myTZ = new Timezone(myDST, mySTD);

#else

  // Can read this info from EEPROM, storage, etc
  String tzName = "EDT/EST" ;

  // Time zone rules can be set as below or dynamically built, say through a configuration
  //  interface, or fetched from eeprom, flash etc.

  if ( tzName == "EDT/EST" )
  {
    // America Eastern Time
    myDST = (TimeChangeRule) 
    {
      "EDT",  Second, Sun, Mar, 2, -240
    };     // Daylight time = UTC - 4 hours
    
    mySTD = (TimeChangeRule) 
    {
      "EST",  First,  Sun, Nov, 2, -300
    };     // Standard time = UTC - 5 hours
  }
  else if ( tzName == "CET/CEST" )
  {
    // central Europe
    myDST = (TimeChangeRule) 
    {
      "CEST", Last, Sun, Mar, 2, 120
    };
    
    mySTD = (TimeChangeRule) 
    {
      "CET",  Last, Sun, Oct, 3, 60
    };
  }

  else if ( tzName == "GMT/BST" )
  {
    // UK
    myDST = (TimeChangeRule) 
    {
      "BST",  Last, Sun, Mar, 1, 60
    };
    
    mySTD = (TimeChangeRule) 
    {
      "GMT",  Last, Sun, Oct, 2, 0
    };
  }

  myTZ = new Timezone();
  myTZ->init( myDST, mySTD );

#endif

  myTZ->writeRules(0);    // write rules to address/offset 0

  Serial.println(F("WriteRules done"));

  myTZ->readRules();        // read back rules from address/offset 0

  Serial.println(F("readRules done"));

  myTZ->display_DST_Rule();
  myTZ->display_STD_Rule();

  Serial.flush();
}

void loop()
{
  // fast blink to indicate EEPROM write is complete
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN, LOW);
  delay(300);
}
