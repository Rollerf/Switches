#include "Switches.h"

Switches::Switches(unsigned long setPointTime, int n_Pin){
    this -> setPointTime = setPointTime;
    lastState = 0;
    initTime = 0;
    interlockOutput = 0;
    this -> n_Pin = n_Pin;
}

bool Switches::interlockButton(bool fallingEdge){

    switchState=digitalRead(n_Pin);

    if (switchState == !fallingEdge){
        if(lastState != switchState && (millis() >= initTime + setPointTime)){
            lastState = switchState;
            interlockOutput = !interlockOutput;
        }
    }
    else {
        initTime = millis();
		lastState = fallingEdge;
    }

    return interlockOutput;
}

bool Switches::switchMode(bool invert){

    switchState=digitalRead(n_Pin);

    if (switchState != lastState){
        if (millis() >= initTime + setPointTime){
            lastState = switchState;
        } 
    }
    else {
        initTime = millis();
    } 
	if(invert){
		return !lastState;
	}
	else{
		return lastState;
	}    
}