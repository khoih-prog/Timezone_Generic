## Timezone_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/Timezone_Generic.svg?)](https://www.ardu-badge.com/Timezone_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Timezone_Generic.svg)](https://github.com/khoih-prog/Timezone_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Timezone_Generic/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Timezone_Generic.svg)](http://github.com/khoih-prog/Timezone_Generic/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

---
---

## Table of Contents

* [Important Change from v1.9.0](#Important-Change-from-v190)
* [Why do we need this Timezone_Generic library](#why-do-we-need-this-timezone_generic-library)
  * [Features](#features)
  * [Currently Supported Boards](#currently-supported-boards)
  * [Currently Supported WiFi Modules and Shields](#currently-supported-wifi-modules-and-shields)
  * [Currently Supported Ethernet Modules and Shields](#currently-supported-ethernet-modules-and-shields)
  * [Currently Supported Storage](#currently-supported-storage)
* [Changelog](changelog.md)
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
  * [9. For Portenta_H7 boards using Arduino IDE in Linux](#9-for-portenta_h7-boards-using-arduino-ide-in-linux)
  * [10. For RTL8720DN boards using AmebaD core](#10-for-rtl8720dn-boards-using-amebad-core)
  * [11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core](#11-For-SAMD21-and-SAMD51-boards-using-ArduinoCore-fab-sam-core)
  * [12. For Seeeduino RP2040 boards](#12-For-Seeeduino-RP2040-boards)
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
* [Note for Platform IO using ESP32 LittleFS](#note-for-platform-io-using-esp32-littlefs)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [Usage](#usage)
  * [TimeChangeRules struct](#timechangerules-struct)
  * [Timezone class](#timezone-class)
    * [1. Using initialized Timezone](#1-using-initialized-timezone)
    * [2. Using un-initialized Timezone (from v1.2.6)](#2-using-un-initialized-timezone-from-v126)
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
    * [ 1. RTC_Ethernet](examples/Ethernet/RTC_Ethernet)
    * [ 2. TZ_NTP_Clock_Ethernet](examples/Ethernet/TZ_NTP_Clock_Ethernet)
    * [ 3. TZ_NTP_WorldClock_Ethernet](examples/Ethernet/TZ_NTP_WorldClock_Ethernet)
  * [STM32F/L/H/G/WB/MP1 Boards with Ethernet](#stm32flhgwbmp1-boards-with-ethernet)
    * [ 1. BI_RTC_Alarm_STM32_Ethernet](examples/Ethernet/BI_RTC_Alarm_STM32_Ethernet)
    * [ 2. BI_RTC_STM32_Ethernet](examples/Ethernet/BI_RTC_STM32_Ethernet)
    * [ 3. RTC_STM32_Ethernet](examples/Ethernet/RTC_STM32_Ethernet)
    * [ 4. TZ_NTP_Clock_STM32_Ethernet](examples/Ethernet/TZ_NTP_Clock_STM32_Ethernet)
    * [ 5. TZ_NTP_WorldClock_STM32_Ethernet](examples/Ethernet/TZ_NTP_WorldClock_STM32_Ethernet)
  * [Generic Boards with WiFiNINA](#generic-boards-with-wifinina)
    * [ 1. RTC_WiFiNINA](examples/WiFiNINA/RTC_WiFiNINA)
    * [ 2. TZ_NTP_Clock_WiFiNINA](examples/WiFiNINA/TZ_NTP_Clock_WiFiNINA)
    * [ 3. TZ_NTP_WorldClock_WiFiNINA](examples/WiFiNINA/TZ_NTP_WorldClock_WiFiNINA)
  * [WT32_ETH01 Boards](#wt32_eth01-boards)
    * [ 1. TZ_NTP_Clock_WT32_ETH01](examples/WT32_ETH01/TZ_NTP_Clock_WT32_ETH01)
    * [ 2. TZ_NTP_WorldClock_WT32_ETH01](examples/WT32_ETH01/TZ_NTP_WorldClock_WT32_ETH01)
  * [RTL8720DN Boards](#rtl8720dn-boards)
    * [ 1. TZ_NTP_Clock_RTL8720DN](examples/RTL8720DN/TZ_NTP_Clock_RTL8720DN)
    * [ 2. TZ_NTP_WorldClock_RTL8720DN](examples/RTL8720DN/TZ_NTP_WorldClock_RTL8720DN)
  * [Portenta_H7 WiFi](#Portenta_H7-WiFi) **New**
    * [ 1. TZ_NTP_Clock_WiFi](examples/Portenta_H7_WiFi/TZ_NTP_Clock_WiFi)
    * [ 2. TZ_NTP_WorldClock_WiFi](examples/Portenta_H7_WiFi/TZ_NTP_WorldClock_WiFi) 
  * [RP2040W Boards with CYW43439 WiFi](#RP2040W-Boards-with-CYW43439-WiFi)
    * [ 1. RTC_RP2040W](examples/RP2040W/RTC_RP2040W) **New**
    * [ 2. TZ_NTP_Clock_RP2040W](examples/RP2040W/TZ_NTP_Clock_RP2040W)
    * [ 3. TZ_NTP_WorldClock_RP2040W](examples/RP2040W/TZ_NTP_WorldClock_RP2040W)
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
  * [19. TZ_NTP_WorldClock_WT32_ETH01 on WT32-ETH01 with ETH_PHY_LAN8720](#19-tz_ntp_worldclock_wt32_eth01-on-wt32-eth01-with-eth_phy_lan8720)
  * [20. TZ_NTP_WorldClock_RTL8720DN on Rtlduino RTL8720DN](#20-tz_ntp_worldclock_rtl8720dn-on-rtlduino-rtl8720dn)
  * [21. TZ_NTP_Clock_Ethernet on PORTENTA_H7_M7](#21-TZ_NTP_Clock_Ethernet-on-PORTENTA_H7_M7)
  * [22. TZ_NTP_WorldClock_WiFi on PORTENTA_H7_M7](#22-TZ_NTP_WorldClock_WiFi-on-PORTENTA_H7_M7)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Important Change from v1.9.0

Please have a look at [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error)


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
  - RP2040-based boards, such as **RASPBERRY_PI_PICO, RASPBERRY_PI_PICO_W, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).
  - **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet
  - **RTL8720DN, RTL8722DM, RTL8722CSM, etc. boards**
  - **Portenta_H7**
  
### Currently Supported WiFi Modules and Shields

  - **ESP8266 built-in WiFi**.
  - **ESP32 built-in WiFi**.
  - **WiFiNINA using WiFiNINA or WiFiNINA_Generic library**.
  - **ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or [ESP8266_AT_WebServer](https://github.com/khoih-prog/ESP8266_AT_WebServer) library**.
  - **RTL8720DN, RTL8722DM, RTL8722CSM**
  - **Built-in WiFi of Portenta_H7**
  - **Built-in WiFi of RP2040W**
  
### Currently Supported Ethernet Modules and Shields

  - **W5x00's using Ethernet_Generic Library.**
  - **ENC28J60 using EthernetENC or UIPEthernet library.**
  - **LAN8742A using STM32Ethernet / STM32 LwIP libraries.**
  - **LAN8720A in WT32-ETH01** using [`WebServer_WT32_ETH01`](https://github.com/khoih-prog/WebServer_WT32_ETH01).
  - **Portenta_H7 Ethernet** using [`Portenta_Ethernet`](https://github.com/arduino/ArduinoCore-mbed/tree/master/libraries/Ethernet) library
  
### Currently Supported Storage

  - **ESP8266 LittleFS, SPIFFS**.
  - **ESP32, ESP32-S2 SPIFFS and LittleFS. ESP32-C3 SPIFFS**.
  - **SAM DUE DueFlashStorage**.
  - **SAMD FlashStorage_SAMD**.
  - **nRF52/RP2040 LittleFS**.
  - **STM32, Teensy and AVR, MegaAVR EEPROM**.
  - **RTL8720 FlashStorage_RTL8720**.
  - **Portenta_H7 LittleFS**.

---
---


## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Arduino AVR core 1.8.5+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) for AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest)
 3. [`Arduino MegaAVR core v1.8.3+`](https://github.com/arduino/ArduinoCore-megaavr) for Arduino MegaAVR boards such as Arduino Uno WiFi Rev2. Use Arduino Board Manager to install. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-megaavr.svg)](https://github.com/arduino/ArduinoCore-megaavr/releases/latest)
 4. [`ESP32 Core 2.0.5+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 5. [`ESP8266 Core 3.0.2+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS. 
 6. [`Teensy core v1.57+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. **Ready** from v1.0.0.
 7. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 8. [`Arduino SAMD core 1.8.13+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 9. [`Adafruit SAMD core 1.7.10+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
10. [`Seeeduino SAMD core 1.8.3+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
11. [`Adafruit nRF52 v1.3.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest) 
12. [`Arduino Core for STM32 v2.3.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)
13. [`Arduino mbed_rp2040 core 3.3.0+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino RP2040-based boards, such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
14. [`Earle Philhower's arduino-pico core v2.5.4+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
15. [`Arduino AmebaD core 3.1.4+`](https://github.com/ambiot/ambd_arduino) for Realtek RTL8720DN, RTL8722DM and RTL8722CSM. [![GitHub release](https://img.shields.io/github/release/ambiot/ambd_arduino.svg)](https://github.com/ambiot/ambd_arduino/releases/latest)
16. [`Time v1.6.1+`](https://github.com/PaulStoffregen/Time). [![GitHub release](https://img.shields.io/github/release/PaulStoffregen/Time.svg)](https://github.com/PaulStoffregen/Time/releases/latest). For PIO [`Time library`](https://platformio.org/lib/show/44/Time)
17. Depending on which board you're using:
   - [`DueFlashStorage library v1.0.0+`](https://github.com/sebnil/DueFlashStorage) for SAM DUE.
   - [`FlashStorage_SAMD library v1.3.2+`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD21 and SAMD51 boards (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit Itsy-Bitsy M4, etc.). [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_SAMD.svg)](https://github.com/khoih-prog/FlashStorage_SAMD/releases/latest)
   - [`FlashStorage_STM32F1 library v1.1.0+`](https://github.com/khoih-prog/FlashStorage_STM32F1) for STM32F1/F3 boards. [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_STM32F1.svg)](https://github.com/khoih-prog/FlashStorage_STM32F1/releases/latest)
   - [`FlashStorage_STM32 library v1.2.0+`](https://github.com/khoih-prog/FlashStorage_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_STM32.svg)](https://github.com/khoih-prog/FlashStorage_STM32/releases/latest)
   - [`FlashStorage_RTL8720 library v1.1.0+`](https://github.com/khoih-prog/FlashStorage_RTL8720) for RTL8720DN. etc. boards. [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_RTL8720.svg)](https://github.com/khoih-prog/FlashStorage_RTL8720/releases/latest)
   - [`LittleFS_esp32 v1.0.6+`](https://github.com/lorol/LITTLEFS) for ESP32-based boards using LittleFS. [![GitHub release](https://img.shields.io/github/release/lorol/LITTLEFS.svg)](https://github.com/lorol/LITTLEFS/releases/latest). **Notice**: This [`LittleFS_esp32 library`](https://github.com/lorol/LITTLEFS) has been integrated to Arduino [esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/tree/master/libraries/LITTLEFS).

18. Depending on which Ethernet card/module/shield you're using:
   - [`Ethernet_Generic library v2.6.1+`](https://github.com/khoih-prog/Ethernet_Generic) for W5100, W5200 and W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.  [![GitHub release](https://img.shields.io/github/release/khoih-prog/Ethernet_Generic.svg)](https://github.com/khoih-prog/Ethernet_Generic/releases/latest)
   - [`EthernetENC library v2.0.3+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.12+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest)
   - [`STM32Ethernet library v1.3.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32Ethernet.svg)](https://github.com/stm32duino/STM32Ethernet/releases/latest). To be used with [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP). [![GitHub release](https://img.shields.io/github/release/stm32duino/LwIP.svg)](https://github.com/stm32duino/LwIP/releases/latest). 
19. [`WiFiNINA_Generic library v1.8.14-6+`](https://github.com/khoih-prog/WiFiNINA_Generic) to use WiFiNINA modules/shields if using WiFiNINA for boards such as Nano 33 IoT, nRF52, Teensy, etc. [![GitHub release](https://img.shields.io/github/release/khoih-prog/WiFiNINA_Generic.svg)](https://github.com/khoih-prog/WiFiNINA_Generic/releases/latest)
20. [`WiFiWebServer library v1.9.5+`](https://github.com/khoih-prog/WiFiWebServer) to use WiFi/WiFiNINA modules/shields. [![GitHub release](https://img.shields.io/github/release/khoih-prog/WiFiWebServer.svg)](https://github.com/khoih-prog/WiFiWebServer/releases/latest)
21. [`EthernetWebServer library v2.2.3+`](https://github.com/khoih-prog/EthernetWebServer) to use Ethernet modules/shields on boards other than STM32F/L/H/G/WB/MP1. [![GitHub release](https://img.shields.io/github/release/khoih-prog/EthernetWebServer.svg)](https://github.com/khoih-prog/EthernetWebServer/releases/latest)
22. [`EthernetWebServer_STM32 library v1.5.0+`](https://github.com/khoih-prog/EthernetWebServer_STM32) to use Ethernet modules/shields on STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/khoih-prog/EthernetWebServer_STM32.svg)](https://github.com/khoih-prog/EthernetWebServer_STM32/releases/latest)
23. [`ESP8266_AT_WebServer library v1.5.4+`](https://github.com/khoih-prog/ESP8266_AT_WebServer) to use ESP8266-AT/ESP32-AT WiFi modules/shields. [![GitHub release](https://img.shields.io/github/release/khoih-prog/ESP8266_AT_WebServer.svg)](https://github.com/khoih-prog/ESP8266_AT_WebServer/releases/latest)
24. [`DS323x_Generic library v1.3.1+`](https://github.com/khoih-prog/DS323x_Generic) to use examples using DS323x RTC modules/shields. [![GitHub release](https://img.shields.io/github/release/khoih-prog/DS323x_Generic.svg)](https://github.com/khoih-prog/DS323x_Generic/releases/latest)
25. [`STM32RTC library v1.3.1+`](https://github.com/stm32duino/STM32RTC) to use STM32 examples using built-in STM32 RTC. [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32RTC.svg)](https://github.com/stm32duino/STM32RTC/releases/latest).
26. [`WebServer_WT32_ETH01 library v1.5.1+`](https://github.com/khoih-prog/WebServer_WT32_ETH01) to use WT32_ETH01 (ESP32 + LAN8720). [![GitHub release](https://img.shields.io/github/release/khoih-prog/WebServer_WT32_ETH01.svg)](https://github.com/khoih-prog/WebServer_WT32_ETH01/releases/latest)
27. [`WiFiWebServer_RTL8720 library v1.1.2+`](https://github.com/khoih-prog/WiFiWebServer_RTL8720) to use Realtek RTL8720DN, etc. [![GitHub release](https://img.shields.io/github/release/khoih-prog/WiFiWebServer_RTL8720.svg)](https://github.com/khoih-prog/WiFiWebServer_RTL8720/releases/latest)


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
3. Install [**Timezone_Generic** library](https://registry.platformio.org/libraries/khoih-prog/Timezone_Generic) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/Timezone_Generic/installation). Search for **Timezone_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 Packages_Patches](Packages_Patches/adafruit/hardware/nrf52/1.3.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0). 

Supposing the Adafruit nRF52 version is 1.3.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.19/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.19. These files must be copied into the directory:

- `./arduino-1.8.19/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy4/Stream.h`

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
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD Packages_Patches](Packages_Patches/arduino/hardware/samd/1.8.13) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.13).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.13. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.13/platform.txt`

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
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the whole [Adafruit SAMD Packages_Patches](Packages_Patches/adafruit/hardware/samd/1.7.10) directory into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.10). 

Supposing the Adafruit SAMD core version is 1.7.10. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.10/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.10/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.10/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the whole [Seeeduino SAMD Packages_Patches](Packages_Patches/Seeeduino/hardware/samd/1.8.3) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3). 

Supposing the Seeeduino SAMD core version is 1.8.3. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.3.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.3.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.3.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 2.3.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
these files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/2.3.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.3.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 2.3.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/2.3.0/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
these files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h`

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


#### 9. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/3.3.0/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/3.3.0/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/3.3.0
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 3.3.0. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/3.3.0/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`


#### 10. For RTL8720DN boards using AmebaD core
 
 To avoid compile error relating to PROGMEM, you have to copy the file [Realtek AmebaD core pgmspace.h](Packages_Patches/realtek/hardware/AmebaD/3.1.4/cores/ambd/avr/pgmspace.h) into Realtek AmebaD directory (~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/arduino/avr/pgmspace.h). 

Supposing the Realtek AmebaD core version is 3.1.4. This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/3.1.4/cores/arduino/avr/pgmspace.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/x.yy.zz/cores/arduino/avr/pgmspace.h`


#### 11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core
 
 To avoid compile error relating to SAMD21/SAMD51, you have to copy the file [ArduinoCore-fab-sam core pgmspace.h](Packages_Patches/Fab_SAM_Arduino/hardware/samd/1.7.0/boards.txt) into `ArduinoCore-fab-sam` samd directory (~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.7.0/boards.txt). 

Supposing the `ArduinoCore-fab-sam` samd core version is 1.7.0. This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.7.0/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/x.yy.zz/boards.txt`


#### 12. For Seeeduino RP2040 boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino RP2040 (XIAO RP2040, Wio RP2040 Mini) boards***, you have to copy the whole [Seeeduino RP2040 Packages_Patches](Packages_Patches/Seeeduino/hardware/rp2040/2.7.2) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2). 

Supposing the Seeeduino SAMD core version is 2.7.2. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/variants/Seeed_XIAO_RP2040/pins_arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/variants/Seeed_XIAO_RP2040/pins_arduino.h`


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

**To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library**, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

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

The current library implementation, using `xyz-Impl.h` instead of standard `xyz.cpp`, possibly creates certain `Multiple Definitions` Linker error in certain use cases.

You can use

```
#include <Timezone_Generic.hpp>               //https://github.com/khoih-prog/Timezone_Generic
```

in many files. But be sure to use the following `#include <Timezone_Generic.h>` **in just 1 `.h`, `.cpp` or `.ino` file**, which must **not be included in any other file**, to avoid `Multiple Definitions` Linker Error

```
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <Timezone_Generic.h>                //https://github.com/khoih-prog/Timezone_Generic
```


---
---


### Note for Platform IO using ESP32 LittleFS

#### Necessary only for esp32 core v1.0.6-

From esp32 core v1.0.6+, [`LittleFS_esp32 v1.0.6`](https://github.com/lorol/LITTLEFS) has been included and this step is not necessary anymore.

In Platform IO, to fix the error when using [`LittleFS_esp32 v1.0`](https://github.com/lorol/LITTLEFS) for ESP32-based boards with ESP32 core v1.0.4- (ESP-IDF v3.2-), uncomment the following line

from

```
//#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

to

```
#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

It's advisable to use the latest [`LittleFS_esp32 v1.0.5+`](https://github.com/lorol/LITTLEFS) to avoid the issue.

Thanks to [Roshan](https://github.com/solroshan) to report the issue in [Error esp_littlefs.c 'utime_p'](https://github.com/khoih-prog/ESPAsync_WiFiManager/issues/28) 

---
---

### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/main/components/driver/adc_common.c#L61)

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

#### 1. Using initialized Timezone

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

#### 2. Using un-initialized Timezone (from v1.2.6)

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

then in setup(), get the correct TimeChangeRule (from SAM DUE DueFlashStorage, SAMD FlashStorage, nRF52 LittleFS, STM32 and AVR EEPROM, etc. or from any input), and initialized the Timezone.

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

 1. [RTC_Ethernet](examples/Ethernet/RTC_Ethernet) 
 2. [TZ_NTP_Clock_Ethernet](examples/Ethernet/TZ_NTP_Clock_Ethernet)
 3. [TZ_NTP_WorldClock_Ethernet](examples/Ethernet/TZ_NTP_WorldClock_Ethernet)
 
### STM32F/L/H/G/WB/MP1 Boards with Ethernet
 
 1. [BI_RTC_Alarm_STM32_Ethernet](examples/Ethernet/BI_RTC_Alarm_STM32_Ethernet)
 2. [BI_RTC_STM32_Ethernet](examples/Ethernet/BI_RTC_STM32_Ethernet)
 3. [RTC_STM32_Ethernet](examples/Ethernet/RTC_STM32_Ethernet)
 4. [TZ_NTP_Clock_STM32_Ethernet](examples/Ethernet/TZ_NTP_Clock_STM32_Ethernet)
 5. [TZ_NTP_WorldClock_STM32_Ethernet](examples/Ethernet/TZ_NTP_WorldClock_STM32_Ethernet)
 
### Generic Boards with WiFiNINA 
 
 1. [RTC_WiFiNINA](examples/WiFiNINA/RTC_WiFiNINA) 
 2. [TZ_NTP_Clock_WiFiNINA](examples/WiFiNINA/TZ_NTP_Clock_WiFiNINA)
 3. [TZ_NTP_WorldClock_WiFiNINA](examples/WiFiNINA/TZ_NTP_WorldClock_WiFiNINA)

### WT32_ETH01 Boards
 
 1. [TZ_NTP_Clock_WT32_ETH01](examples/WT32_ETH01/TZ_NTP_Clock_WT32_ETH01)
 2. [TZ_NTP_WorldClock_WT32_ETH01](examples/WT32_ETH01/TZ_NTP_WorldClock_WT32_ETH01)

### RTL8720DN Boards
 
 1. [TZ_NTP_Clock_RTL8720DN](examples/RTL8720DN/TZ_NTP_Clock_RTL8720DN)
 2. [TZ_NTP_WorldClock_RTL8720DN](examples/RTL8720DN/TZ_NTP_WorldClock_RTL8720DN)

### Portenta_H7 WiFi
 
 1. [TZ_NTP_Clock_WiFi](examples/Portenta_H7_WiFi/TZ_NTP_Clock_WiFi) **New**
 2. [TZ_NTP_WorldClock_WiFi](examples/Portenta_H7_WiFi/TZ_NTP_WorldClock_WiFi) **New**
 
### RP2040W Boards with CYW43439 WiFi 
 
 1. [RTC_RP2040W](examples/RP2040W/RTC_RP2040W) **New**
 2. [TZ_NTP_Clock_RP2040W](examples/RP2040W/TZ_NTP_Clock_RP2040W) **New**
 3. [TZ_NTP_WorldClock_RP2040W](examples/RP2040W/TZ_NTP_WorldClock_RP2040W) **New**

---
---

### Example [TZ_NTP_Clock_Ethernet](examples/Ethernet/TZ_NTP_Clock_Ethernet)

#### 1. File [TZ_NTP_Clock_Ethernet.ino](examples/Ethernet/TZ_NTP_Clock_Ethernet/TZ_NTP_Clock_Ethernet.ino)

https://github.com/khoih-prog/Timezone_Generic/blob/89a32d8fa53577523b3826f08071fd4f546ab44a/examples/Ethernet/TZ_NTP_Clock_Ethernet/TZ_NTP_Clock_Ethernet.ino#L21-L434

---

#### 2. File [defines.h](examples/Ethernet/TZ_NTP_Clock_Ethernet/defines.h)

https://github.com/khoih-prog/Timezone_Generic/blob/89a32d8fa53577523b3826f08071fd4f546ab44a/examples/Ethernet/TZ_NTP_Clock_Ethernet/defines.h#L10-L475

---
---

### Debug Terminal Output Samples

### 1. TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with ENC28J60

The following is debug terminal output when running example [**TZ_NTP_WorldClock_Ethernet**](examples/Ethernet/TZ_NTP_WorldClock_Ethernet) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library

```
Start TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with ENC28J60 using EthernetENC Library
Timezone_Generic v1.10.1
[EWS] =========================
[EWS] Default SPI pinout:
[EWS] MOSI: 25
[EWS] MISO: 24
[EWS] SCK: 26
[EWS] SS: 5
[EWS] =========================
[EWS] Board : NRF52840_FEATHER , setCsPin: 10
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
Seconds since Jan 1 1900 = 3858290300
Unix time = 1649301500
The UTC time is 3:18:20

13:18:20 Thu 07 Apr 2022 AEST Sydney
06:18:20 Thu 07 Apr 2022 MSK  Moscow
05:18:20 Thu 07 Apr 2022 CEST Paris
04:18:20 Thu 07 Apr 2022 BST  London
03:18:20 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:20 Wed 06 Apr 2022 EDT  New York
22:18:20 Wed 06 Apr 2022 CDT  Chicago
21:18:20 Wed 06 Apr 2022 MDT  Denver
20:18:20 Wed 06 Apr 2022 MST  Phoenix
20:18:20 Wed 06 Apr 2022 PDT  Los Angeles

13:18:30 Thu 07 Apr 2022 AEST Sydney
06:18:30 Thu 07 Apr 2022 MSK  Moscow
05:18:30 Thu 07 Apr 2022 CEST Paris
04:18:30 Thu 07 Apr 2022 BST  London
03:18:30 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:30 Wed 06 Apr 2022 EDT  New York
22:18:30 Wed 06 Apr 2022 CDT  Chicago
21:18:30 Wed 06 Apr 2022 MDT  Denver
20:18:30 Wed 06 Apr 2022 MST  Phoenix
20:18:30 Wed 06 Apr 2022 PDT  Los Angeles
```

---

### 2. TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with W5500

The following is debug terminal output when running example [**TZ_NTP_WorldClock_Ethernet**](examples/Ethernet/TZ_NTP_WorldClock_Ethernet) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet_Generic Library

```
Start TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with W5x00 using Ethernet_Generic Library
Timezone_Generic v1.10.1
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 25
[EWS] MISO: 24
[EWS] SCK: 26
[EWS] SS: 5
[EWS] =========================
[EWS] Board : NRF52840_FEATHER , setCsPin: 10
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
Seconds since Jan 1 1900 = 3858290300
Unix time = 1649301500
The UTC time is 3:18:20

13:18:20 Thu 07 Apr 2022 AEST Sydney
06:18:20 Thu 07 Apr 2022 MSK  Moscow
05:18:20 Thu 07 Apr 2022 CEST Paris
04:18:20 Thu 07 Apr 2022 BST  London
03:18:20 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:20 Wed 06 Apr 2022 EDT  New York
22:18:20 Wed 06 Apr 2022 CDT  Chicago
21:18:20 Wed 06 Apr 2022 MDT  Denver
20:18:20 Wed 06 Apr 2022 MST  Phoenix
20:18:20 Wed 06 Apr 2022 PDT  Los Angeles

13:18:30 Thu 07 Apr 2022 AEST Sydney
06:18:30 Thu 07 Apr 2022 MSK  Moscow
05:18:30 Thu 07 Apr 2022 CEST Paris
04:18:30 Thu 07 Apr 2022 BST  London
03:18:30 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:30 Wed 06 Apr 2022 EDT  New York
22:18:30 Wed 06 Apr 2022 CDT  Chicago
21:18:30 Wed 06 Apr 2022 MDT  Denver
20:18:30 Wed 06 Apr 2022 MST  Phoenix
20:18:30 Wed 06 Apr 2022 PDT  Los Angeles
```

---

### 3. TZ_NTP_WorldClock_WiFiNINA on SAMD_NANO_33_IOT with WiFiNINA

The following is debug terminal output when running example [**TZ_NTP_WorldClock_WiFiNINA**](examples/WiFiNINA/TZ_NTP_WorldClock_WiFiNINA) on Arduino SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

```
Starting TZ_NTP_WorldClock_WiFiNINA on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
Timezone_Generic v1.10.1
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.128
Listening on port 2390

Packet received
Seconds since Jan 1 1900 = 3858290300
Unix time = 1649301500
The UTC time is 3:18:20

13:18:20 Thu 07 Apr 2022 AEST Sydney
06:18:20 Thu 07 Apr 2022 MSK  Moscow
05:18:20 Thu 07 Apr 2022 CEST Paris
04:18:20 Thu 07 Apr 2022 BST  London
03:18:20 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:20 Wed 06 Apr 2022 EDT  New York
22:18:20 Wed 06 Apr 2022 CDT  Chicago
21:18:20 Wed 06 Apr 2022 MDT  Denver
20:18:20 Wed 06 Apr 2022 MST  Phoenix
20:18:20 Wed 06 Apr 2022 PDT  Los Angeles

13:18:30 Thu 07 Apr 2022 AEST Sydney
06:18:30 Thu 07 Apr 2022 MSK  Moscow
05:18:30 Thu 07 Apr 2022 CEST Paris
04:18:30 Thu 07 Apr 2022 BST  London
03:18:30 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:30 Wed 06 Apr 2022 EDT  New York
22:18:30 Wed 06 Apr 2022 CDT  Chicago
21:18:30 Wed 06 Apr 2022 MDT  Denver
20:18:30 Wed 06 Apr 2022 MST  Phoenix
20:18:30 Wed 06 Apr 2022 PDT  Los Angeles
```

---

### 4. RTC_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with W5500

The following is debug terminal output when running example [**RTC_STM32_Ethernet**](examples/Ethernet/RTC_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with W5500 using Ethernet_Generic Library

```
Start RTC_STM32_Ethernet on NUCLEO_F767ZI, using W5x00 & Ethernet_Generic Library
Timezone_Generic v1.10.1
DS323x_Generic v1.3.1
[EWS] Board : NUCLEO_F767ZI , setCsPin: 10
[EWS] Default SPI pinout:
[EWS] MOSI: 11
[EWS] MISO: 12
[EWS] SCK: 13
[EWS] SS: 10
[EWS] =========================
You're connected to the network, IP = 192.168.2.117

Packet received
Seconds since Jan 1 1900 = 3858289514
Unix time = 1649300714
The UTC time is 3:05:14


03:05:14 Thu 07 Apr 2022 UTC
23:05:14 Wed 06 Apr 2022 EDT

03:05:23 Thu 07 Apr 2022 UTC
23:05:23 Wed 06 Apr 2022 EDT

03:05:33 Thu 07 Apr 2022 UTC
23:05:33 Wed 06 Apr 2022 EDT
```

---

### 5. RTC_Ethernet on Arduino SAM DUE with W5100

The following is debug terminal output when running example [**RTC_Ethernet**](examples/Ethernet/RTC_Ethernet) on Arduino SAM DUE with W5100 using Ethernet_Generic Library

```
Start RTC_Ethernet on SAM DUE with W5x00 using Ethernet_Generic Library
Timezone_Generic v1.10.1
DS323x_Generic v1.3.1
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 75
[EWS] MISO: 74
[EWS] SCK: 76
[EWS] SS: 10
[EWS] =========================
[EWS] Board : SAM DUE , setCsPin: 10
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

03:06:43 Thu 07 Apr 2022 UTC
23:06:43 Wed 06 Apr 2022 EDT

03:06:53 Thu 07 Apr 2022 UTC
23:06:53 Wed 06 Apr 2022 EDT
```

---

### 6. RTC_Ethernet on Adafruit NRF52840_FEATHER with W5500

The following is debug terminal output when running example [**RTC_Ethernet**](examples/Ethernet/RTC_Ethernet) on Adafruit NRF52840_FEATHER with W5500 using Ethernet_Generic Library

```
Start RTC_Ethernet on NRF52840_FEATHER with W5x00 using Ethernet_Generic Library
Timezone_Generic v1.10.1
DS323x_Generic v1.3.1
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 25
[EWS] MISO: 24
[EWS] SCK: 26
[EWS] SS: 5
[EWS] =========================
[EWS] Board : NRF52840_FEATHER , setCsPin: 10
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
Seconds since Jan 1 1900 = 3858289514
Unix time = 1649300714
The UTC time is 3:05:14

03:05:14 Thu 07 Apr 2022 UTC
23:05:14 Wed 06 Apr 2022 EDT

03:05:23 Thu 07 Apr 2022 UTC
23:05:23 Wed 06 Apr 2022 EDT

03:05:33 Thu 07 Apr 2022 UTC
23:05:33 Wed 06 Apr 2022 EDT
```

---

### 7. tzTest on Adafruit NRF52840_FEATHER

The following is debug terminal output when running example [**tzTest**](examples/tzTest) on NRF52840_FEATHER

```
Starting TZTest on NRF52840_FEATHER
Timezone_Generic v1.10.1
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
Timezone_Generic v1.10.1
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
Timezone_Generic v1.10.1
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
Timezone_Generic v1.10.1
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
Timezone_Generic v1.10.1
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
Timezone_Generic v1.10.1
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
Timezone_Generic v1.10.1
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
Timezone_Generic v1.10.1
[EWS] Board : NUCLEO_F767ZI , setCsPin: 10
[EWS] Default SPI pinout:
[EWS] MOSI: 11
[EWS] MISO: 12
[EWS] SCK: 13
[EWS] SS: 10
[EWS] =========================
You're connected to the network, IP = 192.168.2.97
Packet received
Seconds since Jan 1 1900 = 3858289514
Unix time = 1649300714

Updating Time for STM32 RTC
The UTC time is 3:05:14
============================
03:05:14 Thu 07 Apr 2022 UTC
23:05:14 Wed 06 Apr 2022 EDT
============================
03:05:23 Thu 07 Apr 2022 UTC
23:05:23 Wed 06 Apr 2022 EDT
============================
03:05:33 Thu 07 Apr 2022 UTC
23:05:33 Wed 06 Apr 2022 EDT
============================
```


---

### 15. BI_RTC_Alarm_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A

The following is debug terminal output when running example [**BI_RTC_Alarm_STM32_Ethernet**](examples/Ethernet/BI_RTC_Alarm_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library to demonstrate the usage of STM32 built-in RTC Alarm function

```
Start BI_RTC_Alarm_STM32_Ethernet on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
Timezone_Generic v1.10.1
[EWS] Board : NUCLEO_F767ZI , setCsPin: 10
[EWS] Default SPI pinout:
[EWS] MOSI: 11
[EWS] MISO: 12
[EWS] SCK: 13
[EWS] SS: 10
[EWS] =========================
You're connected to the network, IP = 192.168.2.96
Packet received
Seconds since Jan 1 1900 = 3812900198
Unix time = 1603911398

Updating Time for STM32 RTC
=======RTC ALARM SET========
18:57:08 Wed 01 Dec 2021 UTC
14:57:08 Wed 01 Dec 2021 EDT
============================
The UTC time is 18:56:38
============================
18:56:38 Wed 01 Dec 2021 UTC
14:56:38 Wed 01 Dec 2021 EDT
============================
18:56:47 Wed 01 Dec 2021 UTC
14:56:47 Wed 01 Dec 2021 EDT
============================
18:56:56 Wed 01 Dec 2021 UTC
14:56:56 Wed 01 Dec 2021 EDT
============================
18:57:05 Wed 01 Dec 2021 UTC
14:57:05 Wed 01 Dec 2021 EDT
*****RTC ALARM ACTIVATED*****
*****RTC ALARM ACTIVATED*****
============================
18:57:15 Wed 01 Dec 2021 UTC
14:57:15 Wed 01 Dec 2021 EDT
```

---

### 16. TZ_NTP_WorldClock_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA

The following is debug terminal output when running example [**TZ_NTP_WorldClock_WiFiNINA**](examples/WiFiNINA/TZ_NTP_WorldClock_WiFiNINA) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

```
Start TZ_NTP_WorldClock_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
Timezone_Generic v1.10.1
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.153
Listening on port 2390

Packet received
Seconds since Jan 1 1900 = 3858290300
Unix time = 1649301500
The UTC time is 3:18:20

13:18:20 Thu 07 Apr 2022 AEST Sydney
06:18:20 Thu 07 Apr 2022 MSK  Moscow
05:18:20 Thu 07 Apr 2022 CEST Paris
04:18:20 Thu 07 Apr 2022 BST  London
03:18:20 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:20 Wed 06 Apr 2022 EDT  New York
22:18:20 Wed 06 Apr 2022 CDT  Chicago
21:18:20 Wed 06 Apr 2022 MDT  Denver
20:18:20 Wed 06 Apr 2022 MST  Phoenix
20:18:20 Wed 06 Apr 2022 PDT  Los Angeles

13:18:30 Thu 07 Apr 2022 AEST Sydney
06:18:30 Thu 07 Apr 2022 MSK  Moscow
05:18:30 Thu 07 Apr 2022 CEST Paris
04:18:30 Thu 07 Apr 2022 BST  London
03:18:30 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:30 Wed 06 Apr 2022 EDT  New York
22:18:30 Wed 06 Apr 2022 CDT  Chicago
21:18:30 Wed 06 Apr 2022 MDT  Denver
20:18:30 Wed 06 Apr 2022 MST  Phoenix
20:18:30 Wed 06 Apr 2022 PDT  Los Angeles
```

---

### 17. TZ_NTP_WorldClock_Ethernet on MBED RASPBERRY_PI_PICO with W5x00

The following is debug terminal output when running example [**TZ_NTP_WorldClock_Ethernet**](examples/Ethernet/TZ_NTP_WorldClock_Ethernet) on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library

```
Start TZ_NTP_WorldClock_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library
Timezone_Generic v1.10.1
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] RPIPICO setCsPin: 17
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 8
You're connected to the network, IP = 192.168.2.99

Packet received
Seconds since Jan 1 1900 = 3858290300
Unix time = 1649301500
The UTC time is 3:18:20

13:18:20 Thu 07 Apr 2022 AEST Sydney
06:18:20 Thu 07 Apr 2022 MSK  Moscow
05:18:20 Thu 07 Apr 2022 CEST Paris
04:18:20 Thu 07 Apr 2022 BST  London
03:18:20 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:20 Wed 06 Apr 2022 EDT  New York
22:18:20 Wed 06 Apr 2022 CDT  Chicago
21:18:20 Wed 06 Apr 2022 MDT  Denver
20:18:20 Wed 06 Apr 2022 MST  Phoenix
20:18:20 Wed 06 Apr 2022 PDT  Los Angeles
```

---

### 18. TZ_NTP_WorldClock_Ethernet on RASPBERRY_PI_PICO with W5x00

The following is debug terminal output when running example [**TZ_NTP_WorldClock_Ethernet**](examples/Ethernet/TZ_NTP_WorldClock_Ethernet) on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library


```
Start TZ_NTP_WorldClock_Ethernet on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library
Timezone_Generic v1.10.1
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] RPIPICO setCsPin: 17
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
Seconds since Jan 1 1900 = 3858290300
Unix time = 1649301500
The UTC time is 3:18:20

13:18:20 Thu 07 Apr 2022 AEST Sydney
06:18:20 Thu 07 Apr 2022 MSK  Moscow
05:18:20 Thu 07 Apr 2022 CEST Paris
04:18:20 Thu 07 Apr 2022 BST  London
03:18:20 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:20 Wed 06 Apr 2022 EDT  New York
22:18:20 Wed 06 Apr 2022 CDT  Chicago
21:18:20 Wed 06 Apr 2022 MDT  Denver
20:18:20 Wed 06 Apr 2022 MST  Phoenix
20:18:20 Wed 06 Apr 2022 PDT  Los Angeles
```

---

### 19. TZ_NTP_WorldClock_WT32_ETH01 on WT32-ETH01 with ETH_PHY_LAN8720

The following is debug terminal output when running example [**TZ_NTP_WorldClock_WT32_ETH01**](examples/WT32-ETH01/TZ_NTP_WorldClock_WT32_ETH01) on WT32-ETH01 with ETH_PHY_LAN8720


```
Start TZ_NTP_WorldClock_WT32_ETH01 on WT32-ETH01 with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.5.1
Timezone_Generic v1.10.1
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232
FULL_DUPLEX, 100Mbps
TZ_NTP_WorldClock_WT32_ETH01 started @ IP address: 192.168.2.232
Listening on port 2390

Packet received
Seconds since Jan 1 1900 = 3858290300
Unix time = 1649301500
The UTC time is 3:18:20

13:18:20 Thu 07 Apr 2022 AEST Sydney
06:18:20 Thu 07 Apr 2022 MSK  Moscow
05:18:20 Thu 07 Apr 2022 CEST Paris
04:18:20 Thu 07 Apr 2022 BST  London
03:18:20 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:20 Wed 06 Apr 2022 EDT  New York
22:18:20 Wed 06 Apr 2022 CDT  Chicago
21:18:20 Wed 06 Apr 2022 MDT  Denver
20:18:20 Wed 06 Apr 2022 MST  Phoenix
20:18:20 Wed 06 Apr 2022 PDT  Los Angeles
```

---

### 20. TZ_NTP_WorldClock_RTL8720DN on Rtlduino RTL8720DN

The following is debug terminal output when running example [**TZ_NTP_WorldClock_RTL8720DN**](examples/RTL8720DN/TZ_NTP_WorldClock_RTL8720DN) on Rtlduino RTL8720DN


```
Start TZ_NTP_WorldClock_RTL8720DN on Rtlduino RTL8720DN
WiFiWebServer_RTL8720 v1.1.2
Timezone_Generic v1.10.1
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet_5G
TZ_NTP_Clock_RTL8720DN started @ IP address: 192.168.2.111
Listening on port 2390

Packet received
Seconds since Jan 1 1900 = 3858290300
Unix time = 1649301500
The UTC time is 3:18:20

13:18:20 Thu 07 Apr 2022 AEST Sydney
06:18:20 Thu 07 Apr 2022 MSK  Moscow
05:18:20 Thu 07 Apr 2022 CEST Paris
04:18:20 Thu 07 Apr 2022 BST  London
03:18:20 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:20 Wed 06 Apr 2022 EDT  New York
22:18:20 Wed 06 Apr 2022 CDT  Chicago
21:18:20 Wed 06 Apr 2022 MDT  Denver
20:18:20 Wed 06 Apr 2022 MST  Phoenix
20:18:20 Wed 06 Apr 2022 PDT  Los Angeles
```

---

### 21. TZ_NTP_Clock_Ethernet on PORTENTA_H7_M7

The following is debug terminal output when running example [**TZ_NTP_Clock_Ethernet**](examples/Ethernet/TZ_NTP_Clock_Ethernet) on PORTENTA_H7_M7 using Portenta_Ethernet Library


```
Start TZ_NTP_Clock_Ethernet on PORTENTA_H7_M7 with Ethernet 
Timezone_Generic v1.10.1
[EWS] ======== USE_PORTENTA_H7_ETHERNET ========
=========================
Currently Used SPI pinout:
MOSI:8
MISO:10
SCK:9
SS:7
=========================
Using mac index = 7
You're connected to the network, IP = 192.168.2.106
[TZ] LittleFS Mount OK
Packet received
Seconds since Jan 1 1900 = 3858288516
Unix time = 1649299716
The UTC time is 2:48:36

02:48:36 Thu 07 Apr 2022 UTC
22:48:36 Wed 06 Apr 2022 EDT

02:48:45 Thu 07 Apr 2022 UTC
22:48:45 Wed 06 Apr 2022 EDT

02:48:55 Thu 07 Apr 2022 UTC
22:48:55 Wed 06 Apr 2022 EDT
```

---

### 22. TZ_NTP_WorldClock_WiFi on PORTENTA_H7_M7

The following is debug terminal output when running example [**TZ_NTP_WorldClock_WiFi**](examples/Portenta_H7_WiFi/TZ_NTP_WorldClock_WiFi) on PORTENTA_H7_M7 using WiFi


```
Start TZ_NTP_WorldClock_WiFi on PORTENTA_H7_M7
Timezone_Generic v1.10.1
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.105
Listening on port 2390
Packet received
Seconds since Jan 1 1900 = 3858290300
Unix time = 1649301500
The UTC time is 3:18:20

13:18:20 Thu 07 Apr 2022 AEST Sydney
06:18:20 Thu 07 Apr 2022 MSK  Moscow
05:18:20 Thu 07 Apr 2022 CEST Paris
04:18:20 Thu 07 Apr 2022 BST  London
03:18:20 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:20 Wed 06 Apr 2022 EDT  New York
22:18:20 Wed 06 Apr 2022 CDT  Chicago
21:18:20 Wed 06 Apr 2022 MDT  Denver
20:18:20 Wed 06 Apr 2022 MST  Phoenix
20:18:20 Wed 06 Apr 2022 PDT  Los Angeles

13:18:30 Thu 07 Apr 2022 AEST Sydney
06:18:30 Thu 07 Apr 2022 MSK  Moscow
05:18:30 Thu 07 Apr 2022 CEST Paris
04:18:30 Thu 07 Apr 2022 BST  London
03:18:30 Thu 07 Apr 2022 UTC  Universal Coordinated Time
23:18:30 Wed 06 Apr 2022 EDT  New York
22:18:30 Wed 06 Apr 2022 CDT  Chicago
21:18:30 Wed 06 Apr 2022 MDT  Denver
20:18:30 Wed 06 Apr 2022 MST  Phoenix
20:18:30 Wed 06 Apr 2022 PDT  Los Angeles
```

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
 4. Add support to **Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc. and LittleFS**.
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
16. Add support to ESP32-S2 (using SPIFFS or LittleFS) and ESP32-C3 boards (using SPIFFS)
17. Add support to **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet
18. Add support to **RTL8720DN, RTL8722DM, RTL8722CSM, etc.** boards
19. Fix `multiple-definitions` linker error and weird bug related to `src_cpp`.
20. Optimize library code by using `reference-passing` instead of `value-passing`
21. Update to be compatible with new `FlashStorage_SAMD`
22. Use better `FlashStorage_STM32` or `FlashStorage_STM32F1` library for STM32
23. Add support to generic SAMD21 boards : `__SAMD21E1xA__`, `__SAMD21G1xA__` and `__SAMD21J1xA__`
24. Add support to Portenta_H7 Ethernet and WiFi
25. Use [Ethernet_Generic](https://github.com/khoih-prog/Ethernet_Generic) library as default for W5x00 Ethernet.
26. Add support to `RP2040W` using `CYW43439 WiFi` with `arduino-pico` core


---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Based on and modified from the [**Jack Christensen's Timezone Library**](https://github.com/JChristensen/Timezone).
2. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing.
3. Thanks to **6v6gt** to contribute the new feature to allow un-initialized TZ. Check [**Timezone_Generic Library to convert UTC to local time**](https://forum.arduino.cc/index.php?topic=711259).
4. Thanks to [Maximilian Gerhardt](https://github.com/maxgerhardt) to create bug report [RP2040_RTC_Time crashes Pico, does not work #3](https://github.com/khoih-prog/RP2040_RTC/issues/3) and help investigate and fix the bug, leading to v1.7.2



<table>
  <tr>
    <td align="center"><a href="https://github.com/JChristensen"><img src="https://github.com/JChristensen.png" width="100px;" alt="JChristensen"/><br /><sub><b>⭐️ Jack Christensen</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b> Miguel Wisintainer</b></sub></a><br /></td>
    <td align="center"><a href="https://forum.arduino.cc/index.php?action=profile;u=454553"><img src="https://dcw9y8se13llu.cloudfront.net/avatars/6v6gt.jpg" width="100px;" alt="6v6gt"/><br /><sub><b> 6v6gt</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/maxgerhardt"><img src="https://github.com/maxgerhardt.png" width="100px;" alt="maxgerhardt"/><br /><sub><b>Maximilian Gerhardt</b></sub></a><br /></td>
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


