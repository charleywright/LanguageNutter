#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class curriculum_data
    {
    public:
        curriculum_data(json parsed)
        {
            this->group_id = get_str(parsed, "group_id");
            this->group_image = get_str(parsed, "group_image");
            this->group_sub_title = get_int(parsed, "group_sub_title");
            this->group_title = get_int(parsed, "group_title");
            this->is_valid = get_str_bool(parsed, "isValid");
            this->name = get_int(parsed, "name");
            this->package_name = get_int(parsed, "packageName");
            this->package_uid = get_int(parsed, "packageUid");
            this->picture = get_str(parsed, "picture");
            this->start_screen = get_int(parsed, "start_screen");
            this->style = get_str(parsed, "style");
            this->uid = get_int(parsed, "uid");
        };
        std::string group_id;
        std::string group_image;
        int group_sub_title;
        int group_title;
        bool is_valid;
        int name;
        int package_name;
        int package_uid;
        std::string picture;
        int start_screen;
        std::string style;
        int uid;
    };
}