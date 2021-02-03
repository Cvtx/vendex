#include <iostream>
#include "include/inputparser.h"
#include "include/token.h"

int main(int argc, char **argv)
{
    InputParser input(argc, argv, Operations, Options);
    OptionToken token("o token", TokenOption::Verbal);
    input.printOptions();
    std::cout << token.getValue();
    TokenOption option = static_cast<TokenOption>(token.getName());
    std::cout << (option == TokenOption::Verbal);
    return 0;
}