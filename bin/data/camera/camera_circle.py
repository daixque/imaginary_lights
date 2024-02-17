import csv
import math

# Parameters
radius = 500
time_steps = range(181, 331)  # 181 to 330 seconds

# Open the file in append mode
with open('camera.csv', 'a', newline='') as file:
    writer = csv.writer(file)

    # Loop over the time steps
    for t in time_steps:
        # Calculate the camera position (circle around the z-axis, at y=10)
        camera_x = radius * math.cos(math.radians(t))
        camera_y = 10
        camera_z = radius * math.sin(math.radians(t))

        # Calculate the camera direction (circle around the z-axis, at y=0)
        lookat_x = radius * math.cos(math.radians(t + 180))  # 180 degrees offset to look at the center
        lookat_y = 0
        lookat_z = radius * math.sin(math.radians(t + 180))  # 180 degrees offset to look at the center

        # Write the row to the CSV file
        writer.writerow([t, camera_x, camera_y, camera_z, lookat_x, lookat_y, lookat_z])