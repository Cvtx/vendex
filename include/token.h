#pragma once
#include <map>
#include "options.h"
#include "operations.h"

enum class TokenType
{
    Option,
    Operation,
    Parameter
};

// class IToken
// {
// public:
//     virtual std::string getValue() = 0;
//     virtual int getName() = 0;
// };

class IToken
{
public:
    virtual std::string getValue() = 0;
    virtual TokenType getType() = 0;
};

class Token : IToken
{
public:
    Token(const std::string &value, TokenType type);
    std::string getValue();
    TokenType getType();

protected:
    std::string value;
    TokenType type;
};