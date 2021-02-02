#include "../include/operations.h"

void performOperation(const OperationsFunctionsMap &operations, const Operation &operation, const Arguments &args)
{
    OperationsFunctionsMap::const_iterator iterator = operations.find(operation);
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
