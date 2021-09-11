#include <string>
#include <vector>
#include <curl/curl.h>
#include "write_callback.hpp"
#include "json.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut
{
    std::vector<types::achievement> get_achievements(std::string token)
    {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.languagenut.com/userDataController/getUserAchievements");
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
        std::vector<types::achievement> achievements;
        json response = json::parse(raw_response);
        for (auto i : response["achievements"])
        {
            achievements.push_back(types::achievement(i));
        }
        return achievements;
    }
}