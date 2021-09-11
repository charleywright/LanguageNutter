#include "json.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class task
    {
    public:
        task(json parsed)
        {
            this->translation = std::stoi(parsed.value("translation", ""));
            this->rel_module_uid = std::stoi(parsed.value("rel_module_uid", ""));
            this->type = parsed.value("type", this->type);
            this->game_type = parsed.value("gameType", this->game_type);
            this->title = std::stoi(parsed.value("title", ""));
            this->game_uid = std::stoi(parsed.value("game_uid", ""));
            this->game_translation = std::stoi(parsed.value("gameTranslation", ""));
            this->game_link = parsed.value("gameLink", this->game_link);
            if (parsed["catalog_uid"].type_name() == "null")
            {
                this->catalog_uid = 0;
            }
            else
                this->catalog_uid = std::stoi(parsed.value("catalog_uid", ""));
            this->game_title = std::stoi(parsed.value("gameTitle", ""));
            this->feature_uid = std::stoi(parsed.value("feature_uid", ""));
            this->name = parsed.value("name", this->name);
            for (std::string i : parsed["gameTranslations"])
                this->game_translations.push_back(std::stoi(i));
            this->base.push_back(parsed["base"][0]);
            this->base.push_back(parsed["base"][1]);
            this->base.push_back("null");
            this->base.push_back(parsed["base"][3]);
            this->base.push_back(parsed["base"][4]);
            this->base.push_back(parsed["base"][5]);
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