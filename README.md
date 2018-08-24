# Steppone
Stepper library for Wiring/Arduino for 28byj-48

```C
#include <Steppone.h>;

const int PIN_1 = 9;
const int PIN_2 = 10;
const int PIN_3 = 11;
const int PIN_4 = 12;


Steppone myStepper = Steppone(PIN_1, PIN_2, PIN_3, PIN_4);

void setup() {
  Serial.begin(9600);
  Serial.println("STEPPER ON");
  delay(10);
}

void loop() {

  Serial.println("FORW");
  myStepper.step(4095, 0);
  delay(1000);
  Serial.println("BACK");
  myStepper.step(4095, 1);
  delay(1000);
}

```
