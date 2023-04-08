#include "Controller_SHT3X.h"
#include "debugkxn.h"

Controller_SHT3X_Data::Controller_SHT3X_Data()
{
  this->nameDevice = "SHT30";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x44);
  Set_HS_Code(177);
  // Add your code here
}

Controller_SHT3X_Data::~Controller_SHT3X_Data()
{
}

bool Controller_SHT3X_Data::getData()
{
  // Add your code here
  Sensor.UpdateData();
  String tempString = "T: " + String(Sensor.GetTemperature()) + "C  ";
  this->valueDevice = tempString;
  this->valueDevice2 = "H: " + String(Sensor.GetRelHumidity()) + "%";
  return true;
}

bool Controller_SHT3X_Data::init()
{
  deInit();
  // Add your code here
  Sensor.Begin();

  return 1;
}

bool Controller_SHT3X_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_SHT3X_Data device_Controller_SHT3X;