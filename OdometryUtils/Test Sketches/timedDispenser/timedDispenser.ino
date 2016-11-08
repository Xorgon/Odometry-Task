#include <Arduino.h>
#include <Dispenser.h>

Dispenser dispenser;

void setup() {
    dispenser = Dispenser(10);
}

void loop() {
    dispenser.dispense();
    delay(1000);
}