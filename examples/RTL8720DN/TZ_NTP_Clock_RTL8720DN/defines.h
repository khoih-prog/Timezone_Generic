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

#define DEBUG_WIFI_WEBSERVER_PORT   Serial
#define NTP_DBG_PORT                Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             3
#define _NTP_LOGLEVEL_              0
#define _TZ_LOGLEVEL_               3

#include <WiFiWebServer_RTL8720.h>

char ssid[] = "SSID_5GHz";        // your network SSID (name)
char pass[] = "12345678";        // your network password

#endif    //defines_h
