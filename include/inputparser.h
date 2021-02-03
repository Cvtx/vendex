#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <iostream>

#include "options.h"
#include "operations.h"

/**
 * Terminology explained:
 * Token is every string that is passed to executable e.g. in 
 * $ ./vendex -v create tag 
 * tokens will be -v, create, tag. 
 * Also, very first token is always path to executable, which included by default.
 * 
 * Option is a token that starts with - (dash) e.g. -v.
 * Operation is a token that don't start with - (dash) e.g. create.   
 * 
 */

/**
 * @brief Parses command-line options and stores them.
 * 
 */
class InputParser
{
public:
    InputParser(const int &argc, char **argv, const OperationsTokensMap &operations, const OptionsTokensMap &options);
    const std::string &getCmdOption(const std::string &option) const;
    bool cmdOptionExists(const std::string &option) const;
    const std::string &cmdOptionAtPosition(const uint32_t &position) const;
    bool hasVerbalOption() const;
    void printOptions() const;

    Operation parseOperation(const OperationsTokensMap &operations, const std::string &token);
    Option parseOption(const OptionsTokensMap &options, const std::string token);

private:
    std::vector<std::string> tokens;
    const std::string &emptyString() const;
    bool positionInBound(const uint32_t &position) const;
};