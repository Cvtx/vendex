#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <iostream>

#include "token.h"
#include "options.h"
#include "operations.h"
#include "parameters.h"

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
    InputParser();
    InputParser(const int &argc, char **argv);

    void input(const int &argc, char **argv);
    void parse();
    void reset();

    Token getCmdOption(const std::string &option) const;
    bool cmdOptionExists(const std::string &option) const;
    Token cmdOptionAtPosition(const uint32_t &position) const;

    void printOptions() const;
    void printParameters() const;

private:
    std::vector<OptionToken> options;
    OperationToken operation = OperationToken(Operation::Undefined);
    std::vector<ParameterToken> parameters;

    void parseOptions(const OptionsTokensMap &map);
    void parseOperation(const OperationsTokensMap &map);
    void parseParameters(const ParametersTokensMap &map);

    std::vector<ParameterToken> getParameters();
    OperationToken getOperationToken();
    Operation getOperation();
    std::vector<OptionToken> getOptions();

    const std::string &emptyString() const;
    bool positionInBound(const uint32_t &position) const;
};