#include "Controller_BH1750.h"
#include "debugkxn.h"

Controller_BH1750_Data::Controller_BH1750_Data()
{
  this->Add_AddressList(0x23);

  this->nameDevice = "BH1750";
  this->timeInterval = 500;
  this->valueDevice = "No device";

  Set_HS_Code(159);
  // Add your code here
}

Controller_BH1750_Data::~Controller_BH1750_Data()
{
}

bool Controller_BH1750_Data::getData()
{
  // Add your code here
  float lux = lightMeter.readLightLevel();
  this->valueDevice = "LIGHT:" + String(lux) + "  lux";
  this->timeInterval = 500;
  // this->valueDevice = String(Sensor.GetTemperature());
  return true;
}

bool Controller_BH1750_Data::init()
{
  deInit();
  // Add your code here
  lightMeter.begin();
  return 1;
}

bool Controller_BH1750_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_BH1750_Data device_Controller_BH1750;