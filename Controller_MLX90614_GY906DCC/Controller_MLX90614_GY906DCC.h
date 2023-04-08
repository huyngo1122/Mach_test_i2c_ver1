#ifndef Controller_MLX90614_GY906DCC_H__
#define Controller_MLX90614_GY906DCC_H__
#include "Model_I2C_Device.h"
#include "Adafruit_MLX90614.h"
// include your Libraries here

class Controller_MLX90614_GY906DCC_Data : public Model_I2C_Device
{
public:
    // Add your declare here
    Adafruit_MLX90614 mlx = Adafruit_MLX90614();
    Controller_MLX90614_GY906DCC_Data();
    ~Controller_MLX90614_GY906DCC_Data();
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_MLX90614_GY906DCC_Data device_Controller_MLX90614_GY906DCC;
#endif