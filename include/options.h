#include <string>
#include <map>

#define OptionsMap std::map<std::string, Option>

/**
 * @brief Possible options
 * 
 */
enum Option
{
    Verbal,
    FileName,
    Directory
};

/**
 * @brief Mapping cli flags to option
 * 
 */
const OptionsMap Options{
    {"v", Verbal},
    {"f", FileName},
};