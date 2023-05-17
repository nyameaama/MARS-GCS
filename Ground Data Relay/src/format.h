#ifndef FORMAT_H
#define FORMAT_H

#include <string>
#include <unordered_set>

class Format {
private:
    std::unordered_set<std::string> authorizedStrings;

public:
    Format();

    std::string mergeStringAndFloat(const std::string& str, float value);

private:
    bool isStringAuthorized(const std::string& str);
};

#endif  // FORMAT_H