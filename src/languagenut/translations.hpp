#include <vector>
#include <string>
#include "json.hpp"
#include <curl/curl.h>
#include "write_callback.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut
{
    json get_module_translations(std::string token, std::string lang = "en")
    {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.languagenut.com/translationController/getUserModuleTranslations");
        std::string body = std::string("token=").append(token).append("&language=").append(lang);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::string raw_response;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &raw_response);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        json response = json::parse(raw_response);
        return response["translations"];
    }

    json get_translations(std::string lang = "en")
    {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.languagenut.com/publicTranslationController/getTranslations");
        std::string body = std::string("language=").append(lang);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::string raw_response;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &raw_response);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        json response = json::parse(raw_response);
        return response["translations"];
    }
}