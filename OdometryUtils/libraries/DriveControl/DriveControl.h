// Created by Elijah Andrews on behalf of Team A

#ifndef ODOMETRY_TASK_DRIVECONTROL_H
#define ODOMETRY_TASK_DRIVECONTROL_H

#include <Arduino.h>
#include <Wire.h>

#define MD25ADDRESS         0x58                              // Address of the MD25
#define SPEED1              0x00                              // Byte to send speed to both motors for forward and backward motion if operated in MODE 2 or 3 and Motor 1 Speed if in MODE 0 or 1
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

    void turn(float radius, float theta, bool dirRight);

private:
    int mode = 2; // MD25 mode
    float wheelOffset = 131; // Wheel offset from centre of robot to centre-line of wheel.
    float wheelRadius = 51.5; // Radius of a wheel.
    float maxLineSpeed = 25; // Max speed in a line.
    float maxTurnSpeed = 20; // Max speed in a turn.
    int accelRate = 1; // Acceleration rate.
    int decelRate = 3; // Deceleration rate.
    float pi = 3.14159265358979323846;
    float stoppingDistance = 20.0; //145.0;

    void resetEncoders();

    float getDistance1();

    float getDistance2();

    void setSpeed(int speed);

    void setTurn(int turn);

    void setAcceleration(int a);

    void stop();
};

#endif //ODOMETRY_TASK_DRIVECONTROL_H
