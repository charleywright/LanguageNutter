#include <string>
#include <vector>
#include <iostream>
#include <curl/curl.h>
#include "json.hpp"
#include "write_callback.hpp"

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

    class class_
    {
    public:
        class_(json parsed)
        {
            this->class_uid = std::stoi(parsed.value("class_uid", ""));
            this->name = parsed.value("name", "");
            this->is_class = (bool)std::stoi(parsed.value("is_class", "0"));
            this->score = std::stoi(parsed.value("score", "0"));
        };
        int class_uid;
        std::string name;
        int score;
        bool is_class;
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

namespace languagenut
{
    std::vector<types::user> get_school_rankings(std::string token)
    {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.languagenut.com/highscoreController/studentsAllAccount");
        std::string body = std::string("token=").append(token);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::string raw_response;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &raw_response);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        json parsed = json::parse(raw_response);
        std::vector<types::user> users;
        for (json i : parsed["list"])
        {
            users.push_back(types::user(i));
        }
        return users;
    }

    std::vector<types::class_> get_class_rankings(std::string token)
    {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.languagenut.com/highscoreController/classes");
        std::string body = std::string("token=").append(token).append("&from=0&to=").append(std::to_string(INT32_MAX));
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::string raw_response;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &raw_response);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        json parsed = json::parse(raw_response);
        std::vector<types::class_> classes;
        for (json i : parsed["list"])
        {
            classes.push_back(types::class_(i));
        }
        return classes;
    }

    std::vector<types::global_user> get_global_rankings(std::string token, int padding = 5)
    {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.languagenut.com/userDataController/getUserScore");
        std::string body = std::string("token=").append(token).append("&number=").append(std::to_string(padding));
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::string raw_response;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &raw_response);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        std::vector<types::global_user> users;
        if (raw_response[0] == '<')
        {
            std::cout << "API Crashed" << std::endl;
            return users;
        }
        json parsed = json::parse(raw_response);
        for (json i : parsed["scores"])
        {
            users.push_back(types::global_user(i));
        }
        return users;
    }
}