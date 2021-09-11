#include <string>
#include <vector>
#include <iostream>
#include <curl/curl.h>
#include "json.hpp"
#include "write_callback.hpp"

using json = nlohmann::json;
#pragma once

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