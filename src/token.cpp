#include "../include/token.h"

/**
 * @brief Return value. 
 * It will work in all classes that inherit this class 
 * with public or protected specifier.
 * 
 * @return std::string 
 */
std::string AToken::getValue()
{
    return this->value;
}

int AToken::getName()
{
    return this->name;
}

TokenType OptionToken::getType()
{
    return TokenType::Option;
}

OptionToken::OptionToken(const std::string &value, TokenOption name)
{
    this->value = value;
    this->name = name;
}