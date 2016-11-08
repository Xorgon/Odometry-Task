#include <Arduino.h>
#include <DriveControl.h>
#include <Dispenser.h>
#include <Indicate.h>

DriveControl driveControl;
Dispenser dispenser;
Indicate indicate;

bool done;

void setup() {
    driveControl = DriveControl(true);
    dispenser = Dispenser(11);
    indicate = Indicate(2, 9);
    indicate.doIndicate();
    done = false;
}

void loop() {
    if (!done) {
        driveControl.line(200);
        indicate.doIndicate();
        dispenser.dispense();
        driveControl.turn(0, 180, true);
        indicate.doIndicate();
        driveControl.line(200);
        indicate.doIndicate();
        driveControl.turn(0, 180, false);
        indicate.doIndicate();
        done = true;
    }

//    driveControl.turn(180, 90, true);
//    indicate.doIndicate();
}