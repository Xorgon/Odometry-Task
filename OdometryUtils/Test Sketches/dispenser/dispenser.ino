#include <Arduino.h>
#include <Servo.h>
#include <Dispenser.h>

int dispense = 0;
Dispenser dispenser;


void onButton() {
    dispense++;
}

void setup() {
    dispenser = Dispenser(9);
    pinMode(2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), onButton, FALLING);
    Serial.begin(9600);
    while (!Serial);
    Serial.println("Started.");
}

void loop() {
    for (dispense; dispense > 0; dispense--){
        dispenser.dispense();
    }
}
