#include "../include/inputparser.h"

/**
 * @brief Construct a new Input Parser:: Input Parser object
 * 
 * @param argc Amount of options
 * @param argv Options
 */
InputParser::InputParser(int &argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        this->tokens.push_back(std::string(argv[i]));
    }
}

/**
 * @brief Gives parameter of the option
 * 
 * @param option
 * @return const std::string& parameter
 */
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

/**
 * @brief Checks if options exist
 * 
 * @param option 
 * @return true if option exist
 * @return false if option don't exist
 */
bool InputParser::cmdOptionExists(const std::string &option) const
{
    return std::find(this->tokens.begin(), this->tokens.end(), option) != this->tokens.end();
}

/**
 * @brief Return option at certain position
 * 
 * @param position 
 * @return const std::string& option or empty string if position is invalid
 */
const std::string &InputParser::cmdOptionAtPosition(const uint32_t &position) const
{
    if (!positionInBound(position))
    {
        return emptyString();
    }

    /* Return token at position */
    return this->tokens[position];
}

/**
 * @brief Checks if position is in bound of tokens amount
 * 
 * @param position 
 * @return true if position is in bound of tokens amount
 * @return false if position is out of bound
 */
bool InputParser::positionInBound(const uint32_t &position) const
{
    return (position >= 0) && (position <= this->tokens.size());
}

/**
 * @brief Return empty string
 * 
 * @return const std::string& 
 */
const std::string &InputParser::emptyString() const
{
    static const std::string empty_string("");
    return empty_string;
}

/**
 * @brief Checks for verbal option
 * 
 * @return true if verbal option exist
 * @return false if verbal option don't exist
 */
bool InputParser::hasVerbalOption() const
{
    const std::string verbal = std::string("-v");
    return cmdOptionAtPosition(2) == verbal;
}

/**
 * @brief Prints all parsed options
 * 
 */
void InputParser::printOptions() const
{
    int size = this->tokens.size();
    if (size == 0)
    {
        std::cout << "There is no passed options.";
    }
    else
    {
        std::cout << "Passed options are: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << " " << this->tokens[i];
        }
    }
    std::cout << std::endl;
}