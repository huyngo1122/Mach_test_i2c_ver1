#include "Controller_HDC1080.h"
#include "debugkxn.h"

Controller_HDC1080_Data::Controller_HDC1080_Data()
{
  this->nameDevice = "HDC1080-3,3V";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x40);
  this->Add_HsCode(1310);
  // Add your code here
}

Controller_HDC1080_Data::~Controller_HDC1080_Data()
{
}

bool Controller_HDC1080_Data::getData()
{
  // Add your code here
  tempsensor.readTempHumid();
  float temp = tempsensor.getTemp();
  float humid = tempsensor.getRelativeHumidity();
  String tempString = "T=  " + String(temp) + " C";
  this->valueDevice = tempString;
  String humidString = "RH= " + String(humid) + " %";
  this->valueDevice2 = humidString;
  this->timeInterval = 500;
  return true;
}

bool Controller_HDC1080_Data::init()
{

  tempsensor = HDC1080JS();
  tempsensor.config();
  deInit();
  // Add your code here

  return 1;
}

bool Controller_HDC1080_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_HDC1080_Data device_Controller_HDC1080;