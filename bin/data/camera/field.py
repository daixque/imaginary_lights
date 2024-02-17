import csv
import math

# Parameters
radius = 800
time_steps = range(331)  # 0 to 330 seconds

# Open the file in write mode
with open('camera_field2.csv', 'w', newline='') as file:
    writer = csv.writer(file)

    # Write the header
    writer.writerow(['time', 'camera_x', 'camera_y', 'camera_z', 'lookat_x', 'lookat_y', 'lookat_z'])

    # Loop over the time steps
    for t in time_steps:
        # Calculate the camera position (circle around the z-axis, at y=10)
        camera_x = radius * math.sin(math.radians(t * 2))
        camera_y = 20
        camera_z = radius * math.cos(math.radians(t * 2))

        # Calculate the camera direction (circle around the z-axis, at y=0)
        lookat_x = radius * math.cos(math.radians(t * 3 + 180))  # 180 degrees offset to look at the center
        lookat_y = 0
        lookat_z = radius * math.sin(math.radians(t * 3 + 180))  # 180 degrees offset to look at the center

        # Write the row to the CSV file
        writer.writerow([t, camera_x, camera_y, camera_z, lookat_x, lookat_y, lookat_z])