#include <iostream>
#include "include/inputparser.h"
#include "include/token.h"

int main(int argc, char **argv)
{
    InputParser input(argc, argv);
    input.printOptions();
    return 0;
}