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
    Switches::~Switches();
    //switchMode works for normal switch
    bool switchMode();
    //interlockButton, when you push the button, this one changes his state until you press it again
	//if risingEdge is true the output is changed when the value input is 1. If is false it works with fallingEdge
    bool interlockButton(bool risingEdge);
};

