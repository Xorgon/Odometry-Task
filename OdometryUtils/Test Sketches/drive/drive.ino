#include <Arduino.h>
#include <DriveControl.h>
#include <Indicate.h>

DriveControl driveControl;
Indicate indicate;

bool done;

void setup() {
    driveControl = DriveControl(true);
    indicate = Indicate(2, 9);
    indicate.doIndicate();
    done = false;
}

void loop() {
    if (!done) {
//        driveControl.turn(0, 90, true);
        driveControl.line(500);
//        indicate.doIndicate();
//        driveControl.turn(0, 90, false);
//        indicate.doIndicate();
//        driveControl.turn(0, 540, true);
//        indicate.doIndicate();
//        delay(250);
        indicate.doIndicate();
        done = true;
    }

//    driveControl.turn(180, 90, true);
//    indicate.doIndicate();
}