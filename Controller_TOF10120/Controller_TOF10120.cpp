#include "Controller_TOF10120.h"
#include "debugkxn.h"

Controller_TOF10120_Data::Controller_TOF10120_Data()
{
  this->nameDevice = "Controller_TOF10120";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0X52);
  this->Add_HsCode(1318);
  // Add your code here

}

Controller_TOF10120_Data::~Controller_TOF10120_Data()
{
  
}

bool Controller_TOF10120_Data::getData()
{
  // Add your code here
  SensorRead(0x00,i2c_rx_buf,2);
    lenth_val=i2c_rx_buf[0];
    lenth_val=lenth_val<<8;
    lenth_val|=i2c_rx_buf[1];
    Serial.print("i2c= ");// print the lenth_val
    Serial.println(lenth_val);
  this->valueDevice = "Dim= "+ String(lenth_val);
  
  return true;
}

bool Controller_TOF10120_Data::init()
{
    Wire.begin();
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_TOF10120_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_TOF10120_Data device_Controller_TOF10120;