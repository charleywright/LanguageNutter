#include "json.hpp"
#include "json_helpers.hpp"
#include <vector>

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class vocab_screen
    {
    public:
        vocab_screen(json parsed)
        {
            this->uid = get_int(parsed, "uid");
            this->start_screen = get_int(parsed, "start_screen");
            this->title = get_str(parsed, "title");
            this->additional_information = get_str(parsed, "additionalInformation");
            this->group_id = get_str(parsed, "group_id");
            for (json i : parsed["languages"])
                this->languages.push_back(i.value("ietf", ""));
        };
        int uid;
        int start_screen;
        std::string title;
        std::string additional_information;
        std::string group_id;
        std::vector<std::string> languages;
    };
}