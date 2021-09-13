#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class achievement
    {
    public:
        achievement(json parsed)
        {
            this->name = get_int(parsed, "name");
            this->description = get_int(parsed, "description");
            this->image = get_str(parsed, "image");
            this->counter = get_int(parsed, "counter");
            this->date = get_str(parsed, "date");
        };
        int name;
        int description;
        std::string image;
        int counter;
        std::string date;
    };
}