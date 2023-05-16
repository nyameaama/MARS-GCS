import csv

# Define the data structure
data = {
    "Latitude": (5,2),
    "Longitude": (4, 2),
    "Altitude": (3, 2),
    "Throttle": (1,2),
    "Velocity": (2, 2),
    "Satellites": (6, 2),
    "Pitch": (7,2),
    "Roll": (8, 2),
    "Yaw": (9, 2),
    "VehicleState": (10,2),
    "AngleX": (11, 2),
    "AngleY": (12, 2),
    "AngleZ": (13,2),
    "motorFL": (14, 2),
    "motorFR": (15, 2),
    "motorRL": (16,2),
    "motorRR": (17, 2)
}

def update_csv_cell(filename, row, column, value):
    # Read the existing data from the CSV file
    with open(filename, 'r') as file:
        reader = csv.reader(file)
        lines = list(reader)

    # Update the value in the specified row and column
    if row <= len(lines) and column <= len(lines[row - 1]):
        lines[row - 1][column - 1] = str(value)
    else:
        print("Invalid row or column.")

    # Write the updated data back to the CSV file
    with open(filename, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(lines)

def parse_sensor_data(input_str):
    sensor_name, value = input_str.split('_')
    return sensor_name, float(value)

def find_row_and_column(data, key):
    if key in data:
        return data[key]
    return None

def format_(_dataNoFormat):
    # Parse the sensor data
    sensor_name, value = parse_sensor_data(_dataNoFormat)

    # Example string to search
    search_key = sensor_name

    # Call the find_row_and_column function to search for the string
    result = find_row_and_column(data, search_key)
    if result is not None:
        row, column = result
        # Update the data in the CSV file
        filename = '/Users/nyameaama/Documents/MARS-GCS/Ground_App/data.csv'
        update_csv_cell(filename, row, column, value)
    else:
        print("String not found in the data structure")
