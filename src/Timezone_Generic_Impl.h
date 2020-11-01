/****************************************************************************************************************************
  Timezone_Generic_Impl.h
  
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

#define TIMEZONE_GENERIC_VERSION "1.2.5"

#define  TZ_FILENAME      "/timezone.dat"
#define  TZ_DATA_OFFSET   0

#define TZ_USE_EEPROM      true

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
  #if defined(TZ_USE_SAM_DUE)
    #undef TZ_USE_SAM_DUE
  #endif
  #define TZ_USE_SAM_DUE     true
  
  #if defined(TZ_USE_EEPROM)
    #undef TZ_USE_EEPROM
  #endif
  #define TZ_USE_EEPROM    false
  
  #warning Use SAM-DUE and DueFlashStorage
  
#elif ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )
  #if defined(TZ_USE_SAMD)
    #undef TZ_USE_SAMD
  #endif
  #define TZ_USE_SAMD      true
  
  #if defined(TZ_USE_EEPROM)
    #undef TZ_USE_EEPROM
  #endif
  #define TZ_USE_EEPROM    false
  
  #warning Use SAMD and FlashStorage
  
#elif ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
        defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
        defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )   

  #if defined(TZ_USE_NRF52)
    #undef TZ_USE_NRF52
  #endif
  #define TZ_USE_NRF52      true
  
  #if defined(TZ_USE_EEPROM)
    #undef TZ_USE_EEPROM
  #endif
  #define TZ_USE_EEPROM    false
  
  #warning Use NRF52 and LittleFS / InternalFS

#elif ( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )

  #if defined(TZ_USE_STM32)
    #undef TZ_USE_STM32
  #endif
  #define TZ_USE_STM32      true
  
  #if defined(TZ_USE_EEPROM)
    #undef TZ_USE_EEPROM
  #endif
  #define TZ_USE_EEPROM    true
  
  #warning Use STM32 and EEPROM
         
#else
  #if defined(CORE_TEENSY)
    #define TZ_USE_EENSY      true
    #warning Use TEENSY and EEPROM
    
  #elif ( defined(ARDUINO_AVR_ADK) || defined(ARDUINO_AVR_BT) || defined(ARDUINO_AVR_DUEMILANOVE) || defined(ARDUINO_AVR_ESPLORA) \
      || defined(ARDUINO_AVR_ETHERNET) || defined(ARDUINO_AVR_FIO) || defined(ARDUINO_AVR_GEMMA) || defined(ARDUINO_AVR_LEONARDO) \
      || defined(ARDUINO_AVR_LILYPAD) || defined(ARDUINO_AVR_LILYPAD_USB) || defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) \
      || defined(ARDUINO_AVR_MICRO) || defined(ARDUINO_AVR_MINI) || defined(ARDUINO_AVR_NANO) || defined(ARDUINO_AVR_NG) \
      || defined(ARDUINO_AVR_PRO) || defined(ARDUINO_AVR_ROBOT_CONTROL) || defined(ARDUINO_AVR_ROBOT_MOTOR) || defined(ARDUINO_AVR_UNO) \
      || defined(ARDUINO_AVR_YUN) || defined(__AVR__) )        
    #warning Use AVR and EEPROM
    #define TZ_USE_AVR        true
    //#include <avr/eeprom.h>
    
  #else
    #warning Use Unknown board and EEPROM
  #endif  
#endif

//default to use EEPROM, otherwise, use DueFlashStorage or FlashStorage_SAMD
#if TZ_USE_EEPROM
  #include <EEPROM.h>

  #ifndef TZ_EEPROM_SIZE
    // Please change according to your application to avoid overwriting or being overwritten
    #define TZ_EEPROM_SIZE     (E2END + 1)
  #endif

#elif TZ_USE_SAMD
  // Include EEPROM-like API for FlashStorage
  #include <FlashAsEEPROM_SAMD.h>             //https://github.com/khoih-prog/FlashStorage_SAMD
#elif TZ_USE_SAM_DUE
  //Use DueFlashStorage to simulate EEPROM
  #include <DueFlashStorage.h>                 //https://github.com/sebnil/DueFlashStorage
  DueFlashStorage dueFlashStorage;
  
#elif TZ_USE_NRF52
  // Include LittleFS similar to SPIFFS
  #include <Adafruit_LittleFS.h>
  #include <InternalFileSystem.h>
  using namespace Adafruit_LittleFS_Namespace;
  
  File TZ_file(InternalFS);
  
#endif    //#if TZ_USE_EEPROM

#ifndef TZ_DEBUG
  #define TZ_DEBUG       false
#endif


/*----------------------------------------------------------------------*
   Create a Timezone object from the given time change rules.
  ----------------------------------------------------------------------*/
Timezone::Timezone(TimeChangeRule dstStart, TimeChangeRule stdStart)
  : m_dst(dstStart), m_std(stdStart), TZ_DATA_START(0)
{
  this->TZ_DATA_START = 0;
  
  initTimeChanges();
}

/*----------------------------------------------------------------------*
   Create a Timezone object for a zone that does not observe
   daylight time.
  ----------------------------------------------------------------------*/
Timezone::Timezone(TimeChangeRule stdTime)
  : m_dst(stdTime), m_std(stdTime), TZ_DATA_START(0)
{ 
  initTimeChanges();
}

//////

// Allow a "blank" TZ object then use begin() method to set the actual TZ.
// Feature added by 6v6gt (https://forum.arduino.cc/index.php?topic=711259)
/*----------------------------------------------------------------------*
   Create a Timezone object for later initialisation 6v6gt 31.10.2020
  ----------------------------------------------------------------------*/
Timezone::Timezone(void)
: TZ_DATA_START(0)
{
		initTimeChanges();
}

/*----------------------------------------------------------------------*
   initialise (used where void constructor is called)  6v6gt
  ----------------------------------------------------------------------*/
void Timezone::init(TimeChangeRule dstStart, TimeChangeRule stdStart)
{
  m_dst = dstStart;
  m_std = stdStart;
}

//////

/*----------------------------------------------------------------------*
   Create a Timezone object from time change rules stored in EEPROM
   at the given address.
  ----------------------------------------------------------------------*/
Timezone::Timezone(int address)
{
  this->TZ_DATA_START = address;
  
#if TZ_USE_EEPROM
  EEPROM.begin();

  TZ_LOGDEBUG3("Read from EEPROM, size = ", TZ_EEPROM_SIZE, ", offset = ", TZ_DATA_START);
  
#elif TZ_USE_SAMD
  // Do something to init FlashStorage
  
#elif TZ_USE_SAM_DUE
  // Do something to init DueFlashStorage

#elif TZ_USE_NRF52
  // Do something to init LittleFS / InternalFS
  // Initialize Internal File System
  InternalFS.begin();
#else
  #error Un-identifiable board selected. Please check your Tools->Board setting.
#endif

  storageSystemInit = true;

  readRules();
}

/*----------------------------------------------------------------------*
   Convert the given UTC time to local time, standard or
   daylight time, as appropriate.
  ----------------------------------------------------------------------*/
time_t Timezone::toLocal(time_t utc)
{
  // recalculate the time change points if needed
  if (year(utc) != year(m_dstUTC)) 
    calcTimeChanges(year(utc));

  if (utcIsDST(utc))
    return utc + m_dst.offset * SECS_PER_MIN;
  else
    return utc + m_std.offset * SECS_PER_MIN;
}

/*----------------------------------------------------------------------*
   Convert the given UTC time to local time, standard or
   daylight time, as appropriate, and return a pointer to the time
   change rule used to do the conversion. The caller must take care
   not to alter this rule.
  ----------------------------------------------------------------------*/
time_t Timezone::toLocal(time_t utc, TimeChangeRule **tcr)
{
  // recalculate the time change points if needed
  if (year(utc) != year(m_dstUTC)) 
    calcTimeChanges(year(utc));

  if (utcIsDST(utc)) 
  {
    *tcr = &m_dst;
    return utc + m_dst.offset * SECS_PER_MIN;
  }
  else 
  {
    *tcr = &m_std;
    return utc + m_std.offset * SECS_PER_MIN;
  }
}

/*----------------------------------------------------------------------*
   Convert the given local time to UTC time.
 *                                                                      *
   WARNING:
   This function is provided for completeness, but should seldom be
   needed and should be used sparingly and carefully.
 *                                                                      *
   Ambiguous situations occur after the Standard-to-DST and the
   DST-to-Standard time transitions. When changing to DST, there is
   one hour of local time that does not exist, since the clock moves
   forward one hour. Similarly, when changing to standard time, there
   is one hour of local times that occur twice since the clock moves
   back one hour.
 *                                                                      *
   This function does not test whether it is passed an erroneous time
   value during the Local -> DST transition that does not exist.
   If passed such a time, an incorrect UTC time value will be returned.
 *                                                                      *
   If passed a local time value during the DST -> Local transition
   that occurs twice, it will be treated as the earlier time, i.e.
   the time that occurs before the transistion.
 *                                                                      *
   Calling this function with local times during a transition interval
   should be avoided!
  ----------------------------------------------------------------------*/
time_t Timezone::toUTC(time_t local)
{
  // recalculate the time change points if needed
  if (year(local) != year(m_dstLoc)) 
    calcTimeChanges(year(local));

  if (locIsDST(local))
    return local - m_dst.offset * SECS_PER_MIN;
  else
    return local - m_std.offset * SECS_PER_MIN;
}

/*----------------------------------------------------------------------*
   Determine whether the given UTC time_t is within the DST interval
   or the Standard time interval.
  ----------------------------------------------------------------------*/
bool Timezone::utcIsDST(time_t utc)
{
  // recalculate the time change points if needed
  if (year(utc) != year(m_dstUTC)) 
    calcTimeChanges(year(utc));

  if (m_stdUTC == m_dstUTC)       // daylight time not observed in this tz
    return false;
  else if (m_stdUTC > m_dstUTC)   // northern hemisphere
    return (utc >= m_dstUTC && utc < m_stdUTC);
  else                            // southern hemisphere
    return !(utc >= m_stdUTC && utc < m_dstUTC);
}

/*----------------------------------------------------------------------*
   Determine whether the given Local time_t is within the DST interval
   or the Standard time interval.
  ----------------------------------------------------------------------*/
bool Timezone::locIsDST(time_t local)
{
  // recalculate the time change points if needed
  if (year(local) != year(m_dstLoc)) 
    calcTimeChanges(year(local));

  if (m_stdUTC == m_dstUTC)       // daylight time not observed in this tz
    return false;
  else if (m_stdLoc > m_dstLoc)   // northern hemisphere
    return (local >= m_dstLoc && local < m_stdLoc);
  else                            // southern hemisphere
    return !(local >= m_stdLoc && local < m_dstLoc);
}

/*----------------------------------------------------------------------*
   Calculate the DST and standard time change points for the given
   given year as local and UTC time_t values.
  ----------------------------------------------------------------------*/
void Timezone::calcTimeChanges(int yr)
{
  m_dstLoc = toTime_t(m_dst, yr);
  m_stdLoc = toTime_t(m_std, yr);
  m_dstUTC = m_dstLoc - m_std.offset * SECS_PER_MIN;
  m_stdUTC = m_stdLoc - m_dst.offset * SECS_PER_MIN;
}

/*----------------------------------------------------------------------*
   Initialize the DST and standard time change points.
  ----------------------------------------------------------------------*/
void Timezone::initTimeChanges()
{
  m_dstLoc = 0;
  m_stdLoc = 0;
  m_dstUTC = 0;
  m_stdUTC = 0;
}

/*----------------------------------------------------------------------*
   Convert the given time change rule to a time_t value
   for the given year.
  ----------------------------------------------------------------------*/
time_t Timezone::toTime_t(TimeChangeRule r, int yr)
{
  uint8_t m = r.month;     // temp copies of r.month and r.week
  uint8_t w = r.week;
  
  if (w == 0)              // is this a "Last week" rule?
  {
    if (++m > 12)        // yes, for "Last", go to the next month
    {
      m = 1;
      ++yr;
    }
    
    w = 1;               // and treat as first week of next month, subtract 7 days later
  }

  // calculate first day of the month, or for "Last" rules, first day of the next month
  tmElements_t tm;
  
  tm.Hour   = r.hour;
  tm.Minute = 0;
  tm.Second = 0;
  tm.Day    = 1;
  tm.Month  = m;
  tm.Year   = yr - 1970;
  time_t t  = makeTime(tm);

  // add offset from the first of the month to r.dow, and offset for the given week
  t += ( (r.dow - weekday(t) + 7) % 7 + (w - 1) * 7 ) * SECS_PER_DAY;
  
  // back up a week if this is a "Last" rule
  if (r.week == 0) 
    t -= 7 * SECS_PER_DAY;
    
  return t;
}

/*----------------------------------------------------------------------*
   Read or update the daylight and standard time rules from RAM.
  ----------------------------------------------------------------------*/
void Timezone::setRules(TimeChangeRule dstStart, TimeChangeRule stdStart)
{
  m_dst = dstStart;
  m_std = stdStart;
  initTimeChanges();  // force calcTimeChanges() at next conversion call
}

void Timezone::display_DST_Rule(void)
{
  TZ_LOGERROR("DST rule");
  TZ_LOGERROR3("abbrev :",  m_dst.abbrev, ", week :",   m_dst.week);
  TZ_LOGERROR3("dow :",     m_dst.dow,    ", month :",  m_dst.month);
  TZ_LOGERROR3("hour :",    m_dst.hour,   ", offset :", m_dst.offset);
}

void Timezone::display_STD_Rule(void)
{
  TZ_LOGERROR("DST rule");
  TZ_LOGERROR3("abbrev :",  m_std.abbrev, ", week :",   m_std.week);
  TZ_LOGERROR3("dow :",     m_std.dow,    ", month :",  m_std.month);
  TZ_LOGERROR3("hour :",    m_std.hour,   ", offset :", m_std.offset);
}


/*----------------------------------------------------------------------*
   Read the daylight and standard time rules from EEPROM/storage at
   the TZ_DATA_START offset.
  ----------------------------------------------------------------------*/
void Timezone::readRules()
{
  readTZData();
  initTimeChanges();  // force calcTimeChanges() at next conversion call
}

/*----------------------------------------------------------------------*
   Write the daylight and standard time rules to EEPROM/storage at
   the TZ_DATA_START offset.
  ----------------------------------------------------------------------*/
void Timezone::writeRules(int address)
{
  this->TZ_DATA_START = address;
  
  writeTZData(address);
  initTimeChanges();  // force calcTimeChanges() at next conversion call
}


#if (TZ_USE_SAMD)

  #warning Using SAMD FlashStorage in Timezone_Generic
  
  // SAMD code  
/*----------------------------------------------------------------------*
   Read the daylight and standard time rules from EEPROM at
   the given address.
  ----------------------------------------------------------------------*/
void Timezone::readTZData(void)
{
  if (!storageSystemInit)
  {
    storageSystemInit = true;
  }
  
  // It's too bad that emulate EEPROM.read()/write() can only deal with bytes. 
  // Have to read/write each byte. To rewrite the library
  
  memset(&m_dst, 0, TZ_DATA_SIZE);
  memset(&m_std, 0, TZ_DATA_SIZE);
  
  uint16_t offset   = TZ_DATA_START;               
  uint8_t* _pointer = (uint8_t *) &m_dst;

  for (int i = 0; i < TZ_DATA_SIZE; i++, _pointer++, offset++)
  {              
    *_pointer = EEPROM.read(offset);
  }
            
  _pointer = (uint8_t *) &m_std;

  for (int i = 0; i < TZ_DATA_SIZE; i++, _pointer++, offset++)
  {              
    *_pointer = EEPROM.read(offset);
  }

  return;  
}

/*----------------------------------------------------------------------*
   Write the daylight and standard time rules to EEPROM at
   the given address.
  ----------------------------------------------------------------------*/
void Timezone::writeTZData(int address)
{
  if (!storageSystemInit)
  {
    storageSystemInit = true;
  }
  
  // It's too bad that emulate EEPROM.read()/write() can only deal with bytes. 
  // Have to read/write each byte. To rewrite the library
  
  uint16_t offset   = address;               
  uint8_t* _pointer = (uint8_t *) &m_dst;

  for (int i = 0; i < TZ_DATA_SIZE; i++, _pointer++, offset++)
  {              
    EEPROM.write(offset, *_pointer);
  }
            
  _pointer = (uint8_t *) &m_std;

  for (int i = 0; i < TZ_DATA_SIZE; i++, _pointer++, offset++)
  {              
    EEPROM.write(offset, *_pointer);
  }

  return;  
}
         
#elif (TZ_USE_SAM_DUE)

  #warning Using SAM DUE dueFlashStorage in Timezone_Generic
  // SAM DUE code    
/*----------------------------------------------------------------------*
   Read the daylight and standard time rules from dueFlashStorage at
   the given offset.
  ----------------------------------------------------------------------*/
void Timezone::readTZData(void)
{
  if (!storageSystemInit)
  {
    storageSystemInit = true;
  }
  
  memset(&m_dst, 0, TZ_DATA_SIZE);
  memset(&m_std, 0, TZ_DATA_SIZE);
  
  // SAM DUE code
  byte* dataPointer = (byte* ) dueFlashStorage.readAddress(TZ_DATA_START);

  memcpy(&m_dst, dataPointer, TZ_DATA_SIZE); 
  
  dataPointer += TZ_DATA_SIZE;
  
  memcpy(&m_std, dataPointer, TZ_DATA_SIZE); 
  
  TZ_LOGDEBUG("Reading from dueFlashStorage OK");
}

/*----------------------------------------------------------------------*
   Write the daylight and standard time rules to dueFlashStorage at
   the given offset.
  ----------------------------------------------------------------------*/
void Timezone::writeTZData(int address)
{ 
  if (!storageSystemInit)
  {
    storageSystemInit = true;
  }
  
  // SAM DUE code     
  dueFlashStorage.write(TZ_DATA_START, (byte *) &m_dst, TZ_DATA_SIZE);
  dueFlashStorage.write(TZ_DATA_START + TZ_DATA_SIZE, (byte *) &m_std, TZ_DATA_SIZE);
  
  TZ_LOGDEBUG("Writing to dueFlashStorage OK");
}
      
#elif (TZ_USE_NRF52)

  #warning Using NRF52 LittleFS in Timezone_Generic
  
  // nRF52 code    
/*----------------------------------------------------------------------*
   Read the daylight and standard time rules from LittleFS at
   the given offset.
  ----------------------------------------------------------------------*/
void Timezone::readTZData(void)
{
  if (!storageSystemInit)
  {
    InternalFS.begin();
    storageSystemInit = true;
  }
  
  // nRF52 code
  TZ_file.open(TZ_FILENAME, FILE_O_READ);
  
  TZ_LOGDEBUG3("Reading m_dst & m_std from TZ_file :", TZ_FILENAME, ", data offset =", TZ_DATA_OFFSET);

  if (TZ_file)
  {
    memset(&m_dst, 0, TZ_DATA_SIZE);
    memset(&m_std, 0, TZ_DATA_SIZE);
    
    TZ_file.seek(TZ_DATA_OFFSET);
    
    TZ_file.read((char *) &m_dst, TZ_DATA_SIZE);
    // Seek to be sure
    TZ_file.seek(TZ_DATA_OFFSET + TZ_DATA_SIZE);
    TZ_file.read((char *) &m_std, TZ_DATA_SIZE);

    TZ_LOGDEBUG("Reading from TZ_file OK");

    TZ_file.close(); 
  }
  else
  {
    TZ_LOGDEBUG("Reading from TZ_file failed");
  }
}

/*----------------------------------------------------------------------*
   Write the daylight and standard time rules to LittleFS at
   the given offset.
  ----------------------------------------------------------------------*/
void Timezone::writeTZData(int address)
{ 
  if (!storageSystemInit)
  {
    InternalFS.begin();
    storageSystemInit = true;
  }
  
  // nRF52 code
  TZ_file.open(TZ_FILENAME, FILE_O_WRITE);

  TZ_LOGDEBUG3("Saving m_dst & m_std to TZ_file :", TZ_FILENAME, ", data offset =", TZ_DATA_OFFSET);

  if (TZ_file)
  {
    TZ_file.seek(TZ_DATA_OFFSET);
    TZ_file.write((uint8_t *) &m_dst, TZ_DATA_SIZE);
    // Seek to be sure
    TZ_file.seek(TZ_DATA_OFFSET + TZ_DATA_SIZE);
    TZ_file.write((uint8_t *) &m_std, TZ_DATA_SIZE);
    
    TZ_file.close();

    TZ_LOGDEBUG("Saving to TZ_file OK");
  }
  else
  {
    TZ_LOGDEBUG("Saving to TZ_file failed");
  }   
}

#elif (TZ_USE_STM32)

  #warning Using STM32 EEPROM in Timezone_Generic

  // STM32 code    
/*----------------------------------------------------------------------*
   Read the daylight and standard time rules from EEPROM at
   the given address.
  ----------------------------------------------------------------------*/
void Timezone::readTZData(void)
{ 
  if (!storageSystemInit)
  {
    storageSystemInit = true;
  }
  
  TZ_LOGDEBUG3("Read from EEPROM, size = ", TZ_EEPROM_SIZE, ", offset = ", TZ_DATA_START);
  
  memset(&m_dst, 0, TZ_DATA_SIZE);
  memset(&m_std, 0, TZ_DATA_SIZE);
  
  EEPROM.get(TZ_DATA_START, m_dst);
  EEPROM.get(TZ_DATA_START + TZ_DATA_SIZE, m_std);
}

/*----------------------------------------------------------------------*
   Write the daylight and standard time rules to EEPROM at
   the given address.
  ----------------------------------------------------------------------*/
void Timezone::writeTZData(int address)
{
  if (!storageSystemInit)
  {
    EEPROM.begin();
    storageSystemInit = true;
  }
  
  TZ_LOGDEBUG3("Write to EEPROM, size = ", TZ_EEPROM_SIZE, ", offset = ", TZ_DATA_START);
   
  EEPROM.put(TZ_DATA_START, m_dst);
  EEPROM.put(TZ_DATA_START + TZ_DATA_SIZE, m_std);
  //EEPROM.commit();
}
        
#elif TZ_USE_EEPROM
/*----------------------------------------------------------------------*
   Read the daylight and standard time rules from EEPROM at
   the given address.
  ----------------------------------------------------------------------*/
void Timezone::readTZData(void)
{
  uint16_t address = TZ_DATA_START;
  
  if (!storageSystemInit)
  {
    EEPROM.begin();
    storageSystemInit = true;
  }
  
  TZ_LOGDEBUG3("Read from EEPROM, size = ", TZ_EEPROM_SIZE, ", offset = ", TZ_DATA_START);
  
  memset(&m_dst, 0, TZ_DATA_SIZE);
  memset(&m_std, 0, TZ_DATA_SIZE);
    
  EEPROM.get(TZ_DATA_START, m_dst);
  EEPROM.get(TZ_DATA_START + TZ_DATA_SIZE, m_std);
}

/*----------------------------------------------------------------------*
   Write the daylight and standard time rules to EEPROM at
   the given address.
  ----------------------------------------------------------------------*/
void Timezone::writeTZData(int address)
{
  if (!storageSystemInit)
  {
    EEPROM.begin();
    storageSystemInit = true;
  }
  
  TZ_LOGDEBUG3("Write to EEPROM, size = ", TZ_EEPROM_SIZE, ", offset = ", TZ_DATA_START);
   
  EEPROM.put(TZ_DATA_START, m_dst);
  EEPROM.put(TZ_DATA_START + TZ_DATA_SIZE, m_std);
  //EEPROM.commit();
}
        
#endif
