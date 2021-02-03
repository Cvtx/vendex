#include "../include/token.h"

std::string Token::getValue()
{
    return this->value;
}

TokenType Token::getType()
{
    return this->type;
}

Token::Token(const std::string &value, TokenType type)
{
    this->value = value;
    this->type = type;
}