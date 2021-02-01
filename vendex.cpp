#include <iostream>
#include "inputparser.h"

int main(int argc, char **argv)
{
    InputParser input(argc, argv);
    // if (input.cmdOptionExists("-h"))
    // {
    //     // Do stuff
    // }

    std::cout << "OK" << std::endl;
    return 0;
}