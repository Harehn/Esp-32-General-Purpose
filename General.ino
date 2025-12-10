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
  //------------------- SET UP DRIVERS AND CODE ---------------------------
  Wire.begin(I2C_SDA, I2C_SDA);
  Serial.begin(115200);
  if(! I2C_check(VERBOSE)) Serial.println("Error in I2C.");
  if(! set_up_temperature()) Serial.println("Error in Setting temperature sensor.");
  if(! set_up_ledc()) Serial.println("Error in setting up ledc.");
  if(! set_up_storage()) Serial.println("Storage didn't set up properly.")

  //------------------- OTHER INITIALIZATIONS -----------------------------
  set_count();
}
 
void loop() {
  //-------------------- TEMPERATURE --------------------------------------
  float temp = get_temperature();
  if (temp == -55.0f) Serial.println("Temperature Reading Error");
  else Serial.printf("Internal Temperature is %f.", temp);

  //-------------------- LEDC ---------------------------------------------
  set_ledc_duty(50); // 0 - 255
  
  //-------------------- COUNT UPDATE/INTERNAL STORAGE --------------------
  increase_count();

  delay(5000);
}