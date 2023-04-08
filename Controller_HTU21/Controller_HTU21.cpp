#include "Controller_HTU21.h"
#include "debugkxn.h"

Controller_HTU21_Data::Controller_HTU21_Data()
{
    this->nameDevice = "HTU21";
    this->timeInterval = 500;
    this->valueDevice = "No device";
    this->Add_AddressList(0x40);
    this->Add_HsCode(176);
    // Add your code here
}

Controller_HTU21_Data::~Controller_HTU21_Data()
{
}

bool Controller_HTU21_Data::getData()
{

    // Add your code here

    float temp = htu.readTemperature();
    float rel_hum = htu.readHumidity();

    String temString = "T=  " + String(temp) + " C";
    String temString1 = "RH= " + String(rel_hum) + " %";
    this->valueDevice = temString;
    this->valueDevice2 = temString1;

    this->timeInterval = 500;
    return true;
}

bool Controller_HTU21_Data::init()
{
    htu.begin();
    deInit();
    // Add your code here

    return 1;
}

bool Controller_HTU21_Data::deInit()
{
    // Add your code here

    return 1;
}

Controller_HTU21_Data device_Controller_HTU21;