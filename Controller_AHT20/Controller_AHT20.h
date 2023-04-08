#ifndef Controller_AHT20_H__
#define Controller_AHT20_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <SparkFun_Qwiic_Humidity_AHT20.h> //Click here to get the library: http://librarymanager/All#Qwiic_Humidity_AHT20 by SparkFun


class Controller_AHT20_Data: public Model_I2C_Device{
  public:
  // Add your declare here
    AHT20 humiditySensor;
  Controller_AHT20_Data();
  ~Controller_AHT20_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_AHT20_Data device_Controller_AHT20;
#endif