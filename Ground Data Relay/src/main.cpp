#include <Arduino.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>

void saveToCSV(const std::string& filename, int row, int column, double data);
void parseSensorData(const std::string& input, std::string& sensorName, double& value);
bool findRowAndColumn(const DataStructure& data, const Key& key, int& row, int& column);

// Define the data structure for key-value pairs
using Key = std::string;
using Value = std::pair<int, int>;
using DataStructure = std::unordered_map<Key, Value>;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Example input string
    std::string input = "Latitude_8.001248";

    // Variables to store parsed sensor name and value
    std::string sensorName;
    double value;

    // Parse the sensor data
    parseSensorData(input, sensorName, value);

  // Define the data structure
    DataStructure data;
    
    // Insert key-value pairs
    data["Latitude"] = std::make_pair(1, 5);
    data["Longitude"] = std::make_pair(2, 3);
    data["Altitude"] = std::make_pair(3, 6);
    
    // Example string to search
    Key searchKey = sensorName;
    
    // Variables to store the retrieved row and column
    int row, column;
    
    // Call the findRowAndColumn function to search for the string
    if (findRowAndColumn(data, searchKey, row, column)) {
        // Print the retrieved row and column
        std::cout << "Row: " << row << std::endl;
        std::cout << "Column: " << column << std::endl;
        // Save the data to a CSV file
        std::string filename = "data.csv";
        saveToCSV(filename, row, column, value);
    } else {
        std::cout << "String not found in the data structure" << std::endl;
    }
  
}

// Function to save data to a specific row and column in a CSV file
void saveToCSV(const std::string& filename, int row, int column, double data) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        // Write data to the specified row and column
        file.seekp((row - 1) * sizeof(double) + (column - 1) * sizeof(char), std::ios::beg);
        file << data << ",";
        file.close();
        std::cout << "Data saved to CSV file successfully." << std::endl;
    } else {
        std::cerr << "Failed to open CSV file." << std::endl;
    }
}

// Function to parse sensor name and value from the input string
void parseSensorData(const std::string& input, std::string& sensorName, double& value) {
    // Find the position of the underscore
    size_t underscorePos = input.find('_');

    // Check if the underscore exists in the input string
    if (underscorePos != std::string::npos) {
        // Extract the sensor name and value from the input string
        sensorName = input.substr(0, underscorePos);
        std::string valueString = input.substr(underscorePos + 1);

        // Convert the value string to double
        value = std::stod(valueString);
    } else {
        // If the underscore is not found, set default values
        sensorName = "";
        value = 0.0;
    }
}

// Function to search for a string and retrieve its row and column
bool findRowAndColumn(const DataStructure& data, const Key& key, int& row, int& column) {
    // Check if the key exists in the data structure
    auto it = data.find(key);
    if (it != data.end()) {
        // If the key exists, retrieve the row and column
        const Value& value = it->second;
        row = value.first;
        column = value.second;
        return true;
    }
    return false;
}