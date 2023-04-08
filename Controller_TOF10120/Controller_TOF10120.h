#ifndef Controller_TOF10120_H__
#define Controller_TOF10120_H__
#include "Model_I2C_Device.h"
#include "avr/io.h"
#include "avr/interrupt.h"
// include your Libraries here


class Controller_TOF10120_Data: public Model_I2C_Device{
  public:
  // Add your declare here
char Res;
unsigned short lenth_val = 0;
unsigned char i2c_rx_buf[16];

void SensorWrite(unsigned char addr,unsigned char* datbuf,unsigned char cnt) 
{
  unsigned short result=0;
  // step 1: instruct sensor to read echoes
  Wire.beginTransmission(82); // transmit to device #82 (0x52)
  // the address specified in the datasheet is 164 (0xa4)
  // but i2c adressing uses the high 7 bits so it's 82
  Wire.write(byte(addr));      // sets distance data address (addr)
  // step 2: wait for address to write
  delay(1);                   // datasheet suggests at least 30uS
  // step 3: send data to sensor
  Wire.write(datbuf, cnt);    // write cnt bytes to slave device
  Wire.endTransmission();      // stop transmitting
}
void SensorRead(unsigned char addr,unsigned char* datbuf,unsigned char cnt) 
{
  unsigned short result=0;
  // step 1: instruct sensor to read echoes
  Wire.beginTransmission(82); // transmit to device #82 (0x52)
  // the address specified in the datasheet is 164 (0xa4)
  // but i2c adressing uses the high 7 bits so it's 82
  Wire.write(byte(addr));      // sets distance data address (addr)
  Wire.endTransmission();      // stop transmitting
  // step 2: wait for readings to happen
  delay(1);                   // datasheet suggests at least 30uS
  // step 3: request reading from sensor
  Wire.requestFrom((int)82, (int)cnt);    // request cnt bytes from slave device #82 (0x52)
  // step 5: receive reading from sensor
  if (cnt <= Wire.available()) { // if two bytes were received
    *datbuf++ = Wire.read();  // receive high byte (overwrites previous reading)
    *datbuf++ = Wire.read(); // receive low byte as lower 8 bits
  }
}
  Controller_TOF10120_Data();
  ~Controller_TOF10120_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_TOF10120_Data device_Controller_TOF10120;
#endif