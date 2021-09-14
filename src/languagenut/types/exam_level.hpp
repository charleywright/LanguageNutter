#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class exam_level
    {
    public:
        exam_level(json parsed)
        {
            this->uid = get_int(parsed, "examUid");
            this->title = get_str(parsed, "title");
        };
        int uid;
        std::string title;
    };
}