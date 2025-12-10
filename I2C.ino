/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: I2C.ino
*  @Description: This file contains the code relating to I2C functionality of ESP32
*/

#include <Wire.h>

bool I2C_check(bool Verbose){
  int nDevices = 0;
  for(int address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0){
      nDevices++;
      if (Verbose) {
        Serial.print("I2C device found at address 0x");
        Serial.println(address,HEX);
        }
    }
  return nDevices == 0;
  }
}