/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: Storage.ino
*  @Description: This file contains the code relating to the persistent storage of ESP32
*/

#include <Preferences.h>

Preferences preferences;

/*
* Sets up the internal storage system
* @return true if the storage is set up properly else false
*/
bool set_up_storage(){
  preferences.begin("general", false); 
  return true;
}

/*
* Dummy example to show storing value in internal storage
*/
void set_count(){
  preferences.putULong("count", 0);
}

/*
* Dummy example to show changing value in internal storage
*/
void increase_count(){
  preferences.putULong("count", preferences.getUlong("count", 0));
}

/*
* Clears the internal storage system
* @return true if the storage is cleared properly else false
*/
bool clear_storage(){
  preferences.clear();
  preferences.end();
  return true;
}