#include "Controller_VL53L_1X.h"
#include "debugkxn.h"

Controller_VL53L_1X_Data::Controller_VL53L_1X_Data()
{
    this->nameDevice = "VL53L_1X";
    this->timeInterval = 250;
    this->valueDevice = "No device";
    this->Add_AddressList(0x29);
    this->Add_HsCode(1272);
    // Add your code here
}

Controller_VL53L_1X_Data::~Controller_VL53L_1X_Data()
{
}

bool Controller_VL53L_1X_Data::getData()
{
    // Add your code here
    sensor.read() this->valueDevice = "Dim: " + String(sensor.read());

    return true;
}

bool Controller_VL53L_1X_Data::init()
{

    sensor.init()
        sensor.setDistanceMode(VL53L1X::Long);
    sensor.setMeasurementTimingBudget(50000);
    deInit();
    // Add your code here

    return 1;
}

bool Controller_VL53L_1X_Data::deInit()
{
    // Add your code here

    return 1;
}

Controller_VL53L_1X_Data device_Controller_VL53L_1X;