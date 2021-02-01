#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <iostream>

/**
 * @brief Parses command-line options and stores them.
 * 
 */
class InputParser
{
public:
    InputParser(int &argc, char **argv);
    const std::string &getCmdOption(const std::string &option) const;
    bool cmdOptionExists(const std::string &option) const;
    const std::string &cmdOptionAtPosition(const uint32_t &position) const;
    bool hasVerbalOption() const;
    void printOptions() const;

private:
    std::vector<std::string> tokens;
    const std::string &emptyString() const;
    bool positionInBound(const uint32_t &position) const;
};