/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: RTC.ino
*  @Description: This file contains the code relating to the Real Time Clock of ESP32
*/

#include <RTClib.h>

// #define Serial Serial0

/* Create an rtc object */
RTC_DS3231 rtc;

/* Dummy time */
const byte seconds = 0;
const byte minutes = 0;
const byte hours = 16;

/* Dummy date */
const byte day = 15;
const byte month = 6;
const byte year = 2015;

/*
* You up the RTC clock to a specific time and date  
* You can also set it with compile time and date
* @return true if the clock is set up properly else false
*/
bool set_up_RTC(){
  // rtc.begin(F(__DATE__), F(__TIME__))); // initialize RTC
  
  // rtc.adjust(DateTime(year, month, day, hours, minutes, sseconds));
  return true;
}

/*
* Prints the current time in the RTC
*/
void printTime(){
  // Serial.begin(115200);
  DateTime now = rtc.now();
  // Print date...
  Serial.print(now.day());
  Serial.print("/");
  Serial.print(now.month());
  Serial.print("/");
  Serial.print(now.year());
  Serial.print(" ");

  // ...and time
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.print(now.second());

  Serial.println();
}

/*
* Stores the various time variables in the internal storage
*/
void rememberTime(){
  DateTime now = rtc.now();
  preferences.putUInt("day", now.day());
  preferences.putUInt("month", now.month());
  preferences.putUInt("year", now.year());

  preferences.putUInt("hour", now.hour());
  preferences.putUInt("minute", now.minute());
  preferences.putUInt("second", now.second());
}