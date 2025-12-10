/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: General.ino
*  @Description: This file contains the setup and main loop of the esp32 code
*/

#include <Wire.h>
#include <Preferences.h>
 
#define VERBOSE false
#define I2C_SDA 21
#define I2C_SCL 22
#define PIN_IN 16
#define PIN_OUT 17

Preferences preferences;

void setup() {
  //------------------- SET UP DRIVERS AND CODE ---------------------------
  Wire.begin(I2C_SDA, I2C_SDA);
  Serial.begin(115200);
  if(! I2C_check(VERBOSE)) Serial.println("Error in I2C.");
  if(! set_up_temperature()) Serial.println("Error in Setting temperature sensor.");
  if(! set_up_ledc()) Serial.println("Error in setting up ledc.");
  if(! set_up_storage()) Serial.println("Storage didn't set up properly.");
  if(! set_up_RTC()) Serial.println("RTC didn't set up properly.");
  if(! set_up_BLE()) Serial.println("Bluetooth didn't set up properly.");

  //------------------- OTHER INITIALIZATIONS -----------------------------
  set_count();
  pinMode(PIN_IN, INPUT);
  pinMode(PIN_OUT, OUTPUT);
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
  print_count();

  //------------------- PRINT TIME ---------------------------------------
  printTime();

  //------------------- BLE SCAN -----------------------------------------
  scan_BLE();

  //-------------------- REPEATER -----------------------------------------
  digitalWrite(PIN_OUT, digitalRead(PIN_IN));

  delay(5000);
}