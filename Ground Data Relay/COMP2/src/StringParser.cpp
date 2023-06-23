#include "StringParser.h"
#include <sstream>

StringParser::StringParser(const std::string& input) : inputString(input), extractedNumber(0) {}

void StringParser::parse() {
    std::stringstream ss(inputString);
    std::string temp;
    
    // Extract the string part (before the colon)
    std::getline(ss, temp, ':');
    extractedString = temp;

    // Extract the number part (after the colon)
    std::getline(ss, temp);
    extractedNumber = std::stoi(temp);
}

std::string StringParser::getExtractedString() const {
    return extractedString;
}

int StringParser::getExtractedNumber() const {
    return extractedNumber;
}