/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: I2C.ino
*  @Description: This file contains the code relating to I2C functionality of ESP32
*/

#include <Wire.h>

/*
* @prerequisite Set up I2C with `Wire.begin`
* Checks all the addresses from 1 to 126 and returns false if all addresses give an error
* If no address replies to the I2C request, this would indicate an issue with the address or the setup
* @param verbose if verbose is True, the addresses that give a reply
* @return false if any of the I2C transmissions get a reply else true
*/
bool I2C_check(bool verbose){
  int nDevices = 0;
  for(int address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0){
      nDevices++;
      if (verbose) {
        Serial.print("I2C device found at address 0x");
        Serial.println(address,HEX);
        }
    }
  return nDevices == 0;
  }
}