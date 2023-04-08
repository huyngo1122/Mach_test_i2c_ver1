#ifndef Controller_VL53L_1X_H__
#define Controller_VL53L_1X_H__
#include "Model_I2C_Device.h"
#include "VL53L1X.h"
// include your Libraries here

class Controller_VL53L_1X_Data : public Model_I2C_Device
{
public:
    // Add your declare here
    VL53L1X sensor;
    Controller_VL53L_1X_Data();
    ~Controller_VL53L_1X_Data();
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_VL53L_1X_Data device_Controller_VL53L_1X;
#endif