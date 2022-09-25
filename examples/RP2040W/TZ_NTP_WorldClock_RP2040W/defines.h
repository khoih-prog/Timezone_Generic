/****************************************************************************************************************************
  defines.h
  
  For AVR, ESP8266/ESP32, SAMD21/SAMD51, nRF52, STM32, WT32_ETH01 boards

  Based on and modified from Arduino Timezone Library (https://github.com/JChristensen/Timezone)
  to support other boards such as ESP8266/ESP32, SAMD21, SAMD51, Adafruit's nRF52 boards, etc.

  Copyright (C) 2018 by Jack Christensen and licensed under GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

  Built by Khoi Hoang https://github.com/khoih-prog/Timezone_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

// Debug Level from 0 to 4
#define _TZ_LOGLEVEL_       1

#if ( defined(ARDUINO_RASPBERRY_PI_PICO_W) )

  #if defined(ARDUINO_ARCH_MBED)

    #if defined(BOARD_NAME)
      #undef BOARD_NAME
    #endif
    
    // Not supported yet. Just for the future
    #define BOARD_NAME      "MBED RASPBERRY_PI_PICO_W"

    #error Core mbed_rp2040 not supporting RP2040W yet.
    
  #endif
  
#else
  #error This code is designed to run on RP2040W platform! Please check your Tools->Board setting.
#endif

#ifndef BOARD_NAME
  #if defined(ARDUINO_BOARD)
    #define BOARD_NAME      ARDUINO_BOARD
  #endif  
#endif

#include <WiFi.h>

char ssid[] = "ssid";             // your network SSID (name)
char pass[] = "12345678";         // your network password

#endif    //defines_h
