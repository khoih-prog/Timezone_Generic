## Timezone_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/Timezone_Generic.svg?)](https://www.ardu-badge.com/Timezone_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Timezone_Generic.svg)](https://github.com/khoih-prog/Timezone_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Timezone_Generic/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Timezone_Generic.svg)](http://github.com/khoih-prog/Timezone_Generic/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.7.1](#releases-v171)
  * [Releases v1.7.0](#releases-v170)
  * [Releases v1.6.0](#releases-v160)
  * [Major Releases v1.5.0](#major-releases-v150)
  * [Major Releases v1.4.0](#major-releases-v140)
  * [Major Releases v1.3.0](#major-releases-v130)
  * [Releases v1.2.6](#releases-v126)
  * [Releases v1.2.5](#releases-v125)
  * [Releases v1.2.4](#releases-v124)

---
---

## Changelog

### Releases v1.7.1

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix
2. Update `Packages' Patches`

### Releases v1.7.0

1. Add support to RTL8720DN, RTL8722DM, RTL8722CSM, etc. boards
2. Add examples with new features

### Releases v1.6.0

1. Add support to WT32_ETH01 (ESP32 + LAN8720) boards
2. Add examples with new features

### Major Releases v1.5.0

1. Add support to ESP32-S2 and ESP32-C3 boards
2. Verify OK with ESP32 core v1.0.6 and ESP8266 core v3.0.0
3. Fix bug.


### Major Releases v1.4.0

1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** v1.7.0+ core](https://github.com/earlephilhower/arduino-pico).
2. Add support to RP2040-based boards, such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** v2.1.0+ core](https://github.com/arduino/ArduinoCore-mbed).
3. Improve and add more debugging codes
4. Update examples with new features


###  Major Releases v1.3.0

1. Add support to ESP32/ESP8266 using LittleFS/SPIFFS
2. Add support to AVR, UNO WiFi Rev2 boards.
3. Clean-up all compiler warnings possible.
4. Optimize library and examples to reduce memory usage by using Flash String whenever possible.
5. Add Table of Contents

### Releases v1.2.6

1. Allow un-initialized TZ then use begin() method to set the actual TZ. Credit of **6v6gt**, see [**Timezone_Generic Library to convert UTC to local time**](https://forum.arduino.cc/index.php?topic=711259)
2. Modify examples to use new un-initialized-TZ feature.

### Releases v1.2.5

1. Add examples to use STM32 Built-In RTC.

### Releases v1.2.4

1. Initial porting to many Generic boards using WiFi/Ethernet modules/shields.
2. Add support to SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1 with WiFiNINA, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields.
3. Add support to SAM DUE DueFlashStorage, SAMD FlashStorage, nRF52 LittleFS, STM32 and AVR EEPROM
4. Add functions.
5. Completely new examples using NTP time to update DS3231 RTC.


