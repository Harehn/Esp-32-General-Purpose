/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: General.ino
*  @Description: This file contains the setup and main loop of the esp32 code
*/

#include <Wire.h>
 
#define VERBOSE false
#define I2C_SDA 21
#define I2C_SCL 22

void setup() {
  Wire.begin(I2C_SDA, I2C_SDA);
  Serial.begin(115200);
  if(! I2C_check(VERBOSE)) Serial.println("Error in I2C");
}
 
void loop() {
  delay(5000);
}