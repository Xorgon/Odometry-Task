#include <Arduino.h>
#include <DriveControl.h>
#include <Indicate.h>

DriveControl driveControl;
Indicate indicate;

void setup() {
    driveControl = DriveControl(true);
    indicate = Indicate(2, 9);
}

void loop() {
    driveControl.line(180);
    indicate.doIndicate();
    driveControl.turn(180, 90, true);
    indicate.doIndicate();
}