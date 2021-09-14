#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class verb_translation
    {
    public:
        verb_translation(json parsed)
        {
            this->audio = get_str(parsed, "audio");
            this->original_verb = get_str(parsed, "originalVerb");
            this->other = get_str(parsed, "other");
            this->translated_verb = get_str(parsed, "translatedVerb");
            this->uid = get_int(parsed, "uid");
        };
        std::string audio;
        std::string original_verb;
        std::string other;
        std::string translated_verb;
        int uid;
    };
}