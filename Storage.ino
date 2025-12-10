/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: Storage.ino
*  @Description: This file contains the code relating to the persistent storage of ESP32
*/

#include <Preferences.h>
#include <nvs_flash.h>

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
  preferences.putULong("count", preferences.getULong("count", 0));
}

/*
* Clears the internal storage system and does a permanent reset
* @return true if the storage is cleared properly else false
*/
bool clear_storage(){
  preferences.clear();
  preferences.end();
  nvs_flash_erase(); // erase the NVS partition and...
  nvs_flash_init(); // initialize the NVS partition.
  return true;
}