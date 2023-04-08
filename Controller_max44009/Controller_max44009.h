#ifndef Controller_max44009_H__
#define Controller_max44009_H__
#include "Model_I2C_Device.h"
#include "Max44009.h"
// include your Libraries here


class Controller_max44009_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  
uint32_t lastDisplay = 0;
Max44009 myLux;
  Controller_max44009_Data();
  ~Controller_max44009_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_max44009_Data device_Controller_max44009;
#endif