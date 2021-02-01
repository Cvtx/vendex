#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

class InputParser
{
public:
    InputParser(int &argc, char **argv);
    const std::string &getCmdOption(const std::string &option) const;
    bool cmdOptionExists(const std::string &option) const;
    const std::string &cmdOptionAtPosition(const uint32_t &position) const;
    bool haveVerbalOption() const;

private:
    std::vector<std::string> tokens;
    const std::string &emptyString() const;
    bool positionInBound(const uint32_t &position) const;
};