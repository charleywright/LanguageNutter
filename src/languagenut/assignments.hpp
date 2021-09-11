#include <string>
#include <vector>
#include <curl/curl.h>
#include "write_callback.hpp"
#include "json.hpp"
#include "types/assignment.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut
{
    std::vector<types::assignment> get_assignments(std::string token)
    {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.languagenut.com/assignmentController/getViewableAll");
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
        std::vector<types::assignment> assignments;
        json response = json::parse(raw_response);
        for (auto i : response["homework"])
        {
            assignments.push_back(types::assignment(i));
        }
        return assignments;
    }
}