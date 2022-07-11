#include <Switches.h>

Switches* switch1;
Switches* switch2;
Switches* switch3;
Switches* switch4;

#define p1 50
#define p2 51
#define p3 52
#define p4 53

void setup() {
  for (int i = 0; i <= 53; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  switch1 = new Switches(1000, p1);
  switch2 = new Switches(1000, p2);
  switch3 = new Switches(1000, p3);
  switch4 = new Switches(1000, p4);

  Serial.begin(9600);

  while (!Serial);
}

void loop() {
  //switchMode(true) reverts the outpunt
  if (switch1->buttonMode(true)) {
    Serial.println("ButtonMode 1");
  }
  if (switch2->buttonMode(true)) {
    Serial.println("ButtonMode 2");
  }
  if (switch3->buttonMode(true)) {
    Serial.println("ButtonMode 3");
  }
  if (switch4->buttonMode(true)) {
    Serial.println("ButtonMode 4");
  }
}
