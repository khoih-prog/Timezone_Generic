/****************************************************************************************************************************
  WriteRules.ino

  Write TimeChangeRules to EEPROM.

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

#define TZ_DBG_PORT         Serial
#define _TZ_LOGLEVEL_       4

#include <Timezone_Generic.h>   // https://github.com/khoih-prog/Timezone_Generic

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

#ifndef LED_BUILTIN
  #define LED_BUILTIN       13
#endif

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  while (!Serial);
  
#if defined(ARDUINO_BOARD)
  Serial.println("\nStart WriteRules on " + String(ARDUINO_BOARD));
#elif defined(BOARD_NAME)
  Serial.println("\nStart WriteRules on " + String(BOARD_NAME));
#else
  Serial.println("\nStart WriteRules");
#endif

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
 
  myTZ.writeRules(0);    // write rules to address/offset 0

  Serial.println("WriteRules done");

  myTZ.readRules();        // read back rules from address/offset 0

  Serial.println("readRules done");

  myTZ.display_DST_Rule();
  myTZ.display_STD_Rule();

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
