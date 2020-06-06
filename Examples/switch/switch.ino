#include <Switches.h>

Switches* switch1;
Switches* switch2;

#define pin4 4
#define pin5 5

void setup() {
  // put your setup code here, to run once:
  pinMode(pin4,INPUT_PULLUP);
  pinMode(pin5,INPUT_PULLUP);

  switch1 = new Switches(500, pin4);
  switch2 = new Switches(500, pin5);
  Serial.begin(9600);

  while(!Serial);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(switch1->switchMode()){
    Serial.println("SwitchMode 1");
  }else{
    Serial.println("SwitchMode 0");
  }
//interlockButton(false) takes the falling edge
//interlockButton(true) takes the rising edge
  if(switch2->interlockButton(false)){
    Serial.println("Button 1");    
  }else{
    Serial.println("Button 0");  
  }

}
