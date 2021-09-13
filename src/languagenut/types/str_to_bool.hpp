#include <sstream>
#include <algorithm>

#pragma once

namespace languagenut::types
{
    bool str_to_bool(std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::istringstream is(str);
        bool b;
        is >> std::boolalpha >> b;
        return b;
    }
}