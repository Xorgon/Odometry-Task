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
        driveControl.line(260);
//        driveControl.turn(260.0, 90.0, false, 0.0);
        done = true;
    }
}