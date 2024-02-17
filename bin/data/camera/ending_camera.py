import numpy as np
import pandas as pd

def output_camera_movement_to_csv(filename):
    # Initialize the data
    data = []

    start_position = np.array([0, 10, 500])
    end_position = np.array([0, 1800, 0])
    target_position = np.array([0, 0, 0])

    for t in range(21):
        progress = t / 20
        time = progress * 20

        # Interpolate the position
        position = start_position * (1 - progress) + end_position * progress

        # Calculate the rotation matrix
        rotation = np.array([
            [np.cos(2 * np.pi * progress), 0, np.sin(2 * np.pi * progress)],
            [0, 1, 0],
            [-np.sin(2 * np.pi * progress), 0, np.cos(2 * np.pi * progress)]
        ])

        # Apply the rotation to the position
        rotated_position = rotation @ position

        # Calculate the direction
        direction = target_position - rotated_position
        direction = direction / np.linalg.norm(direction)

        # Append the time, position, and direction to the data
        data.append([time] + list(rotated_position) + list(direction))

    # Convert the data to a DataFrame and write it to a CSV file
    df = pd.DataFrame(data, columns=['time', 'x', 'y', 'z', 'direction_x', 'direction_y', 'direction_z'])
    df.to_csv(filename, index=False)

output_camera_movement_to_csv("ending_camera.csv")