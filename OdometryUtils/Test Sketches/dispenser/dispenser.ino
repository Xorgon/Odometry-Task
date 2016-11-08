#include <Arduino.h>
#include <Servo.h>
#include <Dispenser.h>

int dispense = 0;
long lastAdded = 0;
Dispenser dispenser;


void onButton() {
//    if ((millis() - lastAdded) > 200) {
        dispense++;
        Serial.println(dispense);
//        lastAdded = millis();
//    }
}

void setup() {
    dispenser = Dispenser(9);
    pinMode(2, INPUT_PULLUP);

    pinMode(7, OUTPUT);
    digitalWrite(7, HIGH);
    attachInterrupt(digitalPinToInterrupt(2), onButton, FALLING);
    Serial.begin(9600);
    while (!Serial);
    Serial.println("Started.");
}

void loop() {
    if (Serial.available() > 0) {
        unsigned long incomingByte = Serial.read();
        Serial.println(incomingByte);
        digitalWrite(7, LOW);
        delay(10);
        digitalWrite(7, HIGH);
    }
    for (dispense; dispense > 0; dispense--){
        dispenser.dispense();
        Serial.print("");
    }
}
