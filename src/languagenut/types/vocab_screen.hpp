#include "json.hpp"
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
            this->uid = std::stoi(parsed.value("uid", ""));
            this->start_screen = std::stoi(parsed.value("start_screen", ""));
            this->title = parsed.value("title", "");
            this->additional_information = parsed.value("additionalInformation", "");
            this->group_id = parsed.value("group_id", "");
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