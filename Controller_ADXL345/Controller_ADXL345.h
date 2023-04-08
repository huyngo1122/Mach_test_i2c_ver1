#ifndef Controller_ADXL345_H__
#define Controller_ADXL345_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Adafruit_Sensor.h>
#include "Adafruit_ADXL345_U.h"

class Controller_ADXL345_Data: public Model_I2C_Device{
  public:
  // Add your declare here
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
  Controller_ADXL345_Data();
  ~Controller_ADXL345_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_ADXL345_Data device_Controller_ADXL345;
#endif