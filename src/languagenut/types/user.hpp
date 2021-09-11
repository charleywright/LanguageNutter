#include "json.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class user
    {
    public:
        user(json parsed)
        {
            this->uid = std::stoi(parsed.value("uid", "")); // LanguageNut returns numbers as strings ("1234"), so stoi is needed
            this->name = parsed.value("name", "");
            this->is_user = (bool)std::stoi(parsed.value("isUser", "0"));
            this->score = std::stoi(parsed.value("score", "0"));
        };
        int uid;
        std::string name;
        bool is_user;
        int score;
    };

    class global_user
    {
    public:
        global_user(json parsed)
        {
            this->user_uid = std::stoi(parsed.value("user_uid", ""));
            this->key = parsed.value("key", this->key);
            this->name = parsed.value("name", this->name);
            this->score = std::stoi(parsed.value("score", ""));
            if (parsed["flag"].type_name() == "null")
                parsed["flag"] = "null";
            this->flag = parsed.value("flag", this->flag);
            this->blocked = (bool)std::stoi(parsed.value("blocked", ""));
            this->account_uid = std::stoi(parsed.value("account_uid", ""));
            this->plain_name = parsed.value("plain_name", this->plain_name);
            if (parsed["user_language"].type_name() == "null")
                parsed["user_language"] = "null";
            this->user_language = parsed.value("user_language", this->user_language);
            this->rank = parsed.value("rank", this->rank);
        };
        int user_uid;
        std::string key;
        std::string name;
        int score;
        std::string flag;
        bool blocked;
        int account_uid;
        std::string plain_name;
        std::string user_language;
        int rank;
    };
}