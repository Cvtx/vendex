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

OptionToken::OptionToken(const std::string &value) : Token(value, TokenType::Option)
{
}

Option OptionToken::getName() const
{
    return this->name;
}

OperationToken::OperationToken(const std::string &value) : Token(value, TokenType::Operation)
{
}

OperationToken::OperationToken(Operation operation) : Token("", TokenType::Operation)
{
    this->name = operation;
}

OperationToken::OperationToken(const std::string &value, Operation operation) : Token(value, TokenType::Operation)
{
    this->name = operation;
}

void OperationToken::setName(Operation operation)
{
    this->name = operation;
}

Operation OperationToken::getName() const
{
    return this->name;
}

ParameterToken::ParameterToken(const std::string &value) : Token(value, TokenType::Parameter)
{
}

Parameter ParameterToken::getName() const
{
    return this->name;
}

void OptionToken::setName(Option option)
{
    this->name = option;
}

void ParameterToken::setName(Parameter parameter)
{
    this->name = parameter;
}