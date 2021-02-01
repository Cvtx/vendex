#include <string>
#include <map>
#include <functional>
#include <iostream>
#include "arguments.h"

#define OperationsMap std::map<Operation, std::function<void(Arguments)>>

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

void CreateDatabase(const Arguments &args)
{
    std::cout << "test"; // just test
}

/**
 * @brief Mapping operations to specific functions
 * 
 */
const OperationsMap Operations{
    {CreateDB, CreateDatabase},
};

/**
 * @brief Finds mapped function to operation and executes it, passing the parameters
 * 
 * @param operations map of Operations
 * @param operation operation to search
 * @param args arguments to pass
 */
void performOperation(const OperationsMap &operations, const Operation &operation, const Arguments &args)
{
    OperationsMap::const_iterator iterator = operations.find(operation);
    if (iterator == operations.end())
    {
        // error handling?
        std::cout << "Unexsisting command passed." << std::endl;
    }
    else
    {
        /* executing function and passing arguments*/
        iterator->second(args);
    }
}
