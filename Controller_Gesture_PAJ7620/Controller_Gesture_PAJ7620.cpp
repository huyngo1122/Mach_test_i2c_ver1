#include "Controller_Gesture_PAJ7620.h"
#include "debugkxn.h"

Controller_Gesture_PAJ7620_Data::Controller_Gesture_PAJ7620_Data()
{
    this->nameDevice = "Gesture_PAJ7620";
    this->timeInterval = 250;
    this->valueDevice = "No device";
    this->Add_AddressList(0x73);
    this->Add_HsCode(1304);
    // Add your code here
}

Controller_Gesture_PAJ7620_Data::~Controller_Gesture_PAJ7620_Data()
{
}

bool Controller_Gesture_PAJ7620_Data::getData()
{
    // Add your code here
    uint8_t data = 0, data1 = 0, error;
    error = paj7620ReadReg(0x43, 1, &data);
    if (!error)
    {
        switch (data)
        { // When different gestures be detected, the variable 'data' will be set to different values by paj7620ReadReg(0x43, 1, &data).
        case GES_RIGHT_FLAG:
            delay(GES_ENTRY_TIME);
            paj7620ReadReg(0x43, 1, &data);
            if (data == GES_FORWARD_FLAG)
            {
                this->valueDevice = "Forward";
                delay(GES_QUIT_TIME);
            }
            else if (data == GES_BACKWARD_FLAG)
            {
                this->valueDevice = "Backward";

                delay(GES_QUIT_TIME);
            }
            else
            {
                this->valueDevice = "Right";
            }
            break;
        case GES_LEFT_FLAG:
            delay(GES_ENTRY_TIME);
            paj7620ReadReg(0x43, 1, &data);
            if (data == GES_FORWARD_FLAG)
            {
                this->valueDevice = "Forward";
                delay(GES_QUIT_TIME);
            }
            else if (data == GES_BACKWARD_FLAG)
            {
                this->valueDevice = "Backward";

                delay(GES_QUIT_TIME);
            }
            else
            {
                this->valueDevice = "Left";
            }
            break;
        case GES_UP_FLAG:
            delay(GES_ENTRY_TIME);
            paj7620ReadReg(0x43, 1, &data);
            if (data == GES_FORWARD_FLAG)
            {
                this->valueDevice = "Forward";
                delay(GES_QUIT_TIME);
            }
            else if (data == GES_BACKWARD_FLAG)
            {
                this->valueDevice = "Backward";

                delay(GES_QUIT_TIME);
            }
            else
            {
                this->valueDevice = "Up";
            }
            break;
        case GES_DOWN_FLAG:
            delay(GES_ENTRY_TIME);
            paj7620ReadReg(0x43, 1, &data);
            if (data == GES_FORWARD_FLAG)
            {
                this->valueDevice = "Forward";
                delay(GES_QUIT_TIME);
            }
            else if (data == GES_BACKWARD_FLAG)
            {
                this->valueDevice = "Backward";

                delay(GES_QUIT_TIME);
            }
            else
            {
                this->valueDevice = "Down";
            }
            break;
        case GES_FORWARD_FLAG:
            this->valueDevice = "Forward";
            delay(GES_QUIT_TIME);
            break;
        case GES_BACKWARD_FLAG:
            this->valueDevice = "Backward";
            delay(GES_QUIT_TIME);
            break;
        case GES_CLOCKWISE_FLAG:
            this->valueDevice = "Clockwise";

            break;
        case GES_COUNT_CLOCKWISE_FLAG:
            this->valueDevice = "anti-clockwise";
            break;
        default:
            paj7620ReadReg(0x44, 1, &data1);
            if (data1 == GES_WAVE_FLAG)
            {
                this->valueDevice = "wave";
            }
            break;
        }
    }
    delay(100);

    return true;
}

bool Controller_Gesture_PAJ7620_Data::init()
{
    uint8_t error = 0;
    error = paj7620Init();

    deInit();
    // Add your code here

    return 1;
}

bool Controller_Gesture_PAJ7620_Data::deInit()
{
    // Add your code here

    return 1;
}

Controller_Gesture_PAJ7620_Data device_Controller_Gesture_PAJ7620;