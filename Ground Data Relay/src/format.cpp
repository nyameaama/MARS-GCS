#include "format.h"

#include <stdexcept>

Format::Format() {
    // Fill the reference table with authorized strings
    authorizedStrings.insert("Latitude");
    authorizedStrings.insert("Longitude");
    authorizedStrings.insert("Altitude");
    // Add more authorized strings as needed
}

std::string Format::mergeStringAndFloat(const std::string& str, float value) {
    if (!isStringAuthorized(str)) {
        //throw std::invalid_argument("Input string not authorized.");
    }
    std::string mergedString = str + "_" + std::to_string(value);
    return mergedString;
}

bool Format::isStringAuthorized(const std::string& str) {
    return authorizedStrings.count(str) > 0;
}