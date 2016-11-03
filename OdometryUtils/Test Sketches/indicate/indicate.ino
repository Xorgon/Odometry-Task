#include <Arduino.h>
#include <Indicate.h>

Indicate indicate;

void setup() {
    indicate = Indicate(5,6);
}

void loop() {
    indicate.doIndicate();
    delay(2000);
}