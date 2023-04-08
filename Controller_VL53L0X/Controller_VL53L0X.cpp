#include "Controller_VL53L0X.h"
#include "debugkxn.h"

Controller_VL53L0X_Data::Controller_VL53L0X_Data()
{
  this->nameDevice = "VL53L0X";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x29);
  this->Add_HsCode(201);
  // Add your code here

}

Controller_VL53L0X_Data::~Controller_VL53L0X_Data()
{
  
}

bool Controller_VL53L0X_Data::getData()
{
  // Add your code here
  if (lox.isRangeComplete()) {
    Serial.print("Distance in mm: ");
    Serial.println(lox.readRange());
  }
  this->valueDevice = "Distance: " + String(lox.readRange())+" mm";
  
  return true;
}

bool Controller_VL53L0X_Data::init()
{
    lox.begin();
    lox.startRangeContinuous();
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_VL53L0X_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_VL53L0X_Data device_Controller_VL53L0X;