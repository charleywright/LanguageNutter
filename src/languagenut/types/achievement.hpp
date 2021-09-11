#include "json.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class achievement
    {
    public:
        achievement(json parsed)
        {
            this->name = std::stoi(parsed.value("name", ""));
            this->description = std::stoi(parsed.value("description", ""));
            this->image = parsed.value("image", this->image);
            this->counter = std::stoi(parsed.value("counter", ""));
            if (parsed["date"].type_name() == "null")
                parsed["date"] = "";
            this->date = parsed.value("date", this->date);
        };
        int name;
        int description;
        std::string image;
        int counter;
        std::string date;
    };
}