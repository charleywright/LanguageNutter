#include <string>
#include <vector>
#include <curl/curl.h>
#include "write_callback.hpp"
#include "json.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class skills
    {
    public:
        skills(json parsed)
        {
            if (parsed["reading"]["average"].type_name() == "null")
                parsed["reading"]["average"] = "0";
            this->reading = std::stod(parsed["reading"].value("average", ""));
            if (parsed["listening"]["average"].type_name() == "null")
                parsed["listening"]["average"] = "0";
            this->listening = std::stod(parsed["listening"].value("average", ""));
            if (parsed["writing"]["average"].type_name() == "null")
                parsed["writing"]["average"] = "0";
            this->writing = std::stod(parsed["writing"].value("average", ""));
            if (parsed["speaking"]["average"].type_name() == "null")
                parsed["speaking"]["average"] = "0";
            this->speaking = std::stod(parsed["speaking"].value("average", ""));
            if (parsed["verbs"]["average"].type_name() == "null")
                parsed["verbs"]["average"] = "0";
            this->verbs = std::stod(parsed["verbs"].value("average", ""));
            if (parsed["grammar"]["average"].type_name() == "null")
                parsed["grammar"]["average"] = "0";
            this->grammar = std::stod(parsed["grammar"].value("average", ""));
            if (parsed["sentence"]["average"].type_name() == "null")
                parsed["sentence"]["average"] = "0";
            this->sentence = std::stod(parsed["sentence"].value("average", ""));
        };
        double reading;
        double listening;
        double writing;
        double speaking;
        double verbs;
        double grammar;
        double sentence;
    };
}

namespace languagenut
{
    types::skills get_skills(std::string token)
    {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.languagenut.com/skillsController/getStudent");
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
        return types::skills(json::parse(raw_response));
    }
}