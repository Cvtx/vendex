#include <iostream>
#include "include/inputparser.h"

int main(int argc, char **argv)
{
    InputParser input(argc, argv, Operations, Options);
    input.printOptions();
    return 0;
}