#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class user
    {
    public:
        user(json parsed)
        {
            this->uid = get_int(parsed, "uid");
            this->name = get_str(parsed, "name");
            this->is_user = (bool)get_int(parsed, "isUser");
            this->score = get_int(parsed, "score");
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
            this->user_uid = get_int(parsed, "user_uid");
            this->key = get_str(parsed, "key");
            this->name = get_str(parsed, "name");
            this->score = get_int(parsed, "score");
            this->flag = get_str(parsed, "flag");
            this->blocked = (bool)get_int(parsed, "blocked");
            this->account_uid = get_int(parsed, "account_uid");
            this->plain_name = get_str(parsed, "plain_name");
            this->user_language = get_str(parsed, "user_language");
            this->rank = get_int(parsed, "rank");
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