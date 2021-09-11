#include <string>
#include <curl/curl.h>
#include "json.hpp"
#include "write_callback.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut
{
    std::string login(std::string username, std::string password)
    {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.languagenut.com/loginController/attemptlogin");
        std::string body = std::string("username=").append(username).append("&pass=").append(password);
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
        return response.value("newToken", "INVALID");
    }
}