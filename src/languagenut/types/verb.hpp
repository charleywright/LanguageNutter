#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class verb
    {
    public:
        verb(json parsed)
        {
            this->is_last = parsed.value("isLast", false);
            this->picture = get_str(parsed, "picture");
            this->style_type = get_str(parsed, "styleType");
            this->title = get_str(parsed, "title");
            this->uid = get_int(parsed, "verbUid");
        };
        bool is_last;
        std::string picture;
        std::string style_type;
        std::string title;
        int uid;
    };
}