#include "Controller_ADXL345.h"
#include "debugkxn.h"

Controller_ADXL345_Data::Controller_ADXL345_Data()
{
  this->nameDevice = "ADXL345";
  this->timeInterval = 500;
  this->valueDevice = "No device";
  this->Add_AddressList(0X53);
  this->Add_HsCode(143);
  // Add your code here
}

Controller_ADXL345_Data::~Controller_ADXL345_Data()
{
}

bool Controller_ADXL345_Data::getData()
{
  // Add your code here
  sensors_event_t event;
  accel.getEvent(&event);

  this->valueDevice = "X= " + String(event.acceleration.x);
  this->valueDevice2 = "Y= " + String(event.acceleration.y);
  this->valueDevice3 = "Z= " + String(event.acceleration.z);
  this->timeInterval = 500;

  return true;
}

bool Controller_ADXL345_Data::init()
{
  deInit();
  // Add your code here

  return 1;
}

bool Controller_ADXL345_Data::deInit()
{
  // Add your code here
  accel.begin();

  return 1;
}

Controller_ADXL345_Data device_Controller_ADXL345;