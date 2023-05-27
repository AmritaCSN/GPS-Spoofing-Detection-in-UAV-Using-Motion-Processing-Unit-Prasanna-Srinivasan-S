# Reference : https://stackoverflow.com/questions/19727298/my-algorithm-to-calculate-position-of-smartphone-gps-and-sensors/19764828#19764828
import math
import pandas as pd

initial_lat = 12.832712
initial_lon = 80.050148

earth_radius = 6371 
time_step = 0.18 

initial_velocity = 0
theta = math.pi/4

mpudata = pd.read_csv(r'C:\Users\iampr\Downloads\major_project\dataset\mpusensor.TXT')
mpudata_len = len(mpudata)+1

for i in range (0,mpudata_len):
    x_axis_acc, y_axis_acc, z_axis_acc = pd.read_csv(r'C:\Users\iampr\Downloads\major_project\dataset\mpusensor.TXT', usecols=['-0.60', ' -0.24', ' 0.05'])
    x_axis_gyr, y_axis_gyr, z_axis_gyr = pd.read_csv(r'C:\Users\iampr\Downloads\major_project\dataset\mpusensor.TXT', usecols=['-20.78', ' -10.14', ' -26.12'])
    x_axis_acc=float(x_axis_acc)
    y_axis_acc=float(y_axis_acc)
    z_axis_acc=float(z_axis_acc)
    x_axis_gyr=float(x_axis_gyr)
    y_axis_gyr=float(y_axis_gyr)
    z_axis_gyr=float(z_axis_gyr)
   
    mag_acc_vector = math.sqrt(x_axis_acc**2 + y_axis_acc**2 + z_axis_acc**2)
    avg_angular_velocity = (x_axis_gyr*time_step + y_axis_gyr*time_step + z_axis_gyr*time_step)/3

    initial_velocity += mag_acc_vector*time_step
    theta += avg_angular_velocity / math.cos(initial_lat)
    
    initial_lat += (initial_velocity*time_step/earth_radius) * math.cos(theta)
    initial_lon += (initial_velocity*time_step/earth_radius) * math.sin(theta) / math.cos(initial_lat)
    
    with open(r'C:\Users\iampr\Downloads\major_project\dataset\new_gps_coordinates.txt', 'a') as f:
        f.write(str(initial_lat))
        f.write(',')
        f.write(str(initial_lon))
        f.write("\n")
        f.close()

    print("Current position: ", initial_lat, initial_lon)
