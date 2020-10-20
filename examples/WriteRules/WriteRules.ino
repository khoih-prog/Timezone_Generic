// Arduino Timezone Library Copyright (C) 2018 by Jack Christensen and
// licensed under GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Arduino Timezone Library example sketch.
// Write TimeChangeRules to EEPROM.
// Jack Christensen Mar 2012

#define TZ_DBG_PORT         Serial
#define _TZ_LOGLEVEL_       4

#include <Timezone_Generic.h>   // https://github.com/khoih-prog/Timezone_Generic

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule usEdt = {"EDT", Second, Sun, Mar, 2, -240};    // UTC - 4 hours
TimeChangeRule usEst = {"EST", First, Sun, Nov, 2, -300};     // UTC - 5 hours

Timezone usEastern(usEdt, usEst);

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
 
  usEastern.writeRules(0);    // write rules to address/offset 0

  Serial.println("WriteRules done");

  usEastern.readRules();        // read back rules from address/offset 0

  Serial.println("readRules done");

  usEastern.display_DST_Rule();
  usEastern.display_STD_Rule();

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
