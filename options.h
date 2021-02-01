#include <string>

std::string makeFlag(const std::string &flag)
{
    return "-" + flag;
}

static const std::string VERBAL_OPTION = makeFlag("v");