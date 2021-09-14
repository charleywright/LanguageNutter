#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class curriculum
    {
    public:
        curriculum(json parsed)
        {
            this->exam_screen = get_int(parsed, "examScreen");
            this->grammar_screen = get_int(parsed, "grammarScreen");
            this->sentence_screen = get_int(parsed, "sentenceScreen");
            this->vocab_screen = get_int(parsed, "startScreen");
            this->topic_screen = get_int(parsed, "topicScreen");
            this->is_curric_product = (bool)get_int(parsed, "isCurricProduct");
            this->is_trial = (bool)get_int(parsed, "isTrial");
            this->picture = get_str(parsed, "picture");
            this->style = get_str(parsed, "style");
            this->time_taken_server = get_int(parsed, "timeTakenServer");
            this->uid = get_int(parsed, "uid");
            this->uses_images = (bool)get_int(parsed, "uses_images");
            for (std::string i : parsed["verbLanguages"])
                this->verb_languages.push_back(i);
        };
        // customLanguages: []
        int exam_screen;
        int grammar_screen;
        int sentence_screen;
        int vocab_screen;
        int topic_screen;
        bool is_curric_product;
        bool is_trial;
        // packageUid: null
        std::string picture;
        std::string style;
        int time_taken_server;
        int uid;
        bool uses_images;
        std::vector<std::string> verb_languages;
    };
}