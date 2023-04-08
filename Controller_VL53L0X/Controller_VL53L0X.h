#ifndef Controller_VL53L0X_H__
#define Controller_VL53L0X_H__
#include "Model_I2C_Device.h"
#include "Adafruit_VL53L0X.h"
// include your Libraries here

class Controller_VL53L0X_Data : public Model_I2C_Device
{
public:
    // Add your declare here
    Adafruit_VL53L0X lox = Adafruit_VL53L0X();
    Controller_VL53L0X_Data();
    ~Controller_VL53L0X_Data();
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_VL53L0X_Data device_Controller_VL53L0X;
#endif