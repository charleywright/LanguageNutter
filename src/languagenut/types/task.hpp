#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class task
    {
    public:
        task(json parsed)
        {
            this->translation = get_int(parsed, "translation");
            this->rel_module_uid = get_int(parsed, "rel_module_uid");
            this->type = get_str(parsed, "type");
            this->game_type = get_str(parsed, "gameType");
            this->title = get_int(parsed, "title");
            this->game_uid = get_int(parsed, "game_uid");
            this->game_translation = get_int(parsed, "gameTranslation");
            this->game_link = get_str(parsed, "gameLink");
            this->catalog_uid = get_int(parsed, "catalog_uid");
            this->game_title = get_int(parsed, "gameTitle");
            this->feature_uid = get_int(parsed, "feature_uid");
            this->name = get_str(parsed, "name");
            for (std::string i : parsed["gameTranslations"])
                this->game_translations.push_back(std::stoi(i));
            for (int i = 0; i < 6; i++)
                this->base.push_back(get_str(parsed["base"], i));
            for (std::string i : parsed["module_translations"])
                this->module_translations.push_back(std::stoi(i));
        };
        int translation;
        int rel_module_uid;
        std::string type;
        std::string game_type;
        int title;
        int game_uid;
        int game_translation;
        std::string game_link;
        int catalog_uid;
        int game_title;
        int feature_uid;
        std::string name;
        std::vector<int> game_translations;
        std::vector<std::string> base;
        // gameResults
        std::vector<int> module_translations;
    };
}