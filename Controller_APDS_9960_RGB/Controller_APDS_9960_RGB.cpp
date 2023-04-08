#include "Controller_APDS_9960_RGB.h"
#include "debugkxn.h"

Controller_APDS_9960_RGB_Data::Controller_APDS_9960_RGB_Data()
{
  this->nameDevice = "APDS_9960-RGB";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0X39);
  this->Add_HsCode(197);
  // Add your code here

}

Controller_APDS_9960_RGB_Data::~Controller_APDS_9960_RGB_Data()
{
  
}

bool Controller_APDS_9960_RGB_Data::getData()
{
  // Add your code here
  if ( apds.isGestureAvailable() ) {
    switch ( apds.readGesture() ) {
      case DIR_UP:
        this->valueDevice = "UP";
        break;
      case DIR_DOWN:
        this->valueDevice = "DOWN";
        break;
      case DIR_LEFT:
        this->valueDevice = "LEFT";
        break;
      case DIR_RIGHT:
        this->valueDevice = "RIGHT";
        break;
      case DIR_NEAR:
        this->valueDevice = "NEAR";
        break;
      case DIR_FAR:
        this->valueDevice = "FAR";
        break;
      default:
        this->valueDevice = "NONE";
    }
  }
  
  
  return true;
}

bool Controller_APDS_9960_RGB_Data::init()
{
    
   
     apds.init();
     apds.enableGestureSensor(true);
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_APDS_9960_RGB_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_APDS_9960_RGB_Data device_Controller_APDS_9960_RGB;