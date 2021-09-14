#include "json.hpp"
#include "json_helpers.hpp"
#include "exam_data.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class module
    {
    public:
        module(json parsed)
        {
            this->uid = get_int(parsed, "uid");
            this->picture = get_str(parsed, "picture");
            this->style_type = get_str(parsed, "styleType");
            this->title = get_int(parsed, "title");
            this->screen_uid = get_int(parsed, "screen_uid");
            this->is_wordsearch_valid = parsed.value("isWordsearchValid", true);
            this->is_hidden = parsed.value("isHidden", false);
            this->is_trial = (bool)get_int(parsed, "isTrial");
            this->is_valid = parsed.value("isValid", true);
            this->show_image = (bool)get_int(parsed, "showImage");
            this->parent_screen = get_int(parsed, "parentScreen");
            this->number_title = get_int(parsed, "numberTitle");
            this->exam_uid = get_int(parsed, "examUid");
            this->exam_data = examdata(parsed["examData"]);
            this->is_exam_custom_content = parsed.value("isExamCustomContent", false);
            this->gold_medals = parsed.value("goldMedals", 0);
            this->silver_medals = parsed.value("SilverMedals", 0);
            this->bronze_medals = parsed.value("bronzeMedals", 0);
            this->language_filter = get_str(parsed, "languageFilter");
        };
        int uid;
        std::string picture;
        // "sentenceCatalog": null,
        // "sentence_catalog": null,
        std::string style_type;
        int title;
        // "screenUid": null,
        int screen_uid;
        // "catalogUid": null,
        bool is_wordsearch_valid;
        bool is_hidden;
        bool is_trial;
        bool is_valid;
        // "forcedText": null,
        bool show_image;
        // "isValidLink": null,
        // "isValidTranslation": null,
        // "validLanguages": null,
        int parent_screen;
        int number_title;
        // "grammarUid": null,
        int exam_uid;
        examdata exam_data;
        bool is_exam_custom_content;
        int gold_medals;
        int silver_medals;
        int bronze_medals;
        std::string language_filter;
    };
}