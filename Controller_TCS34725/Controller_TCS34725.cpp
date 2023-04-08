#include "Controller_TCS34725.h"
#include "debugkxn.h"

Controller_TCS34725_Data::Controller_TCS34725_Data()
{
  this->nameDevice = "TCS34725_V1";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0X5a);
  this->Add_HsCode(215);
  // Add your code here

}

Controller_TCS34725_Data::~Controller_TCS34725_Data()
{
  
}

bool Controller_TCS34725_Data::getData()
{
  // Add your code here
      unsigned char data[9]={0};
 if(!sign)
 {
  //  iic_read(0x00,data,8);
   rgb.Red=(data[0]<<8)|data[1];
   rgb.Green=(data[2]<<8)|data[3];
   rgb.Blue=(data[4]<<8)|data[5];
   rgb.Clear=(data[6]<<8)|data[7];
this->valueDevice = "RED: "+ String(rgb.Red);

this->valueDevice2 = "Green: "+ String(rgb.Green);

this->valueDevice2 = "Blue: "+ String(rgb.Blue);

  

  
  return true;
}
}

bool Controller_TCS34725_Data::init()
{
  i2c_init();
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_TCS34725_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_TCS34725_Data device_Controller_TCS34725;