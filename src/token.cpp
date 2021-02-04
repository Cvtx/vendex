#include "../include/token.h"

Token::Token(const std::string &value, TokenType type)
{
    this->value = value;
    this->type = type;
}

std::string Token::getValue() const
{
    return this->value;
}

TokenType Token::getType() const
{
    return this->type;
}