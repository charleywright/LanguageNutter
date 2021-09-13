#include "json.hpp"
#include <string>
#include <sstream>

#pragma once

// LanguageNut really like returning null, and nlohmann/json doesn't like that. Could use a different lib but I have more experience with this one
namespace languagenut::types
{
    template <typename T>
    inline std::string get_str(nlohmann::json j, T prop)
    {
        if (j[prop].is_null())
            return "";
        return j[prop];
    }

    inline int get_int(nlohmann::json j, std::string prop)
    {
        if (j[prop].is_null())
            return 0;
        return j[prop].is_number() ? j.value(prop, 0) : std::stoi(j.value(prop, "0"));
    }

    // LanguageNut sometimes use "false", false, 0 or "0" depending how they feel
    inline bool get_str_bool(nlohmann::json j, std::string prop)
    {
        if (j[prop].is_null())
            return false;
        std::string str = j.value(prop, "false");
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::istringstream is(str);
        bool b;
        is >> std::boolalpha >> b;
        return b;
    }
}