#include <Antirebote.h>

Antirebote* antirebote1;
Antirebote* antirebote2;

void setup() {
  // put your setup code here, to run once:

  antirebote1 = new Antirebote(1000, 3);
  antirebote2 = new Antirebote(5000, 4);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(antirebote1->interruptor()){
    Serial.println("Interruptor vale 1");
  }else{
    Serial.println("Interruptor vale 0");
  }

  if(antirebote2->pulsadorEnclavamiento()){
    Serial.println("Pulsador enclavamiento 1");    
  }else{
    Serial.println("Pulsador enclavamiento 2");  
  }

}
