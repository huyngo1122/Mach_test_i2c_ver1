#include "Controller_max44009.h"
#include "debugkxn.h"

Controller_max44009_Data::Controller_max44009_Data()
{
  this->nameDevice = "MAX44009_LIGH";
  this->timeInterval = 500;
  this->valueDevice = "No device";
  this->Add_AddressList(0x4A);
  this->Add_HsCode(1308);
  // Add your code here
}

Controller_max44009_Data::~Controller_max44009_Data()
{
}

bool Controller_max44009_Data::getData()
{
  // Add your code here

  float lux = myLux.getLux();
  int err = myLux.getError();
  int st = myLux.getInterruptStatus();
  if (err != 0)
  {
  }
  else
  {

    if (st == 1)
      this->valueDevice = "  IRQ occurred";
  }

  String strData = "LUX: " + String(lux);
  this->valueDevice = strData;
  this->timeInterval = 500;

  return true;
}

bool Controller_max44009_Data::init()
{

  myLux.setContinuousMode();
  myLux.setHighThreshold(30);
  myLux.setLowThreshold(10);
  myLux.setThresholdTimer(2);
  myLux.enableInterrupt();

  deInit();
  // Add your code here

  return 1;
}

bool Controller_max44009_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_max44009_Data device_Controller_max44009;