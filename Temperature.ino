/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: Temperature.ino
*  @Description: This file contains the code relating to internal temperature of ESP32
*/

#include "driver/temperature_sensor.h"

temperature_sensor_handle_t temp_handle = NULL;
float tsens_out;

/*
* Sets up the internal temperature sensor
* @return true if the sensor is set up properly else false
*/
bool set_up_temperature(){
  temperature_sensor_config_t temp_sensor_config = TEMPERATURE_SENSOR_CONFIG_DEFAULT(20, 50);
  if (temperature_sensor_install(&temp_sensor_config, &temp_handle) != ESP_OK) return false;
  if (temperature_sensor_enable(temp_handle) != ESP_OK) return false;
  return true;
}

/*
* @prerequisite Set up the temperature sensor with `set_up_temperature()` in this file
* Checks internal temperature and returns it as a float. 
* You can enable and disable the sensor in this code so that less power is used if the temperature is not checked offten
* The code for enabling and disabling the sensor is commented out
* @return the temperature as a float if received properly else return -55f
*/
float get_temperature(){
  // if (temperature_sensor_enable(temp_handle) != ESP_OK) return -55f;
  if (temperature_sensor_get_celsius(temp_handle, &tsens_out) != ESP_OK) return -55.0f;//float(-55);
  // if (temperature_sensor_disable(temp_handle) != ESP_OK) return -55f;
  return tsens_out;
}