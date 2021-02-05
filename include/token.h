#pragma once
#include <map>
#include <string>

#include "options.h"
#include "operations.h"
#include "parameters.h"

enum class TokenType
{
    Option,
    Operation,
    Parameter
};

class IToken
{
public:
    virtual std::string getValue() const = 0;
    virtual TokenType getType() const = 0;
};

class Token : public IToken
{
public:
    Token(const std::string &value, TokenType type);
    std::string getValue() const;
    TokenType getType() const;

protected:
    std::string value;
    TokenType type;
};

class OptionToken : public Token
{
public:
    OptionToken(const std::string &value);

    Option getName() const;
    void setName(Option option);

protected:
    Option name = Option::Undefined;
};

class OperationToken : public Token
{
public:
    OperationToken(Operation operation);
    OperationToken(const std::string &value);
    OperationToken(const std::string &value, Operation operation);

    Operation getName() const;
    void setName(Operation operation);

protected:
    Operation name = Operation::Undefined;
};

class ParameterToken : public Token
{
public:
    ParameterToken(const std::string &value);

    Parameter getName() const;
    void setName(Parameter parameter);

protected:
    Parameter name = Parameter::Undefined;
};