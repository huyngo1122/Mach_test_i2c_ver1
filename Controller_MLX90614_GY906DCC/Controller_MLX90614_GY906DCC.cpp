#include "Controller_MLX90614_GY906DCC.h"
#include "debugkxn.h"

Controller_MLX90614_GY906DCC_Data::Controller_MLX90614_GY906DCC_Data()
{
    this->nameDevice = "GY906_DDC";
    this->timeInterval = 250;
    this->valueDevice = "No device";
    this->Add_AddressList(0x5A);
    this->Add_HsCode(1450);
    // Add your code here
}

Controller_MLX90614_GY906DCC_Data::~Controller_MLX90614_GY906DCC_Data()
{
}

bool Controller_MLX90614_GY906DCC_Data::getData()
{
    // Add your code here
    this->timeInterval = 500;
    this->valueDevice = "Temp: " + String(mlx.readObjectTempC()) + " *C";

    return true;
}

bool Controller_MLX90614_GY906DCC_Data::init()
{
    mlx.begin()
        deInit();
    // Add your code here

    return 1;
}

bool Controller_MLX90614_GY906DCC_Data::deInit()
{
    // Add your code here

    return 1;
}

Controller_MLX90614_GY906DCC_Data device_Controller_MLX90614_GY906DCC;