//
// Created by Elijah on 27/10/2016.
//

#ifndef SKETCH_DISPENSE_H
#define SKETCH_DISPENSE_H

#include <Arduino.h>
#include <Servo.h>

class Dispenser {
public:
    Dispenser();
    Dispenser(int servoPin);
    void moveTo(int loc);
    void dispense();

private:
    int pos;
    Servo servo;
};

#endif //SKETCH_DISPENSE_H
