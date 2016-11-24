// Created by Elijah Andrews on behalf of Team A

#ifndef ODOMETRY_TASK_INDICATE_H
#define ODOMETRY_TASK_INDICATE_H

#include <Arduino.h>

class Indicate {
public:
    Indicate();

    Indicate(int ledPin, int piezoPin);

    void doIndicate();

private:
    int ledPin;
    int piezoPin;

    void flash();

    void beep(float frequency, float length);
};

#endif //ODOMETRY_TASK_INDICATE_H
