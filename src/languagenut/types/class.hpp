#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class class_
    {
    public:
        class_(json parsed)
        {
            this->class_uid = get_int(parsed, "class_uid");
            this->name = get_str(parsed, "name");
            this->is_class = (bool)get_int(parsed, "is_class");
            this->score = get_int(parsed, "score");
        };
        int class_uid;
        std::string name;
        int score;
        bool is_class;
    };
}