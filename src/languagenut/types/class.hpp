#include "json.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class class_
    {
    public:
        class_(json parsed)
        {
            this->class_uid = std::stoi(parsed.value("class_uid", ""));
            this->name = parsed.value("name", "");
            this->is_class = (bool)std::stoi(parsed.value("is_class", "0"));
            this->score = std::stoi(parsed.value("score", "0"));
        };
        int class_uid;
        std::string name;
        int score;
        bool is_class;
    };
}