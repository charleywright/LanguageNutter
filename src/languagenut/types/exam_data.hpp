#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class examdata
    {
    public:
        examdata(){};
        examdata(json parsed)
        {
            this->exam_game_type = get_str(parsed, "examGameType");
            this->exam_game_uid = get_int(parsed, "examGameUid");
            this->exam_game_sprite = get_str(parsed, "examGameSprite");
            this->exam_question_uid = get_int(parsed, "examQuestionUid");
        };
        std::string exam_game_type;
        int exam_game_uid;
        std::string exam_game_sprite;
        int exam_question_uid;
    };
}