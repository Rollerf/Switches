/*
Library for create Switches
*/

#include "Arduino.h"

class Switches
{
private:
    /* data */
    bool lastState;
    bool switchState;
    bool interlockOutput;
    int n_Pin;
    unsigned long initTime;
    unsigned long currentTime;
    unsigned long setPointTime;

public:
    //Constructor
    Switches(unsigned long setPointTime, int n_Pin);
    //Destructor
    ~Switches();
    //switchMode works for normal switch when received false. But if received true, it returns the inverted value
    bool switchMode(bool invert);
    //buttonMode works for normal button when received false. But if received true, it takes 0 like the press value
    bool buttonMode(bool pullUp);
    //interlockButton, when you push the button, this one changes his state until you press it again
    //if fallingEdge is false the output is changed when the value input is 1. If is true it works with fallingEdge
    bool interlockButton(bool fallingEdge);
};
