// Created by Elijah Andrews on behalf of Team A

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
    dispenser = Dispenser(11); // Initializes a dispenser on Pin 11.
    indicate = Indicate(2, 9); // Initializes indicator with LED on Pin 2 and piezo on Pin 9.
    indicate.doIndicate(); // Indicates completed setup.
    done = false;
}

void loop() {
    if (!done) {
        driveControl.line(340); // Drives in a straight line 340mm.
        indicate.doIndicate(); // Point 1
        driveControl.turn(0, 93, true); // Drives in a turn, radius 0, through 93 degrees to the right.
        driveControl.line(260);
        indicate.doIndicate(); // Point 2
        dispenser.dispense();
        driveControl.turn(0, 93, false);
        driveControl.line(500);
        indicate.doIndicate(); // Point 3
        driveControl.turn(0, 91, false);
        driveControl.turn(260, 91, true);
        indicate.doIndicate(); // Point 4
        dispenser.dispense();
        driveControl.turn(0, 83, true);
        driveControl.line(660 - 22);
        indicate.doIndicate(); // Point 5
        driveControl.turn(0, 90, false);
        driveControl.line(400 - 20);
        indicate.doIndicate(); // Point 6
        dispenser.dispense();
        driveControl.turn(0, 92, false);
        driveControl.line(400 + 7);
        indicate.doIndicate(); // Point 7
        driveControl.turn(0, 92, false);
        driveControl.line(400);
        indicate.doIndicate(); // Point 8
        dispenser.dispense();
        driveControl.turn(0, 42, false);
        driveControl.line(622.3);
        indicate.doIndicate(); // Point 9
        driveControl.turn(0, 141, false);
        driveControl.line(180);
        indicate.doIndicate(); // Point 10
        dispenser.dispense();
        driveControl.turn(0, 91, true);
        driveControl.turn(180, 285, true);
        indicate.doIndicate(); // Point 11
        driveControl.turn(0, 143.2, false);
        driveControl.line(358.7);
        indicate.doIndicate(); // Point 12
        driveControl.line(428.0);
        indicate.doIndicate(); // HOME RUN!
        done = true;
    }
}