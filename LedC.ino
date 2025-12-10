/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: LedC.ino
*  @Description: This file contains the code relating to PWM functionality of ESP32
*/

#define LEDC_PIN 16

/*
* Sets up for LEDC
* @return True if the ledc system is set up properly else False
*/
bool set_up_ledc(){
  // pinMode(LEDC_PIN, OUTPUT);
  if (! ledcAttach(LEDC_PIN, 5000, 8)) return false;
  if (! ledcAttachChannel(LEDC_PIN, 5000, 8, 0)) return false;
  return true;
}

/*
* @prerequisite Set up the temperature sensor with `set_up_ledc()` in this file
* Sets ledc duty
*/
void set_ledc_duty(int duty){
  ledcWrite(LEDC_PIN, duty);
  delay(5000);
}