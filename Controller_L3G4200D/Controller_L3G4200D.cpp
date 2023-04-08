#include "Controller_L3G4200D.h"
#include "debugkxn.h"

Controller_L3G4200D_Data::Controller_L3G4200D_Data()
{
    this->nameDevice = "L3G4200";
    this->timeInterval = 500;
    this->valueDevice = "No device";
    this->Add_AddressList(0x69);
    this->Add_HsCode(196);
    // Add your code here
}

Controller_L3G4200D_Data::~Controller_L3G4200D_Data()
{
}

bool Controller_L3G4200D_Data::getData()
{
    // Add your code here

    // Read normalized values
    Vector norm = gyroscope.readNormalize();

    // Calculate Pitch, Roll and Yaw
    pitch = pitch + norm.YAxis * timeStep;
    roll = roll + norm.XAxis * timeStep;
    yaw = yaw + norm.ZAxis * timeStep;

    this->valueDevice = "X: " + String(norm.XAxis);
    this->valueDevice2 = "Y: " + String(norm.YAxis);
    this->valueDevice3 = "Z: " + String(norm.ZAxis);
    this->timeInterval = 500;
    return true;
}

bool Controller_L3G4200D_Data::init()
{

    gyroscope.begin(L3G4200D_SCALE_2000DPS, L3G4200D_DATARATE_400HZ_50);
    gyroscope.calibrate(100);
    deInit();
    // Add your code here

    return 1;
}

bool Controller_L3G4200D_Data::deInit()
{
    // Add your code here

    return 1;
}

Controller_L3G4200D_Data device_Controller_L3G4200D;