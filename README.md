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

step 2 : arduino ide > sketch > include library > manage libraries > in library manager(ctrl+shift+I) search for libraries MPU9250, SPI, SD, NMEAGPS, and GPSport > install

step 3 : Upload the mpu9250_arduino.ino to arduino

step 4 : MPU Dataset with features (lat, long, alt, yaw, pitch, roll, x-axis mag, y-axis mag, z-axis mag, x-axis acc, y-axis acc, z-axis acc) will be generated and stored in sd card slot

step 5 : MPU Dataset will be used for training and testing the models in gps_spoofing_detection.ipynb, in order to determine gps spoofing with respect to Magnetometer Dataset.png

step 6 : MPU Dataset with features (yaw, pitch, roll, x-axis acc, y-axis acc, z-axis acc) will be used to determine the GPS coordinates by dead reckoning via gps_coordinates_retrieval.py

**References**
1) code used in mpu9250_arduino.ino is combination of arduino libraries from MPU9250, SPI, SD, NMEAGPS, and GPSport
2) code used in gps_coordinates_retrieval.py is referenced from https://stackoverflow.com/questions/19727298/my-algorithm-to-calculate-position-of-smartphone-gps-and-sensors/19764828#19764828

**Links to buy modules, generated on 28/05/2023**


https://www.amazon.in/ARDUINO-MKR1000-WiFi-with-HEADERS/dp/B071LRYYHH/ref=sr_1_3?keywords=arduino+mkr+wifi+1010&qid=1685244346&sprefix=Arduino+mkr%2Caps%2C393&sr=8-3
https://www.amazon.in/REES52-MPU6500-MPU9250-Acceleration-Interface/dp/B07F8PLM5M/ref=sr_1_1?crid=BUZYKP64A0Z1&keywords=mpu9250&qid=1685244374&sprefix=mpu9250%2Caps%2C299&sr=8-1
https://www.amazon.in/Robodo-MO20-Module-Reader-Arduino/dp/B073Q2HY3Q/ref=sr_1_2?keywords=arduino+sd+card+module&qid=1685244475&sprefix=ardunio+sd%2Caps%2C292&sr=8-2
https://www.amazon.in/Robotbanao-NEO-6M-GPS-Module-Pack/dp/B09FM25ZMT/ref=sr_1_1_sspa?keywords=neo+6m+gps+module&qid=1685244503&sprefix=neo+%2Caps%2C306&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1
