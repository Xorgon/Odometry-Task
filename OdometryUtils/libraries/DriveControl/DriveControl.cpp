//
// Created by Elijah on 01/11/2016.
//

#include "DriveControl.h"

DriveControl::DriveControl(bool initialize) {
    if (initialize) {
        Wire.begin();
        Serial.begin(9600);
        delay(100);

        Wire.beginTransmission(MD25ADDRESS);
        Wire.write(MODE_SELECTOR);
        Wire.write(mode);
        Wire.endTransmission();

        resetEncoders();

        setAcceleration(accelRate);
    }
}

DriveControl::DriveControl() {} // Allow for uninitialized global variable creation.

void DriveControl::resetEncoders() {
    Wire.beginTransmission(MD25ADDRESS);
    Wire.write(CMD);
    Wire.write(0x20);
    Wire.endTransmission();
    delay(50);
}

void DriveControl::line(float distance) {
    setSpeed(128 + maxLineSpeed);
    while (getDistance1() < (distance - stoppingDistance)) {
    }
    stop();
    resetEncoders();
}

void DriveControl::turn(float radius, float theta, bool dirRight) {
    float speed = 128 + ((maxTurnSpeed * radius) / (radius + wheelOffset));
    float turn = wheelOffset * maxTurnSpeed / (radius + wheelOffset);

    if (!dirRight) {
        turn = -turn;
    }

    setSpeed(round(speed));
    setTurn(round(128 + turn));

    float outerDist = 2 * pi * (radius + wheelOffset) * theta / 360.; // distance the outer wheel travels.
    float currDist;
    if (dirRight) {
        currDist = getDistance1();
    } else {
        currDist = getDistance2();
    }


    while (currDist < (outerDist - stoppingDistance)) {
        if (dirRight) {
            currDist = getDistance1();
        } else {
            currDist = getDistance2();
        }

    }
    stop();
    resetEncoders();
}

float DriveControl::getDistance1() {
    Wire.beginTransmission(MD25ADDRESS);
    Wire.write(ENCODERONE);
    Wire.endTransmission();

    Wire.requestFrom(MD25ADDRESS, 4);                         // Request 4 bytes from MD25
    while (Wire.available() < 4);                              // Wait for 4 bytes to arrive
    long poss = Wire.read();                                 // First byte for encoder 1.
    poss <<= 8;
    poss += Wire.read();                                     // Second byte for encoder 1.
    poss <<= 8;
    poss += Wire.read();                                     // Third byte for encoder 1.
    poss <<= 8;
    poss += Wire.read();                                     // Fourth byte for encoder 1.
    delay(5);                                                 // Ensure everything is read properly.
    return (2 * pi * wheelRadius * poss / 360.); // Converting from degrees of rotation to distance in mm.
}

float DriveControl::getDistance2() {
    Wire.beginTransmission(MD25ADDRESS);
    Wire.write(ENCODERTWO);
    Wire.endTransmission();

    Wire.requestFrom(MD25ADDRESS, 4);                         // Request 4 bytes from MD25
    while (Wire.available() < 4);                              // Wait for 4 bytes to arrive
    long poss = Wire.read();                                 // First byte for encoder 1.
    poss <<= 8;
    poss += Wire.read();                                     // Second byte for encoder 1.
    poss <<= 8;
    poss += Wire.read();                                     // Third byte for encoder 1.
    poss <<= 8;
    poss += Wire.read();                                     // Fourth byte for encoder 1.
    delay(5);                                                 // Ensure everything is read properly.
    return (2 * pi * wheelRadius * poss / 360.); // Converting from degrees of rotation to distance in mm.
}

void DriveControl::setSpeed(int speed) {
    Wire.beginTransmission(MD25ADDRESS);
    Wire.write(SPEED1);
    Wire.write(speed);
    Wire.endTransmission();
}

void DriveControl::setTurn(int turn) {
    Wire.beginTransmission(MD25ADDRESS);
    Wire.write(SPEED2);
    Wire.write(turn);
    Wire.endTransmission();
}

void DriveControl::setAcceleration(int a) {
    Wire.beginTransmission(MD25ADDRESS);
    Wire.write(ACCELERATION);
    Wire.write(a);
    Wire.endTransmission();
}

void DriveControl::stop() {
    setAcceleration(decelRate);
    setSpeed(128);
    setTurn(128);
    delay(round(25 * maxLineSpeed / decelRate) + 50); // Wait for motion to stop.
    setAcceleration(accelRate);
}