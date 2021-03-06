#include <string>
#include <vector>
#include "json.hpp"
#include <curl/curl.h>
#include "types/types.hpp"

#pragma once

namespace languagenut
{
    class client
    {
    public:
        client() { this->m_curl = curl_easy_init(); };
        bool login(std::string username, std::string password);
        void init(std::string lang = "en");
        types::account get_account();
        std::vector<types::achievement> get_achievements();
        std::vector<types::assignment> get_assignments();
        std::vector<types::user> get_school_rankings();
        std::vector<types::class_> get_class_rankings();
        std::vector<types::global_user> get_global_rankings(int padding = 5);
        types::skills get_skills();
        types::user_data get_user_data();
        types::curriculum get_curriculum(int uid);
        std::vector<types::curriculum_data> get_curriculums();
        std::vector<types::module> get_module_ids(int uid, bool customContent = false, bool order_game_type = true);
        std::vector<types::exam_level> get_exam_levels(int uid);
        std::vector<types::verb> get_verb_categories(std::string lang, int verbUid = 0);
        std::vector<types::verb_translation> get_verb_translations(int uid, int game_id, std::string from, std::string to);
        std::string translate(int id) { return this->m_translations.value(std::to_string(id), ""); };
        std::string translate_module(int id) { return this->m_module_translations.value(std::to_string(id), ""); };

    private:
        nlohmann::json authed_request(std::string path, std::string body = "");
        CURL *m_curl;
        std::string m_token;
        nlohmann::json m_translations;
        nlohmann::json m_module_translations;
    };
}