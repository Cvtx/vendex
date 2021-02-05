#include "../include/inputparser.h"

InputParser::InputParser()
{
}

/**
 * @brief Construct a new Input Parser:: Input Parser object
 * 
 * @param argc amount of arguments 
 * @param argv arguments
 * @param operations map to match token with operation
 * @param options map to match token with option
 */
InputParser::InputParser(const int &argc, char **argv)
{
    input(argc, argv);
}

void InputParser::input(const int &argc, char **argv)
{
    reset();

    /* Parsing arguments ignoring first argument which is path to executable */
    int i = 1;

    /* Parsing options */
    while ((i < argc) && (argv[i][0] == OPTION_DASH))
    {

        this->options.push_back(OptionToken(argv[i]));
        i++;
    }

    /* Parsing operation */
    if (i < argc)
    {
        this->operation = OperationToken(argv[i]);
        i++;
    }

    /* Parsing parameters */
    while (i < argc)
    {
        this->parameters.push_back(ParameterToken(argv[i]));
        i++;
    }
}

void InputParser::parse()
{
    //parseOptions();
    parseOperation(Operations);
    //parseParameters();
}

void InputParser::parseOperation(const OperationsTokensMap &map)
{
    OperationsTokensMap::const_iterator iterator = map.find(this->operation.getValue());

    if (iterator == map.end())
    {
        this->operation.setName(Operation::Undefined);
    }
    else
    {
        /* Return operation */
        this->operation.setName(iterator->second);
    }
}

void InputParser::reset()
{
    this->options.clear();
    this->operation = Operation::Undefined;
    this->parameters.clear();
}

std::vector<ParameterToken> InputParser::getParameters()
{
    return this->parameters;
}
OperationToken InputParser::getOperationToken()
{
    return this->operation;
}
Operation InputParser::getOperation()
{
    return this->operation.getName();
}
std::vector<OptionToken> InputParser::getOptions()
{
    return this->options;
}

void InputParser::parseOptions(const OptionsTokensMap &map)
{
    for (OptionToken &option : this->options)
    {
        OptionsTokensMap::const_iterator iterator = map.find(option.getValue());

        if (iterator == map.end())
        {
            option.setName(Option::Undefined);
        }
        else
        {
            option.setName(iterator->second);
        }
    }
}

void InputParser::parseParameters(const ParametersTokensMap &map)
{
    for (ParameterToken &parameter : this->parameters)
    {
        ParametersTokensMap::const_iterator iterator = map.find(parameter.getValue());

        if (iterator == map.end())
        {
            parameter.setName(Parameter::Undefined);
        }
        else
        {
            parameter.setName(iterator->second);
        }
    }
}

/**
 * @brief Gives parameter of the option 
 * 
 * @param option
 * @return const std::string& parameter
 */
Token InputParser::getCmdOption(const std::string &option) const
{
    // std::vector<Token>::iterator itr;
    // itr = std::find(this->tokens.begin(), this->tokens.end(), option);
    // if (itr != this->tokens.end() && ++itr != this->tokens.end())
    // {
    //     return *itr;
    // }
    Token token("", TokenType::Option);
    return token;
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
    return false;
    //return std::find(this->tokens.begin(), this->tokens.end(), option) != this->tokens.end();
}

/**
 * @brief Return option at certain position
 * 
 * @param position 
 * @return const std::string& option or empty string if position is invalid
 */
Token InputParser::cmdOptionAtPosition(const uint32_t &position) const
{
    // if (positionInBound(position))
    // {
    //     /* Return token at position */
    //     return this->tokens[position];
    // }

    // /* Else return empty string */
    // return Token("", TokenType::Option);
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
    //return (position >= 0) && (position <= this->tokens.size());
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
 * @brief Prints all parsed tokens
 * 
 */
void InputParser::printOptions() const
{
    if (this->options.size() == 0)
    {
        std::cout << "There is no passed options.";
    }
    else
    {
        std::cout << "Passed options are: ";
        for (int i = 0; i < this->options.size(); i++)
        {
            std::cout << " " << (this->options[i].getValue());
        }
    }
    std::cout << std::endl;
}

void InputParser::printParameters() const
{
    if (this->parameters.size() == 0)
    {
        std::cout << "There is no passed parameters.";
    }
    else
    {
        std::cout << "Passed parameters are: ";
        for (int i = 0; i < this->parameters.size(); i++)
        {
            std::cout << " " << (this->parameters[i].getValue());
        }
    }
    std::cout << std::endl;
}