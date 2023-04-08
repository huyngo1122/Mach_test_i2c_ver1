#ifndef Controller_HDC1080_H__
#define Controller_HDC1080_H__
#include "Model_I2C_Device.h"
#include "HDC1080JS.h"
// include your Libraries here

class Controller_HDC1080_Data : public Model_I2C_Device
{
public:
  // Add your declare here
  HDC1080JS tempsensor;
  Controller_HDC1080_Data();
  ~Controller_HDC1080_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_HDC1080_Data device_Controller_HDC1080;
#endif