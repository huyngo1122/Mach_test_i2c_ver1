#include "Controller_GY511.h"
#include "debugkxn.h"

Controller_GY511_Data::Controller_GY511_Data()
{
  this->nameDevice = "GY511";
  this->timeInterval = 500;
  this->valueDevice = "No device";
  this->Add_AddressList(0x19);
  this->Add_HsCode(206);
  // Add your code here
}

Controller_GY511_Data::~Controller_GY511_Data()
{
}

bool Controller_GY511_Data::getData()
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

bool Controller_GY511_Data::init()
{
  accel.begin();
  deInit();
  // Add your code here

  return 1;
}

bool Controller_GY511_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_GY511_Data device_Controller_GY511;