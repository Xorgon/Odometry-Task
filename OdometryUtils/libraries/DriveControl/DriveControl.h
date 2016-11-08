//
// Created by Elijah on 01/11/2016.
//

#ifndef ODOMETRY_TASK_DRIVECONTROL_H
#define ODOMETRY_TASK_DRIVECONTROL_H

#include <Arduino.h>
#include <Wire.h>

#define MD25ADDRESS         0x58                              // Address of the MD25
#define SPEED1              0x00                              // Byte to send speed to both motors for forward and backwards motion if operated in MODE 2 or 3 and Motor 1 Speed if in MODE 0 or 1
#define SPEED2              0x01                              // Byte to send speed for turn speed if operated in MODE 2 or 3 and Motor 2 Speed if in MODE 0 or 1
#define ENCODERONE          0x02                              // Byte to read motor encoder 1
#define ENCODERTWO          0x06                              // Byte to read motor encoder 2
#define ACCELERATION        0xE                               // Byte to define motor acceleration
#define CMD                 0x10                              // Byte to reset encoder values
#define MODE_SELECTOR       0xF                               // Byte to change between control MODES

class DriveControl {
public:
    DriveControl(bool initialize);

    DriveControl();

    void line(float distance);

    void turn(float radius, float theta, bool dirRight, float turnStopDistance);

private:
    int mode = 2;
    float wheelOffset = 129.75;
    float wheelRadius = 51.5;
    float maxLineSpeed = 75;
    float maxTurnSpeed = 20;
    int accelRate = 1;
    int decelRate = 3;
    float pi = 3.14159265358979323846;
    float lineStopDistance = 145.0;
//    float turnStopDistance = 53;

    void resetEncoders();

    float getDistance1();

    float getDistance2();

    void setSpeed(int speed);

    void setTurn(int turn);

    void setAcceleration(int a);

    void stop();
};

#endif //ODOMETRY_TASK_DRIVECONTROL_H
