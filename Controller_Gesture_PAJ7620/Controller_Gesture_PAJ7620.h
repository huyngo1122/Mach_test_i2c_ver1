#ifndef Controller_Gesture_PAJ7620_H__
#define Controller_Gesture_PAJ7620_H__
#include "Model_I2C_Device.h"
#include "paj7620.h"
// include your Libraries here

class Controller_Gesture_PAJ7620_Data : public Model_I2C_Device
{
public:
  // Add your declare here
#define GES_REACTION_TIME 500 // You can adjust the reaction time according to the actual circumstance.
#define GES_ENTRY_TIME 800    // When you want to recognize the Forward/Backward gestures, your gestures' reaction time must less than GES_ENTRY_TIME(0.8s).
#define GES_QUIT_TIME 1000
  Controller_Gesture_PAJ7620_Data();
  ~Controller_Gesture_PAJ7620_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_Gesture_PAJ7620_Data device_Controller_Gesture_PAJ7620;
#endif