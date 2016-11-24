// Created by Elijah Andrews on behalf of Team A

#include "Dispenser.h"

Dispenser::Dispenser() {} // Allows the code to create a global Dispenser variable without properly initializing.

Dispenser::Dispenser(int servoPin) {
    pos = 0;
    servo = Servo();
    servo.attach(servoPin);
    servo.write(0);
}

// Function to smoothly move the servo.
void Dispenser::moveTo(int loc) {
    if (pos == loc) {
        return;
    }
    if (pos < loc) {
        for (pos; pos < loc; pos++) {
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

// Function to dispense an M&M.
void Dispenser::dispense() {
    moveTo(90);
    delay(50);
    moveTo(0);
}