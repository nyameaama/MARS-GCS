#ifndef STRINGPARSER_H
#define STRINGPARSER_H

#include <string>

class StringParser {
private:
    std::string inputString;
    std::string extractedString;
    int extractedNumber;

public:
    StringParser(const std::string& input);

    void parse();

    std::string getExtractedString() const;
    int getExtractedNumber() const;
};

#endif