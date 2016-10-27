//
// Created by Elijah on 27/10/2016.
//

#include "Dispenser.h"

Dispenser::Dispenser(int servoPin) {
    servo.attach(servoPin);
    servo.write(0);
}

void Dispenser::moveTo(int loc) {
    if (pos == loc) {
        return;
    }
    if (pos < loc) {
        for (pos; pos < loc; pos++) {
            Serial.println(pos);
            servo.write(pos);
            delay(5);
        }
    } else {
        for (pos; pos > loc; pos--) {
            servo.write(pos);
            delay(5);
        }
    }
}

void Dispenser::dispense() {
    moveTo(90);
    delay(50);
    moveTo(0);
}