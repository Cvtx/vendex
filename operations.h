#include <string>
#include <map>
#include <functional>

/**
 * @brief Commands that program can perform
 * 
 */
enum Operation
{
    CreateDB,
    DeleteDB,
    AddFile,
    DeleteFile,
    ExportFile
};

/**
 * @brief Possible options
 * 
 */
enum Option
{
    Verbal,
};

void CreateDatabase(std::string s)
{
}

/**
 * @brief Mapping options to specific operations
 * 
 */
const std::map<Operation, std::function<void(std::string)>> OperationsMapping{
    {CreateDB, CreateDatabase},
};