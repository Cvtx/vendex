#pragma once
#include <string>
#include <map>
#include <functional>
#include <iostream>
#include "arguments.h"

#define OperationsFunctionsMap std::map<Operation, std::function<void(Arguments)>>
#define OperationsTokensMap std::map<std::string, Operation>

/**
 * @brief Commands that program can perform
 * 
 */
enum class Operation
{
    Undefined,
    CreateDB,
    DeleteDB,
    AddFile,
    DeleteFile,
    ExportFile
};

/**
 * @brief Mapping operations to specific functions
 * 
 */
const OperationsTokensMap Operations{
    {"createdb", Operation::CreateDB}, // TODO: make create token rather that createdb createtag and so on
    {"deletedb", Operation::DeleteDB},

};

/**
 * @brief Finds mapped function to operation and executes it, passing the parameters
 * 
 * @param operations map of operations
 * @param operation operation to search
 * @param args arguments to pass
 */

void performOperation(const OperationsFunctionsMap &operations, const Operation &operation, const Arguments &args);