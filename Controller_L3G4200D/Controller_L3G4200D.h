#ifndef Controller_L3G4200D_H__
#define Controller_L3G4200D_H__
#include "Model_I2C_Device.h"

#include "L3G4200D.h"
// include your Libraries here

class Controller_L3G4200D_Data : public Model_I2C_Device
{
public:
    // Add your declare here
    L3G4200D gyroscope;

    // Timers
    unsigned long timer = 0;
    float timeStep = 0.01;

    // Pitch, Roll and Yaw values
    float pitch = 0;
    float roll = 0;
    float yaw = 0;
    Controller_L3G4200D_Data();
    ~Controller_L3G4200D_Data();
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_L3G4200D_Data device_Controller_L3G4200D;
#endif