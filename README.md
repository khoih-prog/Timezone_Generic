## Timezone_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/Timezone_Generic.svg?)](https://www.ardu-badge.com/Timezone_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Timezone_Generic.svg)](https://github.com/khoih-prog/Timezone_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Timezone_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Timezone_Generic.svg)](http://github.com/khoih-prog/Timezone_Generic/issues)

---
---

## Table of Contents

* [Why do we need this Timezone_Generic library](#why-do-we-need-this-timezone_generic-library)
  * [Features](#features)
  * [Currently Supported Boards](#currently-supported-boards)
  * [Currently Supported WiFi Modules and Shields](#currently-supported-wifi-modules-and-shields)
  * [Currently Supported Ethernet Modules and Shields](#currently-supported-ethernet-modules-and-shields)
  * [Currently Supported Storage](#currently-supported-storage)
* [Changelog](#changelog)
  * [Major Releases v1.4.0](#major-releases-v140)
  * [Major Releases v1.3.0](#major-releases-v130)
  * [Releases v1.2.6](#releases-v126)
  * [Releases v1.2.5](#releases-v125)
  * [Releases v1.2.4](#releases-v124)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Adafruit nRF52840 and nRF52832 boards](#1-for-adafruit-nRF52840-and-nRF52832-boards)
  * [2. For Teensy boards](#2-for-teensy-boards)
  * [3. For Arduino SAM DUE boards](#3-for-arduino-sam-due-boards)
  * [4. For Arduino SAMD boards](#4-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [5. For Adafruit SAMD boards](#5-for-adafruit-samd-boards)
  * [6. For Seeeduino SAMD boards](#6-for-seeeduino-samd-boards)
  * [7. For STM32 boards](#7-for-stm32-boards) 
    * [7.1. For STM32 boards to use LAN8720](#71-for-stm32-boards-to-use-lan8720)
    * [7.2. For STM32 boards to use Serial1](#72-for-stm32-boards-to-use-serial1)
  * [8. For RP2040-based boards using Earle Philhower arduino-pico core](#8-for-rp2040-based-boards-using-earle-philhower-arduino-pico-core)
    * [8.1. To use BOARD_NAME](#81-to-use-board_name)
    * [8.2. To avoid compile error relating to microsecondsToClockCycles](#82-to-avoid-compile-error-relating-to-microsecondstoclockcycles)
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
  * [7. For fixing ESP32 compile error](#7-for-fixing-esp32-compile-error)
  * [8. For fixing ESP8266 compile error](#8-for-fixing-esp8266-compile-error)
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [Usage](#usage)
  * [TimeChangeRules struct](#timechangerules-struct)
  * [Timezone class](#timezone-class)
    * [1. Using initialzed Timezone](#1-using-initialzed-timezone)
    * [2. Using un-initialzed Timezone (from v1.2.6)](#2-using-un-initialzed-timezone-from-v126)
  * [Timezone_Generic library methods](#timezone_generic-library-methods)
    * [time_t toLocal(time_t utc);](#time_t-tolocaltime_t-utc)
    * [time_t toLocal(time_t utc, TimeChangeRule **tcr);](#time_t-tolocaltime_t-utc-timechangerule-tcr)
    * [bool utcIsDST(time_t utc);](#bool-utcisdsttime_t-utc)
    * [bool locIsDST(time_t local);](#bool-locisdsttime_t-local)
    * [void readRules(int address);](#void-readrulesint-address)
    * [void writeRules(int address);](#void-writerulesint-address)
    * [void setRules(TimeChangeRule dstStart, TimeChangeRule stdStart);](#void-setrulestimechangerule-dststart-timechangerule-stdstart)
    * [time_t toUTC(time_t local);](#time_t-toutctime_t-local)
    * [TimeChangeRule* read_DST_Rule(void);](#timechangerule-read_dst_rulevoid)
    * [TimeChangeRule* read_STD_Rule(void);](#timechangerule-read_std_rulevoid)
    * [void display_DST_Rule(void);](#void-display_dst_rulevoid)
    * [void display_STD_Rule(void);](#void-display_std_rulevoid)
* [Examples](#examples)
  * [Generic Boards](#generic-boards) 
    * [ 1. tzTest](examples/tzTest)
    * [ 2. WriteRules](examples/WriteRules)
  * [Generic Boards with Ethernet](#generic-boards-with-ethernet)
    * [ 3. RTC_Ethernet](examples/Ethernet/RTC_Ethernet)
    * [ 4. TZ_NTP_Clock_Ethernet](examples/Ethernet/TZ_NTP_Clock_Ethernet)
    * [ 5. TZ_NTP_WorldClock_Ethernet](examples/Ethernet/TZ_NTP_WorldClock_Ethernet)
  * [STM32F/L/H/G/WB/MP1 Boards with Ethernet](#stm32flhgwbmp1-boards-with-ethernet)
    * [ 6. BI_RTC_Alarm_STM32_Ethernet](examples/Ethernet/BI_RTC_Alarm_STM32_Ethernet)
    * [ 7. BI_RTC_STM32_Ethernet](examples/Ethernet/BI_RTC_STM32_Ethernet)
    * [ 8. RTC_STM32_Ethernet](examples/Ethernet/RTC_STM32_Ethernet)
    * [ 9. TZ_NTP_Clock_STM32_Ethernet](examples/Ethernet/TZ_NTP_Clock_STM32_Ethernet)
    * [10. TZ_NTP_WorldClock_STM32_Ethernet](examples/Ethernet/TZ_NTP_WorldClock_STM32_Ethernet)
  * [Generic Boards with WiFiNINA ](#generic-boards-with-wifinina)
    * [11. RTC_WiFiNINA](examples/WiFiNINA/RTC_WiFiNINA)
    * [12. TZ_NTP_Clock_WiFiNINA](examples/WiFiNINA/TZ_NTP_Clock_WiFiNINA)
    * [13. TZ_NTP_WorldClock_WiFiNINA](examples/WiFiNINA/TZ_NTP_WorldClock_WiFiNINA)
* [Example TZ_NTP_Clock_Ethernet](#example-tz_ntp_clock_ethernet)
  * [1. File TZ_NTP_Clock_Ethernet.ino](#1-file-tz_ntp_clock_ethernetino)
  * [2. File defines.h](#2-file-definesh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [ 1. TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with ENC28J60](#1-tz_ntp_worldclock_ethernet-on-nrf52840_feather-with-enc28j60)
  * [ 2. TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with W5500](#2-tz_ntp_worldclock_ethernet-on-nrf52840_feather-with-w5500)
  * [ 3. TZ_NTP_WorldClock_WiFiNINA on SAMD_NANO_33_IOT with WiFiNINA](#3-tz_ntp_worldclock_wifinina-on-samd_nano_33_iot-with-wifinina)
  * [ 4. RTC_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with W5500](#4-rtc_stm32_ethernet-on-stm32f7-nucleo-144-nucleo_f767zi-with-w5500)
  * [ 5. RTC_Ethernet on Arduino SAM DUE with W5100](#5-rtc_ethernet-on-arduino-sam-due-with-w5100)
  * [ 6. RTC_Ethernet on Adafruit NRF52840_FEATHER with W5500](#6-rtc_ethernet-on-adafruit-nrf52840_feather-with-w5500)
  * [ 7. tzTest on Adafruit NRF52840_FEATHER](#7-tztest-on-adafruit-nrf52840_feather)
  * [ 8. WriteRules on Adafruit NRF52840_FEATHER using LittleFS](#8-writerules-on-adafruit-nrf52840_feather-using-littlefs)
  * [ 9. WriteRules on SAMD_NANO_33_IOT using FlashStorage_SAMD](#9-writerules-on-samd_nano_33_iot-using-flashstorage_samd)
  * [10. WriteRules on STM32F7 Nucleo-144 NUCLEO_F767ZI using EEPROM](#10-writerules-on-stm32f7-nucleo-144-nucleo_f767zi-using-eeprom)
  * [11. WriteRules on Arduino SAM DUE using dueFlashStorage](#11-writerules-on-arduino-sam-due-using-dueflashstorage)
  * [12. WriteRules on ESP32_DEV using new ESP32 LittleFS](#12-writerules-on-esp32_dev-using-new-esp32-littlefs)
  * [13. WriteRules on ESP8266_NODEMCU using LittleFS](#13-writerules-on-esp8266_nodemcu-using-littlefs)
  * [14. BI_RTC_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A](#14-bi_rtc_stm32_ethernet-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a)
  * [15. BI_RTC_Alarm_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A](#15-bi_rtc_alarm_stm32_ethernet-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a)
  * [16. TZ_NTP_WorldClock_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA](#16-tz_ntp_worldclock_wifinina-on-mbed-nano_rp2040_connect-with-wifinina)
  * [17. TZ_NTP_WorldClock_Ethernet on MBED RASPBERRY_PI_PICO with W5x00](#17-tz_ntp_worldclock_ethernet-on-mbed-raspberry_pi_pico-with-w5x00)
  * [18. TZ_NTP_WorldClock_Ethernet on RASPBERRY_PI_PICO with W5x00](#18-tz_ntp_worldclock_ethernet-on-raspberry_pi_pico-with-w5x00)
* [Releases](#releases)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [Timezone_Generic library](https://github.com/khoih-prog/Timezone_Generic)

### Features

The [**Timezone_Generic library**](https://github.com/khoih-prog/Timezone_Generic) is designed to work in conjunction with the [**Arduino Time library**](https://github.com/PaulStoffregen/Time), which must also be installed on your system. This documentation assumes some familiarity with the Time library.

The primary goal of the [**Timezone_Generic library**](https://github.com/khoih-prog/Timezone_Generic) is to convert Universal Coordinated Time (UTC) to the correct local time, whether it is Daylight Saving Time (a.k.a. summer time, DST) or standard time. The time source could be a GPS receiver, an **NTP server**, or a **Real-Time Clock (RTC)** set to UTC.  But whether a hardware RTC or other time source is even present is immaterial, since the Time library can function as a software RTC without additional hardware (although its accuracy is dependent on the accuracy of the microcontroller's system clock.)

The [**Timezone_Generic library**](https://github.com/khoih-prog/Timezone_Generic) implements two objects to facilitate time zone conversions:

- A **TimeChangeRule** object describes when local time changes to daylight (summer) time, or to standard time, for a particular locale.

- A **Timezone** object uses **TimeChangeRule**s to perform conversions and related functions. It can also write its **TimeChangeRule**s to or read them from EEPROM/DueFlashStorage/FlashStorage/LittleFS/SPIFFS. Multiple time zones can be represented by defining multiple **Timezone** objects.

The examples will demonstrate how to get the UTC time from NTP server, then update the DS3231 RTC to make sure the time is perfectly correct.
You can also modify the examples to read the NTP and update RTC once per every pre-determined period to ensure the RTC accuracy.

This [**Timezone_Generic library**](https://github.com/khoih-prog/Timezone_Generic) is based on and modified from [**Jack Christensen's Timezone Library**](https://github.com/JChristensen/Timezone) to add functions and support to many boards and shields.

---

### Currently Supported Boards

  - **ESP8266**.
  - **ESP32**.
  - **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox etc.**.
  - **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**.
  - **Adafruit SAM21 (Itsy-Bitsy M0, Metro M0, Feather M0, Gemma M0, etc.)**.
  - **Adafruit SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
  - **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
  - **STM32 (Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32F1, STM32F3, STM32F4, STM32H7, STM32L0, etc.)**.
  - **STM32F/L/H/G/WB/MP1 (Nucleo-64 L053R8,Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32Fx, STM32H7, STM32Lx, STM32Gx, STM32WB, STM32MP1, etc.) having 64K+ Flash program memory.**
  - **Arduino AVR boards (UNO, Nano, Mega, etc.)**
  - **Arduino MegaAVR boards (UNO WiFi Rev 2, Nano Every, etc.)**
  - RP2040-based boards, such as **Nano_RP2040_Connect**, using [**Arduino mbed OS for Nano boards**](https://github.com/arduino/ArduinoCore-mbed).
  - RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).
  
### Currently Supported WiFi Modules and Shields

  - **ESP8266 built-in WiFi**.
  - **ESP32 built-in WiFi**.
  - **WiFiNINA using WiFiNINA or WiFiNINA_Generic library**.
  - **ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or [ESP8266_AT_WebServer](https://github.com/khoih-prog/ESP8266_AT_WebServer) library**.
  
### Currently Supported Ethernet Modules and Shields

  - **W5x00's using Ethernet, EthernetLarge, Ethernet2 or Ethernet3 Library.**
  - **ENC28J60 using EthernetENC or UIPEthernet library.**
  - **LAN8742A using STM32Ethernet / STM32 LwIP libraries.**

### Currently Supported Storage

  - **ESP8266 LittleFS, SPIFFS**.
  - **ESP32 SPIFFS and LittleFS**.
  - **SAM DUE DueFlashStorage**.
  - **SAMD FlashStorage_SAMD**.
  - **nRF52/RP2040 LittleFS**.
  - **STM32, Teensy and AVR, MegaAVR EEPROM**.

---
---

## Changelog

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

---
---

## Prerequisites

 1. [`Arduino IDE v1.8.15+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Arduino AVR core 1.8.3+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) for AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest)
 3. [`Arduino MegaAVR core v1.8.3+`](https://github.com/arduino/ArduinoCore-megaavr) for Arduino MegaAVR boards such as Arduino Uno WiFi Rev2. Use Arduino Board Manager to install. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-megaavr.svg)](https://github.com/arduino/ArduinoCore-megaavr/releases/latest)
 4. [`ESP32 Core 1.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 5. [`ESP8266 Core 3.0.0+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS. 
 6. [`Teensy core v1.53+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. **Ready** from v1.0.0.
 7. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 8. [`Arduino SAMD core 1.8.11+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 9. [`Adafruit SAMD core 1.7.2+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
10. [`Seeeduino SAMD core 1.8.1+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)

11. [`Adafruit nRF52 v0.21.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)

  **Warnings** : Use [`Adafruit nRF52 v0.22.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/tag/0.22.0) will create **compiler errors** to some boards. If so, please use the [`Adafruit nRF52 v0.21.0`](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/tag/0.21.0) until the issue fixed.
  
12. [`Arduino Core for STM32 v2.0.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)
13. [`Arduino mbed_rp2040 core 2.1.0+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino RP2040-based boards, such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
14. [`Earle Philhower's arduino-pico core v1.7.0+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)

15. [`Time v1.6+`](https://github.com/PaulStoffregen/Time). [![GitHub release](https://img.shields.io/github/release/PaulStoffregen/Time.svg)](https://github.com/PaulStoffregen/Time/releases/latest). For PIO [`Time library`](https://platformio.org/lib/show/44/Time)
16. Depending on which board you're using:
   - [`DueFlashStorage library v1.0.0+`](https://github.com/sebnil/DueFlashStorage) for SAM DUE. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DueFlashStorage.svg?)](https://www.ardu-badge.com/DueFlashStorage)
   - [`FlashStorage_SAMD library v1.1.0+`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD21 and SAMD51 boards (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit Itsy-Bitsy M4, etc.). [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_SAMD.svg)](https://github.com/khoih-prog/FlashStorage_SAMD/releases/latest)
   - [`FlashStorage_STM32 library v1.1.0+`](https://github.com/khoih-prog/FlashStorage_STM32) for STM32F/L/H/G/WB/MP1 boards. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/FlashStorage_STM32.svg?)](https://www.ardu-badge.com/FlashStorage_STM32)
   - [`LittleFS_esp32 v1.0.6+`](https://github.com/lorol/LITTLEFS) for ESP32-based boards using LittleFS. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_esp32.svg?)](https://www.ardu-badge.com/LittleFS_esp32). **Notice**: This [`LittleFS_esp32 library`](https://github.com/lorol/LITTLEFS) has been integrated to Arduino [esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/tree/master/libraries/LITTLEFS).

17. Depending on which Ethernet card/module/shield you're using:
   - [`Ethernet library v2.0.0+`](https://github.com/arduino-libraries/Ethernet) for W5100, W5200 and W5500.  [![GitHub release](https://img.shields.io/github/release/arduino-libraries/Ethernet.svg)](https://github.com/arduino-libraries/Ethernet/releases/latest)
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500. [![GitHub release](https://img.shields.io/github/release/adafruit/Ethernet2.svg)](https://github.com/adafruit/Ethernet2/releases/latest)
   - [`Ethernet3 library v1.5.5+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip. [![GitHub release](https://img.shields.io/github/release/sstaub/Ethernet3.svg)](https://github.com/sstaub/Ethernet3/releases/latest)
   - [`EthernetENC library v2.0.1+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.10+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest)
   - [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32Ethernet.svg)](https://github.com/stm32duino/STM32Ethernet/releases/latest). To be used with [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP). [![GitHub release](https://img.shields.io/github/release/stm32duino/LwIP.svg)](https://github.com/stm32duino/LwIP/releases/latest). 
18. [`WiFiNINA_Generic library v1.8.10-1+`](https://github.com/khoih-prog/WiFiNINA_Generic) to use WiFiNINA modules/shields. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic) if using WiFiNINA for boards such as Nano 33 IoT, nRF52, Teensy, etc.
19. [`WiFiWebServer library v1.2.0+`](https://github.com/khoih-prog/WiFiWebServer) to use WiFi/WiFiNINA modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
20. [`EthernetWebServer library v1.5.0+`](https://github.com/khoih-prog/EthernetWebServer) to use Ethernet modules/shields on boards other than STM32F/L/H/G/WB/MP1. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer).
21. [`EthernetWebServer_STM32 library v1.2.0+`](https://github.com/khoih-prog/EthernetWebServer_STM32) to use Ethernet modules/shields on STM32F/L/H/G/WB/MP1 boards. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32).
22. [`ESP8266_AT_WebServer library v1.3.0+`](https://github.com/khoih-prog/ESP8266_AT_WebServer) to use ESP8266-AT/ESP32-AT WiFi modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP8266_AT_WebServer.svg?)](https://www.ardu-badge.com/ESP8266_AT_WebServer)
23. [`DS323x_Generic library v1.1.0+`](https://github.com/khoih-prog/DS323x_Generic) to use examples using DS323x RTC modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DS323x_Generic.svg?)](https://www.ardu-badge.com/DS323x_Generic)
24. [`STM32RTC library v1.1.0+`](https://github.com/stm32duino/STM32RTC) to use STM32 examples using built-in STM32 RTC. [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32RTC.svg)](https://github.com/stm32duino/STM32RTC/releases/latest).

---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**Timezone_Generic**](https://github.com/khoih-prog/Timezone_Generic), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/Timezone_Generic.svg?)](https://www.ardu-badge.com/Timezone_Generic) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**Timezone_Generic**](https://github.com/khoih-prog/Timezone_Generic) page.
2. Download the latest release `Timezone_Generic-master.zip`.
3. Extract the zip file to `Timezone_Generic-master` directory 
4. Copy whole `Timezone_Generic-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**Timezone_Generic** library](https://platformio.org/lib/show/11329/Timezone_Generic) by using [Library Manager](https://platformio.org/lib/show/11329/Timezone_Generic/installation). Search for **Timezone_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**Don't use v0.22.0+ yet because of compiler error. To be fixed.**

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 0.21.0](Packages_Patches/adafruit/hardware/nrf52/0.21.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0). 

Supposing the Adafruit nRF52 version is 0.21.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.13/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.13. These files must be copied into the directory:

- `./arduino-1.8.13/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.13/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.13/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.13/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

#### 3. For Arduino SAM DUE boards
 
 **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

#### 4. For Arduino SAMD boards
 
 ***To be able to compile without error and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD cores 1.8.11](Packages_Patches/arduino/hardware/samd/1.8.11) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.11).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.11. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.11/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

#### 5. For Adafruit SAMD boards
 
 ***To be able to automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the file [Adafruit SAMD platform.txt](Packages_Patches/adafruit/hardware/samd/1.7.1) into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.1). 

Supposing the Adafruit SAMD core version is 1.7.1. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.1/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the file [Seeeduino SAMD platform.txt](Packages_Patches/Seeeduino/hardware/samd/1.8.1) into Adafruit samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.1). 

Supposing the Seeeduino SAMD core version is 1.8.1. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.1/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/1.9.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/1.9.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/1.9.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_L053R8/variant.h`

#### 8. For RP2040-based boards using [Earle Philhower arduino-pico core](https://github.com/earlephilhower/arduino-pico)

#### 8.1 To use BOARD_NAME

 **To be able to automatically detect and display BOARD_NAME on RP2040-based boards (RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, GENERIC_RP2040, etc) boards**, you have to copy the file [RP2040 platform.txt](Packages_Patches/rp2040/hardware/rp2040/1.4.0) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0). 

Supposing the rp2040 core version is 1.4.0. This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/platform.txt`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add -DBOARD_NAME="{build.board}" #136](https://github.com/earlephilhower/arduino-pico/pull/136).

#### 8.2 To avoid compile error relating to microsecondsToClockCycles

Some libraries, such as [Adafruit DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library), require the definition of microsecondsToClockCycles(). **To be able to compile and run on RP2040-based boards**, you have to copy the files in [**RP2040 Arduino.h**](Packages_Patches/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0).

Supposing the rp2040 core version is 1.4.0. This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/cores/rp2040/Arduino.h`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add defs for compatibility #142](https://github.com/earlephilhower/arduino-pico/pull/142).

---
---

### Libraries' Patches

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)


#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

#### 5. For Ethernet3 library

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

#### 7. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.13/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

#### 8. For fixing ESP8266 compile error

To fix `ESP8266 compile error` such as

```
error: 'class EthernetClass' has no member named 'init'
Ethernet.init (USE_THIS_SS_PIN);
```

just rename the following file in ./arduino-1.8.13/hardware/esp8266com/esp8266/libraries/Ethernet directory

- From `Ethernet.h` to `Ethernet_ESP8266.h`

---
---

### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using **xyz-Impl.h instead of standard xyz.cpp**, possibly creates certain `Multiple Definitions` Linker error in certain use cases. Although it's simple to just modify several lines of code, either in the library or in the application, the library is adding 2 more source directories

1. **scr_h** for new h-only files
2. **src_cpp** for standard h/cpp files

besides the standard **src** directory.

To use the **old standard cpp** way, locate this library' directory, then just 

1. **Delete the all the files in src directory.**
2. **Copy all the files in src_cpp directory into src.**
3. Close then reopen the application code in Arduino IDE, etc. to recompile from scratch.

To re-use the **new h-only** way, just 

1. **Delete the all the files in src directory.**
2. **Copy the files in src_h directory into src.**
3. Close then reopen the application code in Arduino IDE, etc. to recompile from scratch.

---
---

### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use ADC2 for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use ADC2 with WiFi/BlueTooth (BT/BLE).
- Use ADC1, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by ADC2 (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

---
---

## Usage

### TimeChangeRules struct

Normally these will be coded in pairs for a given time zone: One rule to describe when daylight (summer, DST) time starts, and one to describe when standard time starts.

As an example, here in the Eastern US time zone, Eastern Daylight Time (EDT) starts on the 2nd Sunday in March at 02:00 local time. Eastern Standard Time (EST) starts on the 1st Sunday in November at 02:00 local time.

Define a **TimeChangeRule** as follows:

`TimeChangeRule myRule = {abbrev, week, dow, month, hour, offset};`

Where:

**abbrev** is a character string abbreviation for the time zone; it must be no longer than five characters.

**week** is the week of the month that the rule starts.

**dow** is the day of the week that the rule starts.

**hour** is the hour in local time that the rule starts (0-23).

**offset** is the UTC offset _in minutes_ for the time zone being defined.

For convenience, the following symbolic names can be used:

**week:** First, Second, Third, Fourth, Last
**dow:** Sun, Mon, Tue, Wed, Thu, Fri, Sat
**month:** Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec

For the Eastern US time zone, the **TimeChangeRule**s could be defined as follows:

```c++
TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -240};  //UTC - 4 hours
TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -300};   //UTC - 5 hours
```

---

### Timezone class

There are several ways to define **Timezone** objects.

#### 1. Using initialzed Timezone

By first defining **TimeChangeRule**s and giving the daylight time rule and the standard time rule (assuming usEDT and usEST defined as above):

`Timezone usEastern(usEDT, usEST);`

or

```
Timezone *usEastern;

usEastern = new Timezone(usEDT, usEST);
```

For a time zone that does not change to daylight/summer time, pass a single rule to the constructor. For example:

`Timezone usAZ(usMST, usMST);`

By reading rules previously stored in **EEPROM/DueFlashStorage/FlashStorage/LittleFS/SPIFFS**. This reads both the daylight and standard time rules previously stored at EEPROM/DueFlashStorage/FlashStorage **address 0** or LittleFS/SPIFFS file `timezone.dat` **offset 0** :

`Timezone usPacific(0);`

Note that **TimeChangeRule**s require TZ_DATA_SIZE (12) bytes of storage each, so the pair of rules associated with a Timezone object requires 24 bytes total.  This could possibly change in future versions of the library.  The size of a **TimeChangeRule** can be checked with `TZ_DATA_SIZE` or `sizeof(TimeChangeRule)`.

#### 2. Using un-initialzed Timezone (from v1.2.6)

Just initialize the Timezone object without any TimeChangeRule.

```
#define USING_INITIALIZED_TZ      false   //true

#if USING_INITIALIZED_TZ
  // US Eastern Time Zone (New York, Detroit,Toronto)
  TimeChangeRule myDST = {"EDT", Second, Sun, Mar, 2, -240};    // Daylight time = UTC - 4 hours
  TimeChangeRule mySTD = {"EST", First,  Sun, Nov, 2, -300};    // Standard time = UTC - 5 hours
  Timezone *myTZ;
#else
  // Allow a "blank" TZ object pointer then use init() method to set the actual TZ.
  // Feature added by 6v6gt (https://forum.arduino.cc/index.php?topic=711259)
  Timezone *myTZ ;
  TimeChangeRule myDST;
  TimeChangeRule mySTD;
#endif
```

then in setup(), get the correct TimeChangeRule (from SAM DUE DueFlashStorage, SAMD FlashStorage, nRF52 LittleFS, STM32 and AVR EEPROM, etc. or from any input), and initialzed the Timezone.

```
#if (USING_INITIALIZED_TZ)

  myTZ = new Timezone(myDST, mySTD);

#else

  // Can read this info from EEPROM, storage, etc
  String tzName = "EDT/EST" ;

  // Time zone rules can be set as below or dynamically built, say through a configuration
  // interface, or fetched from eeprom, flash etc.

  if ( tzName == "EDT/EST" )
  {
    // America Eastern Time
    myDST = (TimeChangeRule) {
      "EDT",  Second, Sun, Mar, 2, -240
    };     // Daylight time = UTC - 4 hours
    mySTD = (TimeChangeRule) {
      "EST",  First,  Sun, Nov, 2, -300
    };     // Standard time = UTC - 5 hours
  }
  else if ( tzName == "CET/CEST" )
  {
    // central Europe
    myDST = (TimeChangeRule) {
      "CEST", Last, Sun, Mar, 2, 120
    };
    mySTD = (TimeChangeRule) {
      "CET",  Last, Sun, Oct, 3, 60
    };
  }

  else if ( tzName == "GMT/BST" )
  {
    // UK
    myDST = (TimeChangeRule) {
      "BST",  Last, Sun, Mar, 1, 60
    };
    mySTD = (TimeChangeRule) {
      "GMT",  Last, Sun, Oct, 2, 0
    };
  }

  myTZ = new Timezone();
  myTZ->init( myDST, mySTD );

#endif
```

---
---

### Timezone_Generic library methods

Note that the `time_t` data type is defined by the [Arduino Time library's](https://github.com/PaulStoffregen/Time) <TimeLib.h>. See the Time library documentation [here](https://playground.arduino.cc/Code/Time) and [here](https://www.pjrc.com/teensy/td_libs_Time.html) for additional details.

---

### time_t toLocal(time_t utc);

#### Description

Converts the given UTC time to local time, standard or daylight as appropriate.

#### Syntax

`myTZ.toLocal(utc);`

#### Parameters

**utc:** Universal Coordinated Time *(time_t)*

#### Returns 

Local time *(time_t)*

#### Example

```c++
time_t eastern, utc;
TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -240};  //UTC - 4 hours
TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -300};   //UTC - 5 hours
Timezone usEastern(usEDT, usEST);

utc = now();	//current time from the Time Library
eastern = usEastern.toLocal(utc);
```

---

### time_t toLocal(time_t utc, TimeChangeRule **tcr);

#### Description

As above, converts the given UTC time to local time, and also returns a pointer to the **TimeChangeRule** that was applied to do the conversion. This could then be used, for example, to include the time zone abbreviation as part of a time display.  The caller must take care not to alter the pointed **TimeChangeRule**, as this will then result in incorrect conversions.

#### Syntax

`myTZ.toLocal(utc, &tcr);`

#### Parameters

**utc:** Universal Coordinated Time *(time_t)*
**tcr:** Address of a pointer to a **TimeChangeRule** _(\*\*TimeChangeRule)_ 

#### Returns

Local time *(time_t)*
Pointer to pointer **TimeChangeRule**  _(\*\*TimeChangeRule)_

#### Example

```c++
time_t eastern, utc;
TimeChangeRule *tcr;
TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -240};  //UTC - 4 hours
TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -300};   //UTC - 5 hours
Timezone usEastern(usEDT, usEST);

utc = now();	//current time from the Time Library
eastern = usEastern.toLocal(utc, &tcr);

Serial.print("The time zone is: ");
Serial.println(tcr -> abbrev);
```

---

### bool utcIsDST(time_t utc);
### bool locIsDST(time_t local);

#### Description

These functions determine whether a given UTC time or a given local time is within the daylight saving (summer) time interval, and return true or false accordingly.

#### Syntax

`utcIsDST(utc);`
`locIsDST(local);`

#### Parameters

**utc:** Universal Coordinated Time *(time_t)*
**local:** Local Time *(time_t)*

#### Returns

true or false *(bool)*

#### Example

`if (usEastern.utcIsDST(utc)) { /*do something*/ }`

---

### void readRules(int address);
### void writeRules(int address);

#### Description

These functions read or write a **Timezone** object's two **TimeChangeRule**s from or to EEPROM.

#### Syntax

`myTZ.readRules(address);`
`myTZ.writeRules(address);`

#### Parameters

**address:** The beginning EEPROM address to write to or read from *(int)*

#### Returns

None.

#### Example

`usEastern.writeRules(0);  //write rules beginning at EEPROM address 0 or file offset 0`

---

### void setRules(TimeChangeRule dstStart, TimeChangeRule stdStart);

#### Description

This function reads or updates the daylight and standard time rules from RAM. Can be used to change TimeChangeRules dynamically while a sketch runs.

#### Syntax

`myTZ.setRules(dstStart, stdStart);`

#### Parameters

**dstStart:** A TimeChangeRule denoting the start of daylight saving (summer) time.
**stdStart:** A TimeChangeRule denoting the start of standard time.

#### Returns

None.

#### Example

```c++
TimeChangeRule EDT = {"EDT", Second, Sun, Mar, 2, -240};
TimeChangeRule EST = {"EST", First, Sun, Nov, 2, -300};
Timezone tz(EDT, EST);
...
tz.setRules(EDT, EST);

```

---

### time_t toUTC(time_t local);

#### Description

Converts the given local time to UTC time.

**WARNING:** This function is provided for completeness, but should seldom be needed and should be used sparingly and carefully.

Ambiguous situations occur after the Standard-to-DST and the DST-to-Standard time transitions. When changing to DST, there is one hour of local time that does not exist, since the clock moves forward one hour. Similarly, when changing to standard time, there is one hour of local time that occurs twice since the clock moves back one hour.

This function does not test whether it is passed an erroneous time value during the Local-to-DST transition that does not exist. If passed such a time, an incorrect UTC time value will be returned.

If passed a local time value during the DST-to-Local transition that occurs twice, it will be treated as the earlier time, i.e. the time that occurs before the transition.

Calling this function with local times during a transition interval should be avoided!

#### Syntax

`myTZ.toUTC(local);`

#### Parameters

**local:** Local Time *(time_t)*

#### Returns

UTC *(time_t)*

---

### TimeChangeRule* read_DST_Rule(void);
### TimeChangeRule* read_STD_Rule(void);

#### Description

Read the corresponding **TimeChangeRule**.

#### Syntax

`TimeChangeRule* myDSTptr = myTZ.read_DST_Rule();`
`TimeChangeRule* mySTDptr = myTZ.read_STD_Rule();`

#### Parameters

None

#### Returns

Pointer to **TimeChangeRule**  _(TimeChangeRule*)_

---

### void display_DST_Rule(void);
### void display_STD_Rule(void);

#### Description
Display the corresponding **TimeChangeRule**.

#### Syntax

`myTZ.display_DST_Rule();`
`myTZ.display_STD_Rule();`


#### Parameters

None

#### Returns

None

#### Example

```c++
#define TZ_DBG_PORT         Serial
#define _TZ_LOGLEVEL_       1

TimeChangeRule EDT = {"EDT", Second, Sun, Mar, 2, -240};
TimeChangeRule EST = {"EST", First, Sun, Nov, 2, -300};
Timezone tz(EDT, EST);
...
tz.display_DST_Rule();
tz.display_STD_Rule();

```

---
---

## Examples

### Generic Boards

 1. [tzTest](examples/tzTest)
 2. [WriteRules](examples/WriteRules)
 
### Generic Boards with Ethernet

 3. [RTC_Ethernet](examples/Ethernet/RTC_Ethernet) 
 4. [TZ_NTP_Clock_Ethernet](examples/Ethernet/TZ_NTP_Clock_Ethernet)
 5. [TZ_NTP_WorldClock_Ethernet](examples/Ethernet/TZ_NTP_WorldClock_Ethernet)
 
### STM32F/L/H/G/WB/MP1 Boards with Ethernet
 
 6. [BI_RTC_Alarm_STM32_Ethernet](examples/Ethernet/BI_RTC_Alarm_STM32_Ethernet)
 7. [BI_RTC_STM32_Ethernet](examples/Ethernet/BI_RTC_STM32_Ethernet)
 8. [RTC_STM32_Ethernet](examples/Ethernet/RTC_STM32_Ethernet)
 9. [TZ_NTP_Clock_STM32_Ethernet](examples/Ethernet/TZ_NTP_Clock_STM32_Ethernet)
10. [TZ_NTP_WorldClock_STM32_Ethernet](examples/Ethernet/TZ_NTP_WorldClock_STM32_Ethernet)
 
### Generic Boards with WiFiNINA 
 
11. [RTC_WiFiNINA](examples/WiFiNINA/RTC_WiFiNINA) 
12. [TZ_NTP_Clock_WiFiNINA](examples/WiFiNINA/TZ_NTP_Clock_WiFiNINA)
13. [TZ_NTP_WorldClock_WiFiNINA](examples/WiFiNINA/TZ_NTP_WorldClock_WiFiNINA)

---
---

### Example [TZ_NTP_Clock_Ethernet](examples/Ethernet/TZ_NTP_Clock_Ethernet)

#### 1. File [TZ_NTP_Clock_Ethernet.ino](examples/Ethernet/TZ_NTP_Clock_Ethernet/TZ_NTP_Clock_Ethernet.ino)

```cpp
/*
   The Arduino board communicates with the shield using the SPI bus. This is on digital pins 11, 12, and 13 on the Uno
   and pins 50, 51, and 52 on the Mega. On both boards, pin 10 is used as SS. On the Mega, the hardware SS pin, 53,
   is not used to select the Ethernet controller chip, but it must be kept as an output or the SPI interface won't work.
*/

#include "defines.h"

//////////////////////////////////////////

#include <Timezone_Generic.h>    // https://github.com/khoih-prog/Timezone_Generic

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

// If TimeChangeRules are already stored in EEPROM, comment out the three
// lines above and uncomment the line below.
//Timezone myTZ(100);       // assumes rules stored at EEPROM address 100

TimeChangeRule *tcr;        // pointer to the time change rule, use to get TZ abbrev

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

void displayClock(void)
{
  time_t utc = now();

  time_t local = myTZ->toLocal(utc, &tcr);
  
  Serial.println();
  printDateTime(utc, "UTC");
  printDateTime(local, tcr -> abbrev);
  delay(10000);
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

      // Get the time_t from epoch
      time_t epoch_t = epoch;

      // set the system time to UTC
      // warning: assumes that compileTime() returns US EDT
      // adjust the following line accordingly if you're in another time zone
      setTime(epoch_t);
      
      // print Unix time:
      Serial.println(epoch);

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

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  delay(200);

  Serial.print(F("\nStart TZ_NTP_Clock_Ethernet on ")); Serial.print(BOARD_NAME);
  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);
  Serial.println(TIMEZONE_GENERIC_VERSION);

#if USE_ETHERNET_WRAPPER

  EthernetInit();

#else

#if USE_ETHERNET
  ET_LOGWARN(F("=========== USE_ETHERNET ==========="));
#elif USE_ETHERNET2
  ET_LOGWARN(F("=========== USE_ETHERNET2 ==========="));
#elif USE_ETHERNET3
  ET_LOGWARN(F("=========== USE_ETHERNET3 ==========="));
#elif USE_ETHERNET_LARGE
  ET_LOGWARN(F("=========== USE_ETHERNET_LARGE ==========="));
#elif USE_ETHERNET_ESP8266
  ET_LOGWARN(F("=========== USE_ETHERNET_ESP8266 ==========="));
#else
  ET_LOGWARN(F("========================="));
#endif

  ET_LOGWARN(F("Default SPI pinout:"));
  ET_LOGWARN1(F("MOSI:"), MOSI);
  ET_LOGWARN1(F("MISO:"), MISO);
  ET_LOGWARN1(F("SCK:"),  SCK);
  ET_LOGWARN1(F("SS:"),   SS);
  ET_LOGWARN(F("========================="));

#if defined(ESP8266)
  // For ESP8266, change for other boards if necessary
  #ifndef USE_THIS_SS_PIN
    #define USE_THIS_SS_PIN   D2    // For ESP8266
  #endif

  ET_LOGWARN1(F("ESP8266 setCsPin:"), USE_THIS_SS_PIN);

  #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )
    // For ESP8266
    // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
    // Ethernet           0                 X            X            X            X        0
    // Ethernet2          X                 X            X            X            X        0
    // Ethernet3          X                 X            X            X            X        0
    // EthernetLarge      X                 X            X            X            X        0
    // Ethernet_ESP8266   0                 0            0            0            0        0
    // D2 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
    // Must use library patch for Ethernet, EthernetLarge libraries
    Ethernet.init (USE_THIS_SS_PIN);

  #elif USE_ETHERNET3
    // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
    #ifndef ETHERNET3_MAX_SOCK_NUM
      #define ETHERNET3_MAX_SOCK_NUM      4
    #endif
  
    Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

  #elif USE_CUSTOM_ETHERNET
  
    // You have to add initialization for your Custom Ethernet here
    // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
    Ethernet.init(USE_THIS_SS_PIN);
  
  #endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )

#elif defined(ESP32)

  // You can use Ethernet.init(pin) to configure the CS pin
  //Ethernet.init(10);  // Most Arduino shields
  //Ethernet.init(5);   // MKR ETH shield
  //Ethernet.init(0);   // Teensy 2.0
  //Ethernet.init(20);  // Teensy++ 2.0
  //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
  //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

  #ifndef USE_THIS_SS_PIN
    #define USE_THIS_SS_PIN   22    // For ESP32
  #endif

  ET_LOGWARN1(F("ESP32 setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
  #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )
    // Must use library patch for Ethernet, EthernetLarge libraries
    // ESP32 => GPIO2,4,5,13,15,21,22 OK with Ethernet, Ethernet2, EthernetLarge
    // ESP32 => GPIO2,4,5,15,21,22 OK with Ethernet3
  
    //Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (USE_THIS_SS_PIN);
  
  #elif USE_ETHERNET3
    // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
    #ifndef ETHERNET3_MAX_SOCK_NUM
      #define ETHERNET3_MAX_SOCK_NUM      4
    #endif
  
    Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

  #elif USE_CUSTOM_ETHERNET
  
    // You have to add initialization for your Custom Ethernet here
    // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
    Ethernet.init(USE_THIS_SS_PIN); 
  
  #endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )

#elif ETHERNET_USE_RPIPICO

  pinMode(USE_THIS_SS_PIN, OUTPUT);
  digitalWrite(USE_THIS_SS_PIN, HIGH);
  
  // ETHERNET_USE_RPIPICO, use default SS = 5 or 17
  #ifndef USE_THIS_SS_PIN
    #if defined(ARDUINO_ARCH_MBED)
      #define USE_THIS_SS_PIN   5     // For Arduino Mbed core
    #else  
      #define USE_THIS_SS_PIN   17    // For E.Philhower core
    #endif
  #endif

  ET_LOGWARN1(F("RPIPICO setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
  #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )
    // Must use library patch for Ethernet, EthernetLarge libraries
    // For RPI Pico using Arduino Mbed RP2040 core
    // SCK: GPIO2,  MOSI: GPIO3, MISO: GPIO4, SS/CS: GPIO5
    // For RPI Pico using E. Philhower RP2040 core
    // SCK: GPIO18,  MOSI: GPIO19, MISO: GPIO16, SS/CS: GPIO17
    // Default pin 5/17 to SS/CS
  
    //Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (USE_THIS_SS_PIN);
  
  #elif USE_ETHERNET3
    // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
    #ifndef ETHERNET3_MAX_SOCK_NUM
      #define ETHERNET3_MAX_SOCK_NUM      4
    #endif
  
    Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
    
  #endif    //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )
  
#else   //defined(ESP8266)
  // unknown board, do nothing, use default SS = 10
  #ifndef USE_THIS_SS_PIN
    #define USE_THIS_SS_PIN   10    // For other boards
  #endif

  ET_LOGWARN3(F("Board :"), BOARD_NAME, F(", setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
  #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2  || USE_ETHERNET_ENC )
    // Must use library patch for Ethernet, Ethernet2, EthernetLarge libraries
  
    Ethernet.init (USE_THIS_SS_PIN);
  
  #elif USE_ETHERNET3
    // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
    #ifndef ETHERNET3_MAX_SOCK_NUM
      #define ETHERNET3_MAX_SOCK_NUM      4
    #endif
  
    Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

  #elif USE_CUSTOM_ETHERNET
  
    // You have to add initialization for your Custom Ethernet here
    // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
    Ethernet.init(USE_THIS_SS_PIN);
    
  #endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )

#endif    //defined(ESP8266)


#endif  //USE_ETHERNET_WRAPPER


  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  // Just info to know how to connect correctly
  Serial.println(F("========================="));
  Serial.println(F("Currently Used SPI pinout:"));
  Serial.print(F("MOSI:"));
  Serial.println(MOSI);
  Serial.print(F("MISO:"));
  Serial.println(MISO);
  Serial.print(F("SCK:"));
  Serial.println(SCK);
  Serial.print(F("SS:"));
  Serial.println(SS);
#if USE_ETHERNET3
  Serial.print(F("SPI_CS:"));
  Serial.println(SPI_CS);
#endif
  Serial.println(F("========================="));

  Serial.print(F("Using mac index = "));
  Serial.println(index);

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(Ethernet.localIP());

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

  myTZ = new Timezone();
  myTZ->init( myDST, mySTD );
  
#endif

  Udp.begin(localPort);
}

void loop()
{
  getNTPTime();
  displayClock();
}
```

---

#### 2. File [defines.h](examples/Ethernet/TZ_NTP_Clock_Ethernet/defines.h)

```cpp
#ifndef defines_h
#define defines_h

#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial
#define TZ_DBG_PORT                         Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       3
#define _TZ_LOGLEVEL_                       1

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )
#if defined(ETHERNET_USE_SAMD)
#undef ETHERNET_USE_SAMD
#endif
#define ETHERNET_USE_SAMD      true
#endif

#if ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
        defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
        defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )
#if defined(ETHERNET_USE_NRF528XX)
#undef ETHERNET_USE_NRF528XX
#endif
#define ETHERNET_USE_NRF528XX      true
#endif

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
#if defined(ETHERNET_USE_SAM_DUE)
#undef ETHERNET_USE_SAM_DUE
#endif
#define ETHERNET_USE_SAM_DUE      true
#endif

#if ( defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) || defined(ARDUINO_GENERIC_RP2040) )
  #if defined(ETHERNET_USE_RPIPICO)
    #undef ETHERNET_USE_RPIPICO
  #endif
  #define ETHERNET_USE_RPIPICO      true
#endif

#if defined(ETHERNET_USE_SAMD)
// For SAMD
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

#if ( defined(ARDUINO_SAMD_ZERO) && !defined(SEEED_XIAO_M0) )
#define BOARD_TYPE      "SAMD Zero"
#elif defined(ARDUINO_SAMD_MKR1000)
#define BOARD_TYPE      "SAMD MKR1000"
#elif defined(ARDUINO_SAMD_MKRWIFI1010)
#define BOARD_TYPE      "SAMD MKRWIFI1010"
#elif defined(ARDUINO_SAMD_NANO_33_IOT)
#define BOARD_TYPE      "SAMD NANO_33_IOT"
#elif defined(ARDUINO_SAMD_MKRFox1200)
#define BOARD_TYPE      "SAMD MKRFox1200"
#elif ( defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) )
#define BOARD_TYPE      "SAMD MKRWAN13X0"
#elif defined(ARDUINO_SAMD_MKRGSM1400)
#define BOARD_TYPE      "SAMD MKRGSM1400"
#elif defined(ARDUINO_SAMD_MKRNB1500)
#define BOARD_TYPE      "SAMD MKRNB1500"
#elif defined(ARDUINO_SAMD_MKRVIDOR4000)
#define BOARD_TYPE      "SAMD MKRVIDOR4000"
#elif defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#define BOARD_TYPE      "SAMD ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS"
#elif defined(ADAFRUIT_FEATHER_M0_EXPRESS)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_FEATHER_M0_EXPRESS"
#elif defined(ADAFRUIT_METRO_M0_EXPRESS)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_METRO_M0_EXPRESS"
#elif defined(ADAFRUIT_CIRCUITPLAYGROUND_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_CIRCUITPLAYGROUND_M0"
#elif defined(ADAFRUIT_GEMMA_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_GEMMA_M0"
#elif defined(ADAFRUIT_TRINKET_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_TRINKET_M0"
#elif defined(ADAFRUIT_ITSYBITSY_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_ITSYBITSY_M0"
#elif defined(ARDUINO_SAMD_HALLOWING_M0)
#define BOARD_TYPE      "SAMD21 ARDUINO_SAMD_HALLOWING_M0"
#elif defined(ADAFRUIT_METRO_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_EXPRESS"
#elif defined(ADAFRUIT_GRAND_CENTRAL_M4)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_GRAND_CENTRAL_M4"
#elif defined(ADAFRUIT_FEATHER_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_FEATHER_M4_EXPRESS"
#elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_ITSYBITSY_M4_EXPRESS"
#define USE_THIS_SS_PIN       10
#elif defined(ADAFRUIT_TRELLIS_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_TRELLIS_M4_EXPRESS"
#elif defined(ADAFRUIT_PYPORTAL)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL"
#elif defined(ADAFRUIT_PYPORTAL_M4_TITANO)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL_M4_TITANO"
#elif defined(ADAFRUIT_PYBADGE_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_M4_EXPRESS"
#elif defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_AIRLIFT_LITE"
#elif defined(ADAFRUIT_PYGAMER_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_M4_EXPRESS"
#elif defined(ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS"
#elif defined(ADAFRUIT_PYBADGE_AIRLIFT_M4)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_AIRLIFT_M4"
#elif defined(ADAFRUIT_MONSTER_M4SK_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_MONSTER_M4SK_EXPRESS"
#elif defined(ADAFRUIT_HALLOWING_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_HALLOWING_M4_EXPRESS"
#elif defined(SEEED_WIO_TERMINAL)
#define BOARD_TYPE      "SAMD SEEED_WIO_TERMINAL"
#elif defined(SEEED_FEMTO_M0)
#define BOARD_TYPE      "SAMD SEEED_FEMTO_M0"
#elif defined(SEEED_XIAO_M0)
#define BOARD_TYPE      "SAMD SEEED_XIAO_M0"
#ifdef USE_THIS_SS_PIN
#undef USE_THIS_SS_PIN
#endif
#define USE_THIS_SS_PIN       A1
#warning define SEEED_XIAO_M0 USE_THIS_SS_PIN == A1
#elif defined(Wio_Lite_MG126)
#define BOARD_TYPE      "SAMD SEEED Wio_Lite_MG126"
#elif defined(WIO_GPS_BOARD)
#define BOARD_TYPE      "SAMD SEEED WIO_GPS_BOARD"
#elif defined(SEEEDUINO_ZERO)
#define BOARD_TYPE      "SAMD SEEEDUINO_ZERO"
#elif defined(SEEEDUINO_LORAWAN)
#define BOARD_TYPE      "SAMD SEEEDUINO_LORAWAN"
#elif defined(SEEED_GROVE_UI_WIRELESS)
#define BOARD_TYPE      "SAMD SEEED_GROVE_UI_WIRELESS"
#elif defined(__SAMD21E18A__)
#define BOARD_TYPE      "SAMD21E18A"
#elif defined(__SAMD21G18A__)
#define BOARD_TYPE      "SAMD21G18A"
#elif defined(__SAMD51G19A__)
#define BOARD_TYPE      "SAMD51G19A"
#elif defined(__SAMD51J19A__)
#define BOARD_TYPE      "SAMD51J19A"
#elif defined(__SAMD51J20A__)
#define BOARD_TYPE      "SAMD51J20A"
#elif defined(__SAM3X8E__)
#define BOARD_TYPE      "SAM3X8E"
#elif defined(__CPU_ARC__)
#define BOARD_TYPE      "CPU_ARC"
#elif defined(__SAMD51__)
#define BOARD_TYPE      "SAMD51"
#else
#define BOARD_TYPE      "SAMD Unknown"
#endif

#elif (ETHERNET_USE_SAM_DUE)
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10
#define BOARD_TYPE      "SAM DUE"

#elif (ETHERNET_USE_NRF528XX)
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

#if defined(NRF52840_FEATHER)
#define BOARD_TYPE      "NRF52840_FEATHER"
#elif defined(NRF52832_FEATHER)
#define BOARD_TYPE      "NRF52832_FEATHER"
#elif defined(NRF52840_FEATHER_SENSE)
#define BOARD_TYPE      "NRF52840_FEATHER_SENSE"
#elif defined(NRF52840_ITSYBITSY)
#define BOARD_TYPE      "NRF52840_ITSYBITSY"
#define USE_THIS_SS_PIN   10    // For other boards
#elif defined(NRF52840_CIRCUITPLAY)
#define BOARD_TYPE      "NRF52840_CIRCUITPLAY"
#elif defined(NRF52840_CLUE)
#define BOARD_TYPE      "NRF52840_CLUE"
#elif defined(NRF52840_METRO)
#define BOARD_TYPE      "NRF52840_METRO"
#elif defined(NRF52840_PCA10056)
#define BOARD_TYPE      "NRF52840_PCA10056"
#elif defined(NINA_B302_ublox)
#define BOARD_TYPE      "NINA_B302_ublox"
#elif defined(NINA_B112_ublox)
#define BOARD_TYPE      "NINA_B112_ublox"
#elif defined(PARTICLE_XENON)
#define BOARD_TYPE      "PARTICLE_XENON"
#elif defined(ARDUINO_NRF52_ADAFRUIT)
#define BOARD_TYPE      "ARDUINO_NRF52_ADAFRUIT"
#else
#define BOARD_TYPE      "nRF52 Unknown"
#endif

#elif ( defined(CORE_TEENSY) )
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

#if defined(__IMXRT1062__)
// For Teensy 4.1/4.0
#define BOARD_TYPE      "TEENSY 4.1/4.0"
#elif defined(__MK66FX1M0__)
#define BOARD_TYPE "Teensy 3.6"
#elif defined(__MK64FX512__)
#define BOARD_TYPE "Teensy 3.5"
#elif defined(__MKL26Z64__)
#define BOARD_TYPE "Teensy LC"
#elif defined(__MK20DX256__)
#define BOARD_TYPE "Teensy 3.2" // and Teensy 3.1 (obsolete)
#elif defined(__MK20DX128__)
#define BOARD_TYPE "Teensy 3.0"
#elif defined(__AVR_AT90USB1286__)
#error Teensy 2.0++ not supported yet
#elif defined(__AVR_ATmega32U4__)
#error Teensy 2.0 not supported yet
#else
// For Other Boards
#define BOARD_TYPE      "Unknown Teensy Board"
#endif

#elif ( defined(ESP8266) )
  // For ESP8266
  #warning Use ESP8266 architecture
  #include <ESP8266mDNS.h>
  #define ETHERNET_USE_ESP8266
  #define BOARD_TYPE      "ESP8266"
  
  #define USE_LITTLEFS      true
  #define USE_SPIFFS        false

#elif ( defined(ESP32) )
  // For ESP32
  #warning Use ESP32 architecture
  #define ETHERNET_USE_ESP32
  #define BOARD_TYPE      "ESP32"
  
  #define W5500_RST_PORT   21

  #define USE_LITTLEFS      true
  #define USE_SPIFFS        false 

#elif ETHERNET_USE_RPIPICO
  
  // Default pin 5 (in Mbed) or 17 to SS/CS
  #if defined(ARDUINO_ARCH_MBED)
    // For RPI Pico using Arduino Mbed RP2040 core
    // SCK: GPIO2,  MOSI: GPIO3, MISO: GPIO4, SS/CS: GPIO5
    
    #define USE_THIS_SS_PIN       5

    #if defined(BOARD_NAME)
      #undef BOARD_NAME
    #endif

    #if defined(ARDUINO_RASPBERRY_PI_PICO) 
      #define BOARD_TYPE      "MBED RASPBERRY_PI_PICO"
    #elif defined(ARDUINO_ADAFRUIT_FEATHER_RP2040)
      #define BOARD_TYPE      "MBED DAFRUIT_FEATHER_RP2040"
    #elif defined(ARDUINO_GENERIC_RP2040)
      #define BOARD_TYPE      "MBED GENERIC_RP2040"
    #else
      #define BOARD_TYPE      "MBED Unknown RP2040"
    #endif
    
  #else
    // For RPI Pico using E. Philhower RP2040 core
    // SCK: GPIO18,  MOSI: GPIO19, MISO: GPIO16, SS/CS: GPIO17
    #define USE_THIS_SS_PIN       17

  #endif
    
  #define SS_PIN_DEFAULT        USE_THIS_SS_PIN

  // For RPI Pico
  #warning Use RPI-Pico RP2040 architecture
  
#else
// For Mega
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10
#define BOARD_TYPE            "AVR Mega"
#endif

#ifndef BOARD_NAME
#define BOARD_NAME    BOARD_TYPE
#endif

#include <SPI.h>

//#define USE_ETHERNET_WRAPPER    true
#define USE_ETHERNET_WRAPPER    false

// Use true  for ENC28J60 and UIPEthernet library (https://github.com/UIPEthernet/UIPEthernet)
// Use false for W5x00 and Ethernetx library      (https://www.arduino.cc/en/Reference/Ethernet)

//#define USE_UIP_ETHERNET   true
#define USE_UIP_ETHERNET   false

//#define USE_CUSTOM_ETHERNET     true

// Note: To rename ESP628266 Ethernet lib files to Ethernet_ESP8266.h and Ethernet_ESP8266.cpp
// In order to USE_ETHERNET_ESP8266
#if ( !defined(USE_UIP_ETHERNET) || !USE_UIP_ETHERNET )

// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
// You can define here or customize for each board at same place with BOARD_TYPE
// Check @ defined(SEEED_XIAO_M0)
//#define USE_THIS_SS_PIN   22  //21  //5 //4 //2 //15

// Only one if the following to be true
#define USE_ETHERNET          false
#define USE_ETHERNET2         false
#define USE_ETHERNET3         false
#define USE_ETHERNET_LARGE    true
#define USE_ETHERNET_ESP8266  false
#define USE_ETHERNET_ENC      false
#define USE_CUSTOM_ETHERNET   false

#if !USE_ETHERNET_WRAPPER

#if ( USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC )
#ifdef USE_CUSTOM_ETHERNET
#undef USE_CUSTOM_ETHERNET
#endif
#define USE_CUSTOM_ETHERNET   false //true
#endif

#if USE_ETHERNET3
#include "Ethernet3.h"
#warning Using Ethernet3 lib
#define SHIELD_TYPE           "W5x00 using Ethernet3 Library"
#elif USE_ETHERNET2
#include "Ethernet2.h"
#warning Using Ethernet2 lib
#define SHIELD_TYPE           "W5x00 using Ethernet2 Library"
#elif USE_ETHERNET_LARGE
#include "EthernetLarge.h"
#warning Using EthernetLarge lib
#define SHIELD_TYPE           "W5x00 using EthernetLarge Library"
#elif USE_ETHERNET_ESP8266
#include "Ethernet_ESP8266.h"
#warning Using Ethernet_ESP8266 lib
#define SHIELD_TYPE           "W5x00 using Ethernet_ESP8266 Library"
#elif USE_ETHERNET_ENC
#include "EthernetENC.h"
#warning Using EthernetENC lib
#define SHIELD_TYPE           "ENC28J60 using EthernetENC Library"
#elif USE_CUSTOM_ETHERNET
//#include "Ethernet_XYZ.h"
#include "EthernetENC.h"
#warning Using Custom Ethernet library. You must include a library and initialize.
#define SHIELD_TYPE           "Custom Ethernet using Ethernet_XYZ Library"
#else
#define USE_ETHERNET          true
#include "Ethernet.h"
#warning Using Ethernet lib
#define SHIELD_TYPE           "W5x00 using Ethernet Library"
#endif

// Ethernet_Shield_W5200, EtherCard, EtherSia not supported
// Select just 1 of the following #include if uncomment #define USE_CUSTOM_ETHERNET
// Otherwise, standard Ethernet library will be used for W5x00

#endif    //  USE_ETHERNET_WRAPPER
#elif USE_UIP_ETHERNET
#include "UIPEthernet.h"
#warning Using UIPEthernet library
#define SHIELD_TYPE           "ENC28J60 using UIPEthernet Library"
#endif      // #if !USE_UIP_ETHERNET

#include <EthernetWebServer.h>

#ifndef SHIELD_TYPE
#define SHIELD_TYPE     "Unknown Ethernet shield/library"
#endif

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x14 },
};

// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 222);

#endif    //defines_h

```

---
---

### Debug Terminal Output Samples

### 1. TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with ENC28J60

The following is debug terminal output when running example [**TZ_NTP_WorldClock_Ethernet**](examples/Ethernet/TZ_NTP_WorldClock_Ethernet) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library

```
Start TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with ENC28J60 using EthernetENC Library
Timezone_Generic v1.4.0
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 25
[ETHERNET_WEBSERVER] MISO: 24
[ETHERNET_WEBSERVER] SCK: 26
[ETHERNET_WEBSERVER] SS: 5
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NRF52840_FEATHER , setCsPin: 10
=========================
Currently Used SPI pinout:
MOSI:25
MISO:24
SCK:26
SS:5
=========================
Using mac index = 9
You're connected to the network, IP = 192.168.2.89
Packet received
Seconds since Jan 1 1900 = 3811983610
Unix time = 1602994810
The UTC time is 4:20:10

15:20:10 Sun 18 Oct 2020 AEDT Sydney
07:20:10 Sun 18 Oct 2020 MSK  Moscow
06:20:10 Sun 18 Oct 2020 CEST Paris
05:20:10 Sun 18 Oct 2020 BST  London
04:20:10 Sun 18 Oct 2020 UTC  Universal Coordinated Time
00:20:10 Sun 18 Oct 2020 EDT  New York
23:20:10 Sat 17 Oct 2020 CDT  Chicago
22:20:10 Sat 17 Oct 2020 MDT  Denver
21:20:10 Sat 17 Oct 2020 MST  Phoenix
21:20:10 Sat 17 Oct 2020 PDT  Los Angeles

15:20:20 Sun 18 Oct 2020 AEDT Sydney
07:20:20 Sun 18 Oct 2020 MSK  Moscow
06:20:20 Sun 18 Oct 2020 CEST Paris
05:20:20 Sun 18 Oct 2020 BST  London
04:20:20 Sun 18 Oct 2020 UTC  Universal Coordinated Time
00:20:20 Sun 18 Oct 2020 EDT  New York
23:20:20 Sat 17 Oct 2020 CDT  Chicago
22:20:20 Sat 17 Oct 2020 MDT  Denver
21:20:20 Sat 17 Oct 2020 MST  Phoenix
21:20:20 Sat 17 Oct 2020 PDT  Los Angeles
```

---

### 2. TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with W5500

The following is debug terminal output when running example [**TZ_NTP_WorldClock_Ethernet**](examples/Ethernet/TZ_NTP_WorldClock_Ethernet) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using EthernetLarge Library

```
Start TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with W5x00 using EthernetLarge Library
Timezone_Generic v1.4.0
[ETHERNET_WEBSERVER] =========== USE_ETHERNET_LARGE ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 25
[ETHERNET_WEBSERVER] MISO: 24
[ETHERNET_WEBSERVER] SCK: 26
[ETHERNET_WEBSERVER] SS: 5
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NRF52840_FEATHER , setCsPin: 10
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:25
MISO:24
SCK:26
SS:5
=========================
Using mac index = 0
You're connected to the network, IP = 192.168.2.84
Packet received
Seconds since Jan 1 1900 = 3811984701
Unix time = 1602995901
The UTC time is 4:38:21

15:38:21 Sun 18 Oct 2020 AEDT Sydney
07:38:21 Sun 18 Oct 2020 MSK  Moscow
06:38:21 Sun 18 Oct 2020 CEST Paris
05:38:21 Sun 18 Oct 2020 BST  London
04:38:21 Sun 18 Oct 2020 UTC  Universal Coordinated Time
00:38:21 Sun 18 Oct 2020 EDT  New York
23:38:21 Sat 17 Oct 2020 CDT  Chicago
22:38:21 Sat 17 Oct 2020 MDT  Denver
21:38:21 Sat 17 Oct 2020 MST  Phoenix
21:38:21 Sat 17 Oct 2020 PDT  Los Angeles

15:38:31 Sun 18 Oct 2020 AEDT Sydney
07:38:31 Sun 18 Oct 2020 MSK  Moscow
06:38:31 Sun 18 Oct 2020 CEST Paris
05:38:31 Sun 18 Oct 2020 BST  London
04:38:31 Sun 18 Oct 2020 UTC  Universal Coordinated Time
00:38:31 Sun 18 Oct 2020 EDT  New York
23:38:31 Sat 17 Oct 2020 CDT  Chicago
22:38:31 Sat 17 Oct 2020 MDT  Denver
21:38:31 Sat 17 Oct 2020 MST  Phoenix
21:38:31 Sat 17 Oct 2020 PDT  Los Angeles
```

---

### 3. TZ_NTP_WorldClock_WiFiNINA on SAMD_NANO_33_IOT with WiFiNINA

The following is debug terminal output when running example [**TZ_NTP_WorldClock_WiFiNINA**](examples/WiFiNINA/TZ_NTP_WorldClock_WiFiNINA) on Arduino SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

```
Starting TZ_NTP_WorldClock_WiFiNINA on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
Timezone_Generic v1.4.0
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.128
Listening on port 2390
Packet received
Seconds since Jan 1 1900 = 3811983792
Unix time = 1602994992
The UTC time is 4:23:12

15:23:12 Sun 18 Oct 2020 AEDT Sydney
07:23:12 Sun 18 Oct 2020 MSK  Moscow
06:23:12 Sun 18 Oct 2020 CEST Paris
05:23:12 Sun 18 Oct 2020 BST  London
04:23:12 Sun 18 Oct 2020 UTC  Universal Coordinated Time
00:23:12 Sun 18 Oct 2020 EDT  New York
23:23:12 Sat 17 Oct 2020 CDT  Chicago
22:23:12 Sat 17 Oct 2020 MDT  Denver
21:23:12 Sat 17 Oct 2020 MST  Phoenix
21:23:12 Sat 17 Oct 2020 PDT  Los Angeles

15:23:22 Sun 18 Oct 2020 AEDT Sydney
07:23:22 Sun 18 Oct 2020 MSK  Moscow
06:23:22 Sun 18 Oct 2020 CEST Paris
05:23:22 Sun 18 Oct 2020 BST  London
04:23:22 Sun 18 Oct 2020 UTC  Universal Coordinated Time
00:23:22 Sun 18 Oct 2020 EDT  New York
23:23:22 Sat 17 Oct 2020 CDT  Chicago
22:23:22 Sat 17 Oct 2020 MDT  Denver
21:23:22 Sat 17 Oct 2020 MST  Phoenix
21:23:22 Sat 17 Oct 2020 PDT  Los Angeles
```

---

### 4. RTC_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with W5500

The following is debug terminal output when running example [**RTC_STM32_Ethernet**](examples/Ethernet/RTC_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with W5500 using Ethernet2 Library

```
Start RTC_STM32_Ethernet on NUCLEO_F767ZI, using W5x00 & Ethernet2 Library
Timezone_Generic v1.4.0
DS323x_Generic v1.1.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.117
Packet received
Seconds since Jan 1 1900 = 3812054437
Unix time = 1603065637
The UTC time is 0:00:37
============================
00:00:37 Mon 19 Oct 2020 UTC
20:00:37 Sun 18 Oct 2020 EDT
============================
00:00:46 Mon 19 Oct 2020 UTC
20:00:46 Sun 18 Oct 2020 EDT
```

---

### 5. RTC_Ethernet on Arduino SAM DUE with W5100

The following is debug terminal output when running example [**RTC_Ethernet**](examples/Ethernet/RTC_Ethernet) on Arduino SAM DUE with W5100 using EthernetLarge Library

```
Start RTC_Ethernet on SAM DUE with W5x00 using EthernetLarge Library
Timezone_Generic v1.4.0
DS323x_Generic v1.1.0
[ETHERNET_WEBSERVER] =========== USE_ETHERNET_LARGE ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 75
[ETHERNET_WEBSERVER] MISO: 74
[ETHERNET_WEBSERVER] SCK: 76
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : SAM DUE , setCsPin: 10
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096
=========================
Currently Used SPI pinout:
MOSI:75
MISO:74
SCK:76
SS:10
=========================
Using mac index = 5
You're connected to the network, IP = 192.168.2.108
============================
18:30:45 Sun 18 Oct 2020 UTC
14:30:45 Sun 18 Oct 2020 EDT
```

---

### 6. RTC_Ethernet on Adafruit NRF52840_FEATHER with W5500

The following is debug terminal output when running example [**RTC_Ethernet**](examples/Ethernet/RTC_Ethernet) on Adafruit NRF52840_FEATHER with W5500 using EthernetLarge Library

```
Start RTC_Ethernet on NRF52840_FEATHER with W5x00 using EthernetLarge Library
Timezone_Generic v1.4.0
DS323x_Generic v1.1.0
[ETHERNET_WEBSERVER] =========== USE_ETHERNET_LARGE ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 25
[ETHERNET_WEBSERVER] MISO: 24
[ETHERNET_WEBSERVER] SCK: 26
[ETHERNET_WEBSERVER] SS: 5
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NRF52840_FEATHER , setCsPin: 10
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:25
MISO:24
SCK:26
SS:5
=========================
Using mac index = 3
You're connected to the network, IP = 192.168.2.99
Packet received
Seconds since Jan 1 1900 = 3812052464
Unix time = 1603063664
The UTC time is 23:27:44
============================
23:27:44 Sun 18 Oct 2020 UTC
19:27:44 Sun 18 Oct 2020 EDT
============================
23:27:53 Sun 18 Oct 2020 UTC
19:27:53 Sun 18 Oct 2020 EDT
```

---

### 7. tzTest on Adafruit NRF52840_FEATHER

The following is debug terminal output when running example [**tzTest**](examples/tzTest) on NRF52840_FEATHER

```
Starting TZTest on NRF52840_FEATHER
Timezone_Generic v1.4.0
-------- Apr-2018 time change --------
13:59:57 Sat 31 Mar 2018 UTC = 02:59:57 Sun 01 Apr 2018 NZDT
13:59:58 Sat 31 Mar 2018 UTC = 02:59:58 Sun 01 Apr 2018 NZDT
13:59:59 Sat 31 Mar 2018 UTC = 02:59:59 Sun 01 Apr 2018 NZDT
14:00:00 Sat 31 Mar 2018 UTC = 02:00:00 Sun 01 Apr 2018 NZST
14:00:01 Sat 31 Mar 2018 UTC = 02:00:01 Sun 01 Apr 2018 NZST
14:00:02 Sat 31 Mar 2018 UTC = 02:00:02 Sun 01 Apr 2018 NZST

-------- Sep-2018 time change --------
13:59:57 Sat 29 Sep 2018 UTC = 01:59:57 Sun 30 Sep 2018 NZST
13:59:58 Sat 29 Sep 2018 UTC = 01:59:58 Sun 30 Sep 2018 NZST
13:59:59 Sat 29 Sep 2018 UTC = 01:59:59 Sun 30 Sep 2018 NZST
14:00:00 Sat 29 Sep 2018 UTC = 03:00:00 Sun 30 Sep 2018 NZDT
14:00:01 Sat 29 Sep 2018 UTC = 03:00:01 Sun 30 Sep 2018 NZDT
14:00:02 Sat 29 Sep 2018 UTC = 03:00:02 Sun 30 Sep 2018 NZDT

-------- Apr-2019 time change --------
13:59:57 Sat 06 Apr 2019 UTC = 02:59:57 Sun 07 Apr 2019 NZDT
13:59:58 Sat 06 Apr 2019 UTC = 02:59:58 Sun 07 Apr 2019 NZDT
13:59:59 Sat 06 Apr 2019 UTC = 02:59:59 Sun 07 Apr 2019 NZDT
14:00:00 Sat 06 Apr 2019 UTC = 02:00:00 Sun 07 Apr 2019 NZST
14:00:01 Sat 06 Apr 2019 UTC = 02:00:01 Sun 07 Apr 2019 NZST
14:00:02 Sat 06 Apr 2019 UTC = 02:00:02 Sun 07 Apr 2019 NZST

-------- Sep-2019 time change --------
13:59:57 Sat 28 Sep 2019 UTC = 01:59:57 Sun 29 Sep 2019 NZST
13:59:58 Sat 28 Sep 2019 UTC = 01:59:58 Sun 29 Sep 2019 NZST
13:59:59 Sat 28 Sep 2019 UTC = 01:59:59 Sun 29 Sep 2019 NZST
14:00:00 Sat 28 Sep 2019 UTC = 03:00:00 Sun 29 Sep 2019 NZDT
14:00:01 Sat 28 Sep 2019 UTC = 03:00:01 Sun 29 Sep 2019 NZDT
14:00:02 Sat 28 Sep 2019 UTC = 03:00:02 Sun 29 Sep 2019 NZDT

-------- Apr-2020 time change --------
13:59:57 Sat 04 Apr 2020 UTC = 02:59:57 Sun 05 Apr 2020 NZDT
13:59:58 Sat 04 Apr 2020 UTC = 02:59:58 Sun 05 Apr 2020 NZDT
13:59:59 Sat 04 Apr 2020 UTC = 02:59:59 Sun 05 Apr 2020 NZDT
14:00:00 Sat 04 Apr 2020 UTC = 02:00:00 Sun 05 Apr 2020 NZST
14:00:01 Sat 04 Apr 2020 UTC = 02:00:01 Sun 05 Apr 2020 NZST
14:00:02 Sat 04 Apr 2020 UTC = 02:00:02 Sun 05 Apr 2020 NZST

-------- Sep-2020 time change --------
13:59:57 Sat 26 Sep 2020 UTC = 01:59:57 Sun 27 Sep 2020 NZST
13:59:58 Sat 26 Sep 2020 UTC = 01:59:58 Sun 27 Sep 2020 NZST
13:59:59 Sat 26 Sep 2020 UTC = 01:59:59 Sun 27 Sep 2020 NZST
14:00:00 Sat 26 Sep 2020 UTC = 03:00:00 Sun 27 Sep 2020 NZDT
14:00:01 Sat 26 Sep 2020 UTC = 03:00:01 Sun 27 Sep 2020 NZDT
14:00:02 Sat 26 Sep 2020 UTC = 03:00:02 Sun 27 Sep 2020 NZDT

-------- Mar-2018 time change --------
06:59:57 Sun 11 Mar 2018 UTC = 01:59:57 Sun 11 Mar 2018 EST
06:59:58 Sun 11 Mar 2018 UTC = 01:59:58 Sun 11 Mar 2018 EST
06:59:59 Sun 11 Mar 2018 UTC = 01:59:59 Sun 11 Mar 2018 EST
07:00:00 Sun 11 Mar 2018 UTC = 03:00:00 Sun 11 Mar 2018 EDT
07:00:01 Sun 11 Mar 2018 UTC = 03:00:01 Sun 11 Mar 2018 EDT
07:00:02 Sun 11 Mar 2018 UTC = 03:00:02 Sun 11 Mar 2018 EDT

-------- Nov-2018 time change --------
05:59:57 Sun 04 Nov 2018 UTC = 01:59:57 Sun 04 Nov 2018 EDT
05:59:58 Sun 04 Nov 2018 UTC = 01:59:58 Sun 04 Nov 2018 EDT
05:59:59 Sun 04 Nov 2018 UTC = 01:59:59 Sun 04 Nov 2018 EDT
06:00:00 Sun 04 Nov 2018 UTC = 01:00:00 Sun 04 Nov 2018 EST
06:00:01 Sun 04 Nov 2018 UTC = 01:00:01 Sun 04 Nov 2018 EST
06:00:02 Sun 04 Nov 2018 UTC = 01:00:02 Sun 04 Nov 2018 EST

-------- Mar-2019 time change --------
06:59:57 Sun 10 Mar 2019 UTC = 01:59:57 Sun 10 Mar 2019 EST
06:59:58 Sun 10 Mar 2019 UTC = 01:59:58 Sun 10 Mar 2019 EST
06:59:59 Sun 10 Mar 2019 UTC = 01:59:59 Sun 10 Mar 2019 EST
07:00:00 Sun 10 Mar 2019 UTC = 03:00:00 Sun 10 Mar 2019 EDT
07:00:01 Sun 10 Mar 2019 UTC = 03:00:01 Sun 10 Mar 2019 EDT
07:00:02 Sun 10 Mar 2019 UTC = 03:00:02 Sun 10 Mar 2019 EDT

-------- Nov-2019 time change --------
05:59:57 Sun 03 Nov 2019 UTC = 01:59:57 Sun 03 Nov 2019 EDT
05:59:58 Sun 03 Nov 2019 UTC = 01:59:58 Sun 03 Nov 2019 EDT
05:59:59 Sun 03 Nov 2019 UTC = 01:59:59 Sun 03 Nov 2019 EDT
06:00:00 Sun 03 Nov 2019 UTC = 01:00:00 Sun 03 Nov 2019 EST
06:00:01 Sun 03 Nov 2019 UTC = 01:00:01 Sun 03 Nov 2019 EST
06:00:02 Sun 03 Nov 2019 UTC = 01:00:02 Sun 03 Nov 2019 EST

-------- Mar-2020 time change --------
06:59:57 Sun 08 Mar 2020 UTC = 01:59:57 Sun 08 Mar 2020 EST
06:59:58 Sun 08 Mar 2020 UTC = 01:59:58 Sun 08 Mar 2020 EST
06:59:59 Sun 08 Mar 2020 UTC = 01:59:59 Sun 08 Mar 2020 EST
07:00:00 Sun 08 Mar 2020 UTC = 03:00:00 Sun 08 Mar 2020 EDT
07:00:01 Sun 08 Mar 2020 UTC = 03:00:01 Sun 08 Mar 2020 EDT
07:00:02 Sun 08 Mar 2020 UTC = 03:00:02 Sun 08 Mar 2020 EDT

-------- Nov-2020 time change --------
05:59:57 Sun 01 Nov 2020 UTC = 01:59:57 Sun 01 Nov 2020 EDT
05:59:58 Sun 01 Nov 2020 UTC = 01:59:58 Sun 01 Nov 2020 EDT
05:59:59 Sun 01 Nov 2020 UTC = 01:59:59 Sun 01 Nov 2020 EDT
06:00:00 Sun 01 Nov 2020 UTC = 01:00:00 Sun 01 Nov 2020 EST
06:00:01 Sun 01 Nov 2020 UTC = 01:00:01 Sun 01 Nov 2020 EST
06:00:02 Sun 01 Nov 2020 UTC = 01:00:02 Sun 01 Nov 2020 EST
```

---

### 8. WriteRules on Adafruit NRF52840_FEATHER using LittleFS

The following is debug terminal output when running example [**WriteRules**](examples/WriteRules) on NRF52840_FEATHER using **LittleFS**

```
Start WriteRules on NRF52840_FEATHER
Timezone_Generic v1.4.0
[TZ] Saving m_dst & m_std to TZ_file : /timezone.dat , data offset = 0
[TZ] Saving to TZ_file OK
WriteRules done
[TZ] Reading m_dst & m_std from TZ_file : /timezone.dat , data offset = 0
[TZ] Reading from TZ_file OK
readRules done
[TZ] DST rule
[TZ] abbrev : EDT , week : 2
[TZ] dow : 1 , month : 3
[TZ] hour : 2 , offset : -240
[TZ] DST rule
[TZ] abbrev : EST , week : 1
[TZ] dow : 1 , month : 11
[TZ] hour : 2 , offset : -300
```

---

### 9. WriteRules on SAMD_NANO_33_IOT using FlashStorage_SAMD

The following is debug terminal output when running example [**WriteRules**](examples/WriteRules) on Arduino SAMD21 SAMD_NANO_33_IOT using **FlashStorage_SAMD**

```
Start WriteRules on SAMD_NANO_33_IOT
Timezone_Generic v1.4.0
WriteRules done
readRules done
[TZ] DST rule
[TZ] abbrev : EDT , week : 2
[TZ] dow : 1 , month : 3
[TZ] hour : 2 , offset : -240
[TZ] DST rule
[TZ] abbrev : EST , week : 1
[TZ] dow : 1 , month : 11
[TZ] hour : 2 , offset : -300
```

---

### 10. WriteRules on STM32F7 Nucleo-144 NUCLEO_F767ZI using EEPROM

The following is debug terminal output when running example [**WriteRules**](examples/WriteRules) on STM32F7 Nucleo-144 NUCLEO_F767ZI using **EEPROM**

```
Start WriteRules on NUCLEO_F767ZI
Timezone_Generic v1.4.0
[TZ] Write to EEPROM, size =  16384 , offset =  0
WriteRules done
[TZ] Read from EEPROM, size =  16384 , offset =  0
readRules done
[TZ] DST rule
[TZ] abbrev : EDT , week : 2
[TZ] dow : 1 , month : 3
[TZ] hour : 2 , offset : -240
[TZ] DST rule
[TZ] abbrev : EST , week : 1
[TZ] dow : 1 , month : 11
[TZ] hour : 2 , offset : -300
```

---

### 11. WriteRules on Arduino SAM DUE using dueFlashStorage

The following is debug terminal output when running example [**WriteRules**](examples/WriteRules) on Arduino SAM DUE using **dueFlashStorage**

```
Start WriteRules
Timezone_Generic v1.4.0
[TZ] Writing to dueFlashStorage OK
WriteRules done
[TZ] Reading from dueFlashStorage OK
readRules done
[TZ] DST rule
[TZ] abbrev : EDT , week : 2
[TZ] dow : 1 , month : 3
[TZ] hour : 2 , offset : -240
[TZ] DST rule
[TZ] abbrev : EST , week : 1
[TZ] dow : 1 , month : 11
[TZ] hour : 2 , offset : -300
```

---

### 12. WriteRules on ESP32_DEV using new ESP32 LittleFS

The following is debug terminal output when running example [**WriteRules**](examples/WriteRules) on ESP32_DEV using new **ESP32 LittleFS**

```
Start WriteRules on ESP32_DEV
Timezone_Generic v1.4.0
[TZ] Saving m_dst & m_std to TZ_file : /timezone.dat , data offset = 0
[TZ] Saving to TZ_file OK
WriteRules done
[TZ] Reading m_dst & m_std from TZ_file : /timezone.dat , data offset = 0
[TZ] Reading from TZ_file OK
readRules done
[TZ] DST rule
[TZ] abbrev : EDT , week : 2
[TZ] dow : 1 , month : 3
[TZ] hour : 2 , offset : -240
[TZ] DST rule
[TZ] abbrev : EST , week : 1
[TZ] dow : 1 , month : 11
[TZ] hour : 2 , offset : -300
```

---

### 13. WriteRules on ESP8266_NODEMCU using LittleFS

The following is debug terminal output when running example [**WriteRules**](examples/WriteRules) on ESP8266_NODEMCU using **LittleFS**

```
Start WriteRules on ESP8266_NODEMCU
Timezone_Generic v1.4.0
[TZ] Saving m_dst & m_std to TZ_file : /timezone.dat , data offset = 0
[TZ] Saving to TZ_file OK
WriteRules done
[TZ] Reading m_dst & m_std from TZ_file : /timezone.dat , data offset = 0
[TZ] Reading from TZ_file OK
readRules done
[TZ] DST rule
[TZ] abbrev : EDT , week : 2
[TZ] dow : 1 , month : 3
[TZ] hour : 2 , offset : -240
[TZ] DST rule
[TZ] abbrev : EST , week : 1
[TZ] dow : 1 , month : 11
[TZ] hour : 2 , offset : -300
```

---

### 14. BI_RTC_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A

The following is debug terminal output when running example [**BI_RTC_STM32_Ethernet**](examples/Ethernet/BI_RTC_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library to demonstrate the usage of STM32 built-in RTC

```
Start BI_RTC_STM32_Ethernet on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
Timezone_Generic v1.4.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.97
Packet received
Seconds since Jan 1 1900 = 3812898366
Unix time = 1603909566

Updating Time for STM32 RTC
The UTC time is 18:26:06
============================
18:26:06 Wed 28 Oct 2020 UTC
14:26:06 Wed 28 Oct 2020 EDT
============================
18:26:15 Wed 28 Oct 2020 UTC
14:26:15 Wed 28 Oct 2020 EDT
============================
18:26:24 Wed 28 Oct 2020 UTC
14:26:24 Wed 28 Oct 2020 EDT
============================
18:26:33 Wed 28 Oct 2020 UTC
14:26:33 Wed 28 Oct 2020 EDT
============================
18:26:43 Wed 28 Oct 2020 UTC
14:26:43 Wed 28 Oct 2020 EDT
```


---

### 15. BI_RTC_Alarm_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A

The following is debug terminal output when running example [**BI_RTC_Alarm_STM32_Ethernet**](examples/Ethernet/BI_RTC_Alarm_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library to demonstrate the usage of STM32 built-in RTC Alarm function

```
Start BI_RTC_Alarm_STM32_Ethernet on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
Timezone_Generic v1.4.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.96
Packet received
Seconds since Jan 1 1900 = 3812900198
Unix time = 1603911398

Updating Time for STM32 RTC
=======RTC ALARM SET========
18:57:08 Wed 28 Oct 2020 UTC
14:57:08 Wed 28 Oct 2020 EDT
============================
The UTC time is 18:56:38
============================
18:56:38 Wed 28 Oct 2020 UTC
14:56:38 Wed 28 Oct 2020 EDT
============================
18:56:47 Wed 28 Oct 2020 UTC
14:56:47 Wed 28 Oct 2020 EDT
============================
18:56:56 Wed 28 Oct 2020 UTC
14:56:56 Wed 28 Oct 2020 EDT
============================
18:57:05 Wed 28 Oct 2020 UTC
14:57:05 Wed 28 Oct 2020 EDT
*****RTC ALARM ACTIVATED*****
*****RTC ALARM ACTIVATED*****
============================
18:57:15 Wed 28 Oct 2020 UTC
14:57:15 Wed 28 Oct 2020 EDT
```

---

### 16. TZ_NTP_WorldClock_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA

The following is debug terminal output when running example [**TZ_NTP_WorldClock_WiFiNINA**](examples/WiFiNINA/TZ_NTP_WorldClock_WiFiNINA) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

```
Start TZ_NTP_WorldClock_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
Timezone_Generic v1.4.0
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.153
Listening on port 2390
Packet received
Seconds since Jan 1 1900 = 3831822093
Unix time = 1622833293
The UTC time is 19:01:33

05:01:33 Sat 05 Jun 2021 AEST Sydney
22:01:33 Fri 04 Jun 2021 MSK  Moscow
21:01:33 Fri 04 Jun 2021 CEST Paris
20:01:33 Fri 04 Jun 2021 BST  London
19:01:33 Fri 04 Jun 2021 UTC  Universal Coordinated Time
15:01:33 Fri 04 Jun 2021 EDT  New York
14:01:33 Fri 04 Jun 2021 CDT  Chicago
13:01:33 Fri 04 Jun 2021 MDT  Denver
12:01:33 Fri 04 Jun 2021 MST  Phoenix
12:01:33 Fri 04 Jun 2021 PDT  Los Angeles

05:01:42 Sat 05 Jun 2021 AEST Sydney
22:01:42 Fri 04 Jun 2021 MSK  Moscow
21:01:42 Fri 04 Jun 2021 CEST Paris
20:01:42 Fri 04 Jun 2021 BST  London
19:01:42 Fri 04 Jun 2021 UTC  Universal Coordinated Time
15:01:42 Fri 04 Jun 2021 EDT  New York
14:01:42 Fri 04 Jun 2021 CDT  Chicago
13:01:42 Fri 04 Jun 2021 MDT  Denver
12:01:42 Fri 04 Jun 2021 MST  Phoenix
12:01:42 Fri 04 Jun 2021 PDT  Los Angeles

05:01:52 Sat 05 Jun 2021 AEST Sydney
22:01:52 Fri 04 Jun 2021 MSK  Moscow
21:01:52 Fri 04 Jun 2021 CEST Paris
20:01:52 Fri 04 Jun 2021 BST  London
19:01:52 Fri 04 Jun 2021 UTC  Universal Coordinated Time
15:01:52 Fri 04 Jun 2021 EDT  New York
14:01:52 Fri 04 Jun 2021 CDT  Chicago
13:01:52 Fri 04 Jun 2021 MDT  Denver
12:01:52 Fri 04 Jun 2021 MST  Phoenix
12:01:52 Fri 04 Jun 2021 PDT  Los Angeles
```

---

### 17. TZ_NTP_WorldClock_Ethernet on MBED RASPBERRY_PI_PICO with W5x00

The following is debug terminal output when running example [**TZ_NTP_WorldClock_Ethernet**](examples/Ethernet/TZ_NTP_WorldClock_Ethernet) on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

```
Start TZ_NTP_WorldClock_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
Timezone_Generic v1.4.0
[EWS] =========== USE_ETHERNET_LARGE ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 3
[EWS] MISO: 4
[EWS] SCK: 2
[EWS] SS: 5
[EWS] =========================
[EWS] RPIPICO setCsPin: 5
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 5, new ss_pin = 10, W5100Class::ss_pin = 5
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:3
MISO:4
SCK:2
SS:5
=========================
Using mac index = 8
You're connected to the network, IP = 192.168.2.99
Packet received
Seconds since Jan 1 1900 = 3831845852
Unix time = 1622857052
The UTC time is 1:37:32

11:37:32 Sat 05 Jun 2021 AEST Sydney
04:37:32 Sat 05 Jun 2021 MSK  Moscow
03:37:32 Sat 05 Jun 2021 CEST Paris
02:37:32 Sat 05 Jun 2021 BST  London
01:37:32 Sat 05 Jun 2021 UTC  Universal Coordinated Time
21:37:32 Fri 04 Jun 2021 EDT  New York
20:37:32 Fri 04 Jun 2021 CDT  Chicago
19:37:32 Fri 04 Jun 2021 MDT  Denver
18:37:32 Fri 04 Jun 2021 MST  Phoenix
18:37:32 Fri 04 Jun 2021 PDT  Los Angeles
```

---

### 18. TZ_NTP_WorldClock_Ethernet on RASPBERRY_PI_PICO with W5x00

The following is debug terminal output when running example [**TZ_NTP_WorldClock_Ethernet**](examples/Ethernet/TZ_NTP_WorldClock_Ethernet) on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library


```
Start TZ_NTP_WorldClock_Ethernet on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
Timezone_Generic v1.4.0
[EWS] =========== USE_ETHERNET_LARGE ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] RPIPICO setCsPin: 17
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 17
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 11
You're connected to the network, IP = 192.168.2.96
Packet received
Seconds since Jan 1 1900 = 3831823507
Unix time = 1622834707
The UTC time is 19:25:07

05:25:07 Sat 05 Jun 2021 AEST Sydney
22:25:07 Fri 04 Jun 2021 MSK  Moscow
21:25:07 Fri 04 Jun 2021 CEST Paris
20:25:07 Fri 04 Jun 2021 BST  London
19:25:07 Fri 04 Jun 2021 UTC  Universal Coordinated Time
15:25:07 Fri 04 Jun 2021 EDT  New York
14:25:07 Fri 04 Jun 2021 CDT  Chicago
13:25:07 Fri 04 Jun 2021 MDT  Denver
12:25:07 Fri 04 Jun 2021 MST  Phoenix
12:25:07 Fri 04 Jun 2021 PDT  Los Angeles

05:25:17 Sat 05 Jun 2021 AEST Sydney
22:25:17 Fri 04 Jun 2021 MSK  Moscow
21:25:17 Fri 04 Jun 2021 CEST Paris
20:25:17 Fri 04 Jun 2021 BST  London
19:25:17 Fri 04 Jun 2021 UTC  Universal Coordinated Time
15:25:17 Fri 04 Jun 2021 EDT  New York
14:25:17 Fri 04 Jun 2021 CDT  Chicago
13:25:17 Fri 04 Jun 2021 MDT  Denver
12:25:17 Fri 04 Jun 2021 MST  Phoenix
12:25:17 Fri 04 Jun 2021 PDT  Los Angeles
```


---
---

## Releases

### Major Releases v1.4.0

1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** v1.7.0+ core](https://github.com/earlephilhower/arduino-pico).
2. Add support to RP2040-based boards, such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** v2.1.0+ core](https://github.com/arduino/ArduinoCore-mbed).
3. Improve and add more debugging codes
4. Update examples with new features

### Major Releases v1.3.0

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
5. Completely new examples.

---

### Currently Supported Boards

  - **ESP8266**.
  - **ESP32**.
  - **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox etc.**.
  - **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**.
  - **Adafruit SAM21 (Itsy-Bitsy M0, Metro M0, Feather M0, Gemma M0, etc.)**.
  - **Adafruit SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
  - **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
  - **STM32 (Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32F1, STM32F3, STM32F4, STM32H7, STM32L0, etc.)**.
  - **STM32F/L/H/G/WB/MP1 (Nucleo-64 L053R8,Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32Fx, STM32H7, STM32Lx, STM32Gx, STM32WB, STM32MP1, etc.) having 64K+ Flash program memory.**
  - **Arduino AVR boards (UNO, Nano, Mega, etc.)**
  - **Arduino MegaAVR boards (UNO WiFi Rev 2, Nano Every, etc.)**
  - RP2040-based boards, such as **Nano_RP2040_Connect**, using [**Arduino mbed OS for Nano boards**](https://github.com/arduino/ArduinoCore-mbed).
  - RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).
  
### Currently Supported WiFi Modules and Shields

  - **ESP8266 built-in WiFi**.
  - **ESP32 built-in WiFi**.
  - **WiFiNINA using WiFiNINA or WiFiNINA_Generic library**.
  - **ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or [ESP8266_AT_WebServer](https://github.com/khoih-prog/ESP8266_AT_WebServer) library**.
  
### Currently Supported Ethernet Modules and Shields

  - **W5x00's using Ethernet, EthernetLarge, Ethernet2 or Ethernet3 Library.**
  - **ENC28J60 using EthernetENC or UIPEthernet library.**
  - **LAN8742A using STM32Ethernet / STM32 LwIP libraries.**

### Currently Supported Storage

  - **ESP8266 LittleFS, SPIFFS**.
  - **ESP32 SPIFFS and LittleFS**.
  - **SAM DUE DueFlashStorage**.
  - **SAMD FlashStorage_SAMD**.
  - **nRF52/RP2040 LittleFS**.
  - **STM32, Teensy and AVR, MegaAVR EEPROM**.
  
---
---

### Issues

Submit issues to: [Timezone_Generic issues](https://github.com/khoih-prog/Timezone_Generic/issues)

---
---

### TO DO

1. Bug Searching and Killing
2. Add more examples

---

### DONE

 1. Add support to **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.) and FlashStorage**
 2. Add support to **Adafruit SAMD21 (Itsy-Bitsy M0, Metro M0, Feather M0 Express, etc.) and FlashStorage**.
 3. Add support to **Adafruit SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.) and FlashStorage**.
 4. Add support to **Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc. annd LittleFS**.
 5. Add support to **SAM DUE and DueFlashStorage**.
 6. Add support to Ethernet W5x00, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/adafruit/Ethernet2), [`Ethernet3`](https://github.com/sstaub/Ethernet3) or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 7. Add support to Ethernet ENC28J60, using [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
 8. Add support to Seeeduino SAMD21/SAMD51: LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, Wio Terminal, Grove UI Wireless and FlashStorage.
 9. Add support to [`EthernetENC`](https://github.com/jandrassy/EthernetENC)
10. Add support to ESP32/ESP8266 boards using SPIFFS or LittleFS
11. Add support to Arduino AVR boards (UNO, Nano, Mega, etc.)
12. Add support to Arduino MegaAVR boards (UNO WiFi Rev 2, Nano Every, etc.)
13. Add support to **Arduino Nano RP2040 Connect** using [**Arduino mbed OS for Nano boards**](https://github.com/arduino/ArduinoCore-mbed).
14. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).
15. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Based on and modified from the [**Jack Christensen's Timezone Library**](https://github.com/JChristensen/Timezone).
2. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing.
3. Thanks to **6v6gt** to contribute the new feature to allow un-initialized TZ. Check [**Timezone_Generic Library to convert UTC to local time**](https://forum.arduino.cc/index.php?topic=711259).

<table>
  <tr>
    <td align="center"><a href="https://github.com/JChristensen"><img src="https://github.com/JChristensen.png" width="100px;" alt="JChristensen"/><br /><sub><b>⭐️ Jack Christensen</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b> Miguel Wisintainer</b></sub></a><br /></td>
    <td align="center"><a href="https://forum.arduino.cc/index.php?action=profile;u=454553"><img src="https://dcw9y8se13llu.cloudfront.net/avatars/6v6gt.jpg" width="100px;" alt="6v6gt"/><br /><sub><b> 6v6gt</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [GPLv3](https://github.com/khoih-prog/Timezone_Generic/blob/main/LICENSE)

---

## Copyright

- Copyright 2012- Jack Christensen

- Copyright 2020- Khoi Hoang


