#include <iostream>
#include "inputparser/inputparser.h"
#include "operations.h"

int main(int argc, char **argv)
{
    InputParser input(argc, argv);
    input.printOptions();
    return 0;
}