#include <iostream>
#include "include/inputparser.h"
#include "include/token.h"

int main(int argc, char **argv)
{
    InputParser input(argc, argv);
    InputParser parser;
    input.printOptions();
    input.printParameters();
    return 0;
}