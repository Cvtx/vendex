#pragma once
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

/**
 * @brief Mapping operations to specific functions
 * 
 */
const OperationsMap Operations{

};

/**
 * @brief Finds mapped function to operation and executes it, passing the parameters
 * 
 * @param operations map of operations
 * @param operation operation to search
 * @param args arguments to pass
 */

void performOperation(const OperationsMap &operations, const Operation &operation, const Arguments &args);