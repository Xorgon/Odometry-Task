#include <Arduino.h>
#include <DriveControl.h>

DriveControl driveControl;

void setup() {
    driveControl = DriveControl(true);
}

void loop() {
    driveControl.line(180);
    driveControl.turn(180, 90, true);
}