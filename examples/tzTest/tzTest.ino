/****************************************************************************************************************************
  TZTest.ino

  Sketch to verify operation of Timezone library.

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

#include <Timezone_Generic.h>   // https://github.com/khoih-prog/Timezone_Generic
#include <TimeLib.h>            // https://github.com/PaulStoffregen/Time

// New Zealand Time Zone
TimeChangeRule nzSTD = {"NZST", First, Sun, Apr, 3, 720};   // UTC + 12 hours
TimeChangeRule nzDST = {"NZDT", Last, Sun, Sep, 2, 780};    // UTC + 13 hours
Timezone nz(nzDST, nzSTD);

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule etDST = {"EDT", Second, Sun, Mar, 2, -240};  // Daylight time = UTC - 4 hours
TimeChangeRule etSTD = {"EST", First, Sun, Nov, 2, -300};   // Standard time = UTC - 5 hours
Timezone et(etDST, etSTD);

#ifndef LED_BUILTIN
  #define LED_BUILTIN       13
#endif

// format and print a time_t value, with a time zone appended.
void printDateTime(time_t t, const char *tz)
{
  char buf[32];
  char m[4];    // temporary storage for month string (DateStrings.cpp uses shared buffer)
  
  strcpy(m, monthShortStr(month(t)));
  sprintf(buf, "%.2d:%.2d:%.2d %s %.2d %s %d %s",
          hour(t), minute(t), second(t), dayShortStr(weekday(t)), day(t), m, year(t), tz);
  Serial.print(buf);
}

// print corresponding UTC and local times "n" seconds before and after the time change.
// h is the hour to change the clock using the *current* time (i.e. before the change).
// offset is the utc offset in minutes for the time *after* the change.
void printTimes(uint8_t d, uint8_t m, int y, uint8_t h, int offset, Timezone tz)
{
  const time_t n(3);      // number of times to print before and after the time change
  tmElements_t tm;
  tm.Hour = h;
  tm.Minute = 0;
  tm.Second = 0;
  tm.Day = d;
  tm.Month = m;
  tm.Year = y - 1970;     // offset from 1970
  time_t utc = makeTime(tm) - offset * SECS_PER_MIN - n;

  Serial.print(F("\n-------- "));
  Serial.print(monthShortStr(m));
  Serial.print('-');
  Serial.print(y);
  Serial.print(F(" time change --------\n"));

  for (uint16_t i = 0; i < n * 2; i++)
  {
    TimeChangeRule *tcr;    // pointer to the time change rule, use to get TZ abbrev
    time_t local = tz.toLocal(utc, &tcr);
    printDateTime(utc, "UTC = ");
    printDateTime(local, tcr -> abbrev);
    Serial.println();
    ++utc;
  }
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  while (!Serial);

#if defined(ARDUINO_BOARD)
  Serial.println("\nStarting TZTest on " + String(ARDUINO_BOARD));
#elif defined(BOARD_NAME)
  Serial.println("\nStarting TZTest on " + String(BOARD_NAME));
#else
  Serial.println("\nStarting TZTest");
#endif

  // New Zealand
  printTimes( 1,  4, 2018, nzSTD.hour, nzDST.offset, nz); // day, month, year, hour, offset, tz
  printTimes(30,  9, 2018, nzDST.hour, nzSTD.offset, nz);
  printTimes( 7,  4, 2019, nzSTD.hour, nzDST.offset, nz);
  printTimes(29,  9, 2019, nzDST.hour, nzSTD.offset, nz);
  printTimes( 5,  4, 2020, nzSTD.hour, nzDST.offset, nz);
  printTimes(27,  9, 2020, nzDST.hour, nzSTD.offset, nz);

  // US Eastern
  printTimes(11,  3, 2018, etDST.hour, etSTD.offset, et); // day, month, year, hour, offset, tz
  printTimes( 4, 11, 2018, etSTD.hour, etDST.offset, et);
  printTimes(10,  3, 2019, etDST.hour, etSTD.offset, et);
  printTimes( 3, 11, 2019, etSTD.hour, etDST.offset, et);
  printTimes( 8,  3, 2020, etDST.hour, etSTD.offset, et);
  printTimes( 1, 11, 2020, etSTD.hour, etDST.offset, et);
}

void loop()
{
  // fast blink to indicate running
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN, LOW);
  delay(300);
}
