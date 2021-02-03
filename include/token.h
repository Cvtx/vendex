#pragma once
#include <map>
#include "options.h"
#include "operations.h"

enum TokenName : int
{
    Undefined,
    /* Options */
    /* Operations */
    CreateDB,
    DeleteDB,
    AddFile,
    DeleteFile,
    ExportFile
    /* Parameter */
};

enum TokenOption : int
{
    Verbal
};

// std::map<TokenName, TokenType> map{
//     //{, TokenType::Option}};
// };

enum class TokenType
{
    Option,
    Operation,
    Parameter
};

class IToken
{
public:
    virtual TokenType getType() = 0;
    virtual std::string getValue() = 0;
    virtual int getName() = 0;
    /* 
        It may be wise to make getName() as the part
        of this interface, because it appears in every derived class
        although we will never use it a part of the interface.

        Also making getName() a part of interface is not easy.
        As i know, we should use static to emulate enums and return int
        in getName(), which is not great solution imo;
    */
};

class AToken : IToken
{
public:
    std::string getValue();
    int getName();

protected:
    std::string value;
    int name;
};

class OptionToken : public AToken
{
public:
    OptionToken(const std::string &value, TokenOption name);
    TokenType getType();
    int getName()
    {
        return TokenOption(this->name);
    }
};

class OperationToken : public AToken
{
public:
    TokenType getType();
    //Operation getName();
};

class ParameterToken : public AToken
{
public:
    TokenType getType();
    //Parameter getName();
};