#ifndef Controller_APDS_9960_RGB_H__
#define Controller_APDS_9960_RGB_H__
#include "Model_I2C_Device.h"
#include "SparkFun_APDS9960_Hshop_Update.h"
// include your Libraries here


class Controller_APDS_9960_RGB_Data: public Model_I2C_Device{
  public:
  // Add your declare here

#define APDS9960_INT    2 // Needs to be an interrupt pin

// Constants

// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();

  Controller_APDS_9960_RGB_Data();
  ~Controller_APDS_9960_RGB_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_APDS_9960_RGB_Data device_Controller_APDS_9960_RGB;
#endif