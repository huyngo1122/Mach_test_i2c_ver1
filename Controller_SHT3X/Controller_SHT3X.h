#ifndef Controller_SHT3X_H__
#define Controller_SHT3X_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "hshop_SHT3x.h"

class Controller_SHT3X_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  SHT3x Sensor;

  Controller_SHT3X_Data();
  ~Controller_SHT3X_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_SHT3X_Data device_Controller_SHT3X;
#endif
