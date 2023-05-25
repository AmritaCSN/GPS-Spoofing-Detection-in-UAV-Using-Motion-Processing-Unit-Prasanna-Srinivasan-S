# GPS-Spoofing-Detection-in-UAV-Using-Motion-Processing-Unit-Prasanna-Srinivasan-S

mpu9250_arduino:

libraries used MPU9250, SPI, SD, NMEAGPS, and GPSport

Dataset is generated with features of latitude, longitude, altitude, yaw, pitch, roll, x-axis magnetic field strength, y-axis magnetic field strength, z-axis magnetic field strength, x-axis acceleration, y-axis acceleration, z-axis acceleration.

gps_spoofing_detection:

Generated dataset with features of x-axis magnetic field strength, y-axis magnetic field strength, z-axis magnetic field strength will be compared with magnetometer dataset to detect gps spoofing.

gps_coordinates_retrieval:

Implementation of dead reckoning with MPU9250 dataset for flight path
