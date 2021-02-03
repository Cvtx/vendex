#pragma once
#include <string>
#include <map>

#define OptionsTokensMap std::map<std::string, Option>
#define OPTION_DASH '-' /* Option dash */ // const char ?

/**
 * @brief Possible options
 * 
 */
enum class Option
{
    Undefined,
    Verbal,
    FileName,
    Directory,
    Path,
};

/**
 * @brief Mapping cli flags to option
 * 
 */
const OptionsTokensMap Options{
    {"v", Option::Verbal},
    {"f", Option::FileName},
    {"p", Option::Path},
};

enum class Parameter
{

};