#ifndef Controller_TCS34725_H__
#define Controller_TCS34725_H__
#include "Model_I2C_Device.h"

#include "i2cmaster.h"
// include your Libraries here


class Controller_TCS34725_Data: public Model_I2C_Device{
  public:
  // Add your declare here
// #define uint16_t unsigned int
typedef struct
{
    uint16_t Red;
    uint16_t Green;
    uint16_t Blue;
    uint16_t Clear;
} RGB;
unsigned char Re_buf;
unsigned char sign=0;
RGB rgb;
uint16_t CT=0,Lux=0;
byte color=0,rgb_data[3]={0};
  Controller_TCS34725_Data();
  ~Controller_TCS34725_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_TCS34725_Data device_Controller_TCS34725;
#endif