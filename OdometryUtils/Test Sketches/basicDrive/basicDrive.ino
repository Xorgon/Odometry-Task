#include <Wire.h>                                             // Calls for I2C bus library
#include <Indicate.h>

#define MD25ADDRESS         0x58                              // Address of the MD25
#define SPEED1              0x00                              // Byte to send speed to both motors for forward and backwards motion if operated in MODE 2 or 3 and Motor 1 Speed if in MODE 0 or 1
#define SPEED2              0x01                              // Byte to send speed for turn speed if operated in MODE 2 or 3 and Motor 2 Speed if in MODE 0 or 1
#define ENCODERONE          0x02                              // Byte to read motor encoder 1
#define ENCODERTWO          0x06                              // Byte to read motor encoder 2
#define ACCELERATION        0xE                               // Byte to define motor acceleration
#define CMD                 0x10                              // Byte to reset encoder values
#define MODE_SELECTOR       0xF                               // Byte to change between control MODES

int Mode = 2;                                                 // MODE in which the MD25 will operate selector value
float Wheel_1_Distance_CM = 0;                                // Wheel 1 travel distance variable
float Wheel_2_Distance_CM = 0;                                // Wheel 2 travel distance variable
Indicate indicate;



void setup(){
    Wire.begin();                                               // Begin I2C bus
    Serial.begin(9600);                                         // Begin serial
    delay(100);                                                 // Wait for everything to power up
    indicate = Indicate(2, 9);
    Wire.beginTransmission(MD25ADDRESS);                        // Set MD25 operation MODE
    Wire.write(MODE_SELECTOR);
    Wire.write(Mode);
    Wire.endTransmission();

    Wire.beginTransmission(MD25ADDRESS);                        // Set MD25 operation MODE
    Wire.write(CMD);
    Wire.write(0x36);
    Wire.endTransmission();

    encodeReset();                                              // Cals a function that resets the encoder values to 0
}

void loop(){

    Wire.beginTransmission(MD25ADDRESS);                      // Sets a combined motor speed value
    Wire.write(SPEED1);
    Wire.write(188);
    Wire.endTransmission();
    indicate.doIndicate();
    delay(10000);
    indicate.doIndicate();
    Wire.beginTransmission(MD25ADDRESS);                      // Sets a combined motor speed value
    Wire.write(SPEED1);
    Wire.write(128);
    Wire.endTransmission();
    indicate.doIndicate();
    delay(2000);
    indicate.doIndicate();
}

void encodeReset(){                                         // This function resets the encoder values to 0
    Wire.beginTransmission(MD25ADDRESS);
    Wire.write(CMD);
    Wire.write(0x20);
    Wire.endTransmission();
    delay(50);
}