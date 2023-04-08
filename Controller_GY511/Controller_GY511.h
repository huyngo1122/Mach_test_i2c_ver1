#ifndef Controller_GY511_H__
#define Controller_GY511_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

class Controller_GY511_Data: public Model_I2C_Device{
  public:
  // Add your declare here
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
  Controller_GY511_Data();
  ~Controller_GY511_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_GY511_Data device_Controller_GY511;
#endif