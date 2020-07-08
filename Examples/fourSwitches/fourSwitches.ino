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

  switch1 = new Switches(500, p1);
  switch2 = new Switches(500, p2);
  switch3 = new Switches(500, p3);
  switch4 = new Switches(500, p4);

  Serial.begin(9600);

  while (!Serial);
}

void loop() {
  //switchMode(true) reverts the outpunt
  if (switch1->switchMode(true)) {
    Serial.println("SwitchMode 1");
  }
  if (switch2->switchMode(true)) {
    Serial.println("SwitchMode 2");
  }
  if (switch3->switchMode(true)) {
    Serial.println("SwitchMode 3");
  }
  if (switch4->switchMode(true)) {
    Serial.println("SwitchMode 4");
  }
}
