/****************************************************************************************************************************
  Timezone_Generic.h
  
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

#pragma once

// For AVR, Teensy, STM32 boards, use EEPROM
// For SAM DUE, use DueFlashStorage. 
// For SAMD, use FlashStorage_SAMD
// For nRF52, use LittleFS/InternalFS.
// For ESP8266, use LitteFS, SPIFFS or EEPROM.
// For ESP32, use SPIFFS or EEPROM.

#if defined(ARDUINO) && (ARDUINO >= 100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include <TimeLib.h>    // https://github.com/PaulStoffregen/Time

#include "Timezone_Generic_Debug.h"

// convenient constants for TimeChangeRules
enum week_t   {Last, First, Second, Third, Fourth};
enum dow_t    {Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat};
enum month_t  {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

// structure to describe rules for when daylight/summer time begins,
// or when standard time begins.
typedef struct 
{
  char    abbrev[6];    // five chars max
  uint8_t week;         // First, Second, Third, Fourth, or Last week of the month
  uint8_t dow;          // day of week, 1=Sun, 2=Mon, ... 7=Sat
  uint8_t month;        // 1=Jan, 2=Feb, ... 12=Dec
  uint8_t hour;         // 0-23
  int     offset;       // offset from UTC in minutes
} TimeChangeRule;

#define TZ_DATA_SIZE    sizeof(TimeChangeRule)

class Timezone
{
  public:
    Timezone(TimeChangeRule dstStart, TimeChangeRule stdStart);
    Timezone(TimeChangeRule stdTime);
    Timezone(int address);
    
    // Allow a "blank" TZ object then use begin() method to set the actual TZ.
    // Feature added by 6v6gt (https://forum.arduino.cc/index.php?topic=711259)
    Timezone(void);
		void init(TimeChangeRule dstStart, TimeChangeRule stdStart);
		//////
    
    time_t  toLocal(time_t utc);
    time_t  toLocal(time_t utc, TimeChangeRule **tcr);
    time_t  toUTC(time_t local);
    bool    utcIsDST(time_t utc);
    bool    locIsDST(time_t local);
    void    setRules(TimeChangeRule dstStart, TimeChangeRule stdStart);
    
    //void    readRules(int address);
    void    readRules(void);
    void    writeRules(int address = 0);
    
    TimeChangeRule* read_DST_Rule(void)
    {
      return &m_dst;
    }
    
    TimeChangeRule* read_STD_Rule(void)
    {
      return &m_std;
    }
    
    void display_DST_Rule(void);  
    void display_STD_Rule(void);

  private:
    void    calcTimeChanges(int yr);
    void    initTimeChanges();
    time_t  toTime_t(TimeChangeRule r, int yr);
    
    TimeChangeRule m_dst;   // rule for start of dst or summer time for any year
    TimeChangeRule m_std;   // rule for start of standard time for any year
    
    time_t m_dstUTC;        // dst start for given/current year, given in UTC
    time_t m_stdUTC;        // std time start for given/current year, given in UTC
    time_t m_dstLoc;        // dst start for given/current year, given in local time
    time_t m_stdLoc;        // std time start for given/current year, given in local time
    
    void      readTZData(void);
    void      writeTZData(int address);
    
    uint16_t  TZ_DATA_START     = 0;
    
    bool      storageSystemInit = false;
};

#include "Timezone_Generic_Impl.h"

