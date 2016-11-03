//
// Created by Elijah on 03/11/2016.
//

#include "Indicate.h"

Indicate::Indicate() {}

Indicate::Indicate(int ledPin, int piezoPin) {
    this->ledPin = ledPin;
    this->piezoPin = piezoPin;
    pinMode(ledPin, OUTPUT);
    pinMode(piezoPin, OUTPUT);
}

void Indicate::doIndicate() {
    digitalWrite(ledPin, HIGH);
    beep(1000, 500);
    digitalWrite(ledPin, LOW);
}

void Indicate::beep(float frequency, float length) {
    int period = round(1000/frequency);
    for (int i = 0; i < (length/period); i++){
        digitalWrite(piezoPin, HIGH);
        digitalWrite(piezoPin, LOW);
        delay(period);
    }
}

