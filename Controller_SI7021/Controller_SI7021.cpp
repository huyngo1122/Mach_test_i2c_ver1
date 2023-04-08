#include "Controller_SI7021.h"
#include "debugkxn.h"

Controller_SI7021_Data::Controller_SI7021_Data()
{
  this->nameDevice = "SI7021";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x40);
  this->Add_HsCode(1518);
  // Add your code here

}

Controller_SI7021_Data::~Controller_SI7021_Data()
{
  
}

bool Controller_SI7021_Data::getData()
{
  // Add your code here

  float temperature = sensor.readTemperature();
  float humidity = sensor.readHumidity();

  this->valueDevice = "T: "+ String(temperature)+ " C";
  this->valueDevice2 = "H: " + String(humidity)+"  %";
   this->timeInterval = 500; 
  return true;
}

bool Controller_SI7021_Data::init()
{
  deInit();
  // Add your code here
  sensor.begin();
  return 1;
}

bool Controller_SI7021_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_SI7021_Data device_Controller_SI7021;