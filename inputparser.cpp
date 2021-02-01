#include "inputparser.h"

InputParser::InputParser(int &argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        //this->tokens.push_back(std::string(argv[i]));
    }
}

const std::string &InputParser::getCmdOption(const std::string &option) const
{
    std::vector<std::string>::const_iterator itr;
    itr = std::find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end())
    {
        return *itr;
    }
    return emptyString();
}

bool InputParser::cmdOptionExists(const std::string &option) const
{
    return std::find(this->tokens.begin(), this->tokens.end(), option) != this->tokens.end();
}

const std::string &InputParser::cmdOptionAtPosition(const uint32_t &position) const
{
    if (!positionInBound(position))
    {
        return emptyString();
    }

    /* Return token at position */
    return this->tokens[position];
}

/* Check if token with such position can exist*/
bool InputParser::positionInBound(const uint32_t &position) const
{
    return (position >= 0) && (position <= this->tokens.size());
}

/* Returns empty string */
const std::string &InputParser::emptyString() const
{
    static const std::string empty_string("");
    return empty_string;
}

bool InputParser::haveVerbalOption() const
{
    const std::string verbal = std::string("-v");
    return cmdOptionAtPosition(2) == verbal;
}