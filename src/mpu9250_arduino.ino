//code used here is combination of arduino libraries from MPU9250, SPI, SD, NMEAGPS, and GPSport
#include "MPU9250.h"
#include <SPI.h>
#include <SD.h>
#include <NMEAGPS.h>
#include <GPSport.h>

File myFile;
MPU9250 mpu;
NMEAGPS  gps; 
gps_fix  fix; 

void setup() {
    Serial.begin(9600);
    Wire.begin();
    delay(2000);

    while (!Serial) {
    ;
    }
    Serial.println("Neo-6m gps module initializing");
    gpsPort.begin(9600);
    delay(5000);
    
    Serial.println("Initializing SD card");
    if (!SD.begin(10)) {
    Serial.println("Initialization failed!");
    while (1);
    }
    Serial.println("Initialization done.");



    if (!mpu.setup(0x68)) {  
        while (1) {
            Serial.println("MPU connection failed. Please check your connection");
            delay(5000);
        }
    }

    
    Serial.println("Accel Gyro calibration will start in 5sec.");
    Serial.println("Please leave the device still on the flat plane.");
    mpu.verbose(true);
    delay(5000);
    mpu.calibrateAccelGyro();

    Serial.println("Mag calibration will start in 5sec.");
    Serial.println("Please Wave device until calibration done.");
    delay(5000);
    mpu.calibrateMag();
    mpu.verbose(false);
}

void loop() {
    if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            print_roll_pitch_yaw();
            prev_ms = millis();
        }
    }
    while (gps.available( gpsPort )) {
        fix = gps.read();
    }
}

void print_roll_pitch_yaw() {
    Serial.print("Lat, Lon, Alt: ,");
    Serial.print( fix.latitude(), 6 );
    Serial.print( ',' );
    Serial.print( fix.longitude(), 6 );
    Serial.print( ',' );
    Serial.print( fix.altitude() );
    Serial.print( ',' );
    Serial.print("Yaw, Pitch, Roll: ,");
    Serial.print(mpu.getYaw(), 2);
    Serial.print(", ");
    Serial.print(mpu.getPitch(), 2);
    Serial.print(", ");
    Serial.print(mpu.getRoll(), 2);
    Serial.print(", ");
    Serial.print("Mag : ,");
    Serial.print(mpu.getMagX(), 2);
    Serial.print(", ");
    Serial.print(mpu.getMagY(), 2);
    Serial.print(", ");
    Serial.print(mpu.getMagZ(), 2);
    Serial.print(", ");
    Serial.print("lin_acc = ,");
    Serial.print(mpu.getLinearAccX(), 2);
    Serial.print(", ");
    Serial.print(mpu.getLinearAccY(), 2);
    Serial.print(", ");
    Serial.println(mpu.getLinearAccZ(), 2);


    myFile = SD.open("mpu9250.txt", FILE_WRITE);
    if (myFile) {

        myFile.print("Lat, Lon, Alt: ,");
        myFile.print( fix.latitude(), 6 );
        myFile.print( ',' );
        myFile.print( fix.longitude(), 6 );
        myFile.print( ',' );
        myFile.print( fix.altitude() );
        myFile.print( ',' );
        myFile.print("Yaw, Pitch, Roll: ,");
        myFile.print(mpu.getYaw(), 2);
        myFile.print(", ");
        myFile.print(mpu.getPitch(), 2);
        myFile.print(", ");
        myFile.print(mpu.getRoll(), 2);
        myFile.print(", ");
        myFile.print("Mag : ,");
        myFile.print(mpu.getMagX(), 2);
        myFile.print(", ");
        myFile.print(mpu.getMagY(), 2);
        myFile.print(", ");
        myFile.print(mpu.getMagZ(), 2);
        myFile.print(", ");
        myFile.print("lin_acc = ,");
        myFile.print(mpu.getLinearAccX(), 2);
        myFile.print(", ");
        myFile.print(mpu.getLinearAccY(), 2);
        myFile.print(", ");
        myFile.println(mpu.getLinearAccZ(), 2);
        myFile.close();
        Serial.println("done.");
        } else {
        Serial.println("error opening mpu9250.txt");
        }

}
