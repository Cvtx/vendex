#pragma once
#include <map>
#include <string>

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
    virtual std::string getValue() const = 0;
    virtual TokenType getType() const = 0;
};

class Token
{
public:
    Token(const std::string &value, TokenType type);
    std::string getValue() const;
    TokenType getType() const;

protected:
    std::string value;
    TokenType type;
};