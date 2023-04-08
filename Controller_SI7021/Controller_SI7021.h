#ifndef Controller_SI7021_H__
#define Controller_SI7021_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Adafruit_Si7021.h>

class Controller_SI7021_Data : public Model_I2C_Device
{
public:
  // Add your declare here
  bool enableHeater = false;
  uint8_t loopCnt = 0;

  Adafruit_Si7021 sensor = Adafruit_Si7021();
  Controller_SI7021_Data();
  ~Controller_SI7021_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_SI7021_Data device_Controller_SI7021;
#endif