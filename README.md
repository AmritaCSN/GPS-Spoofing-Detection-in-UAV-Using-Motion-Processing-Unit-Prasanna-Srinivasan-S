# GPS-Spoofing-Detection-in-UAV-Using-Motion-Processing-Unit-Prasanna-Srinivasan-S

**mpu9250_arduino**

libraries used MPU9250, SPI, SD, NMEAGPS, and GPSport

Dataset is generated with features of latitude, longitude, altitude, yaw, pitch, roll, x-axis magnetic field strength, y-axis magnetic field strength, z-axis magnetic field strength, x-axis acceleration, y-axis acceleration, z-axis acceleration.

**gps_spoofing_detection**

Generated dataset with features of x-axis magnetic field strength, y-axis magnetic field strength, z-axis magnetic field strength will be compared with magnetometer dataset to detect gps spoofing.

**gps_coordinates_retrieval**

Implementation of dead reckoning with MPU9250 dataset for flight path

**Procedure**

step 1 : Connect MPU-9250, SD Card Module and NEO-6M GPS modules to Arduino MKR WiFi 1010 as shown in the MPU-9250 Experiment Setup.png

step 2 : Upload the mpu9250_arduino.ino to arduino

step 3 : MPU Dataset with features (lat, long, alt, yaw, pitch, roll, x-axis mag, y-axis mag, z-axis mag, x-axis acc, y-axis acc, z-axis acc) will be generated and stored in sd card slot

step 4 : MPU Dataset will be used for training and testing the models in gps_spoofing_detection.ipynb, in order to determine gps spoofing with respect to Magnetometer Dataset.png

step 5 : MPU Dataset with features (yaw, pitch, roll, x-axis acc, y-axis acc, z-axis acc) will be used to determine the GPS coordinates by dead reckoning via gps_coordinates_retrieval.py

**References**
1) code used in mpu9250_arduino.ino is combination of arduino libraries from MPU9250, SPI, SD, NMEAGPS, and GPSport
2) code used in gps_coordinates_retrieval.py is referenced from https://stackoverflow.com/questions/19727298/my-algorithm-to-calculate-position-of-smartphone-gps-and-sensors/19764828#19764828
