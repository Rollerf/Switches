#include <Switches.h>

Switches* switch1;
Switches* switch2;

#define pin4 4
#define pin5 5

void setup() {
  pinMode(pin4,INPUT_PULLUP);
  pinMode(pin5,INPUT_PULLUP);

  switch1 = new Switches(500, pin4);
  switch2 = new Switches(500, pin5);
  Serial.begin(9600);

  while(!Serial);
}

void loop() {
  if(switch1->switchMode(false)){
    Serial.println("SwitchMode 1");
  }else{
    Serial.println("SwitchMode 0");
  }
//interlockButton(true) takes the falling edge
//interlockButton(false) takes the rising edge
  if(switch2->interlockButton(true)){
    Serial.println("Button 1");    
  }else{
    Serial.println("Button 0");  
  }
}
