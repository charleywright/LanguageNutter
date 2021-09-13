#include "json.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class accountsettings
    {
    public:
        accountsettings(){};
        accountsettings(json parsed)
        {
            this->enable_exam_transcripts = (bool)std::stoi(parsed.value("enableExamTranscripts", "0"));
            this->hints = (bool)std::stoi(parsed.value("hints", "0"));
            this->show_classes_league = (bool)std::stoi(parsed.value("showClassesLeague", "1"));
            this->show_school_ranking = (bool)std::stoi(parsed.value("showSchoolRanking", "1"));
        };
        bool enable_exam_transcripts;
        bool hints;
        bool show_classes_league;
        bool show_school_ranking;
    };

    class account
    {
    public:
        account(json parsed)
        {
            this->name = parsed.value("name", "");
            if (parsed["unquie_referance"].type_name() == "null")
                parsed["unquie_referance"] = "";
            this->unquie_referance = parsed.value("unquie_referance", "");
            this->phone = parsed.value("phone", "");
            if (parsed["email"].type_name() == "null")
                parsed["email"] = "";
            this->email = parsed.value("email", "");
            if (parsed["street"].type_name() == "null")
                parsed["street"] = "";
            this->street = parsed.value("street", "");
            this->billing_country = parsed.value("billing_country", "");
            this->billing_city = parsed.value("billing_city", "");
            if (parsed["post_code"].type_name() == "null")
                parsed["post_code"] = "";
            this->post_code = parsed.value("post_code", "");
            this->hints = (bool)std::stoi(parsed.value("hints", ""));
            this->account_settings = accountsettings(parsed["accountSettings"]);
        };
        std::string name;
        std::string unquie_referance; // 99% sure that is spelt wrong on their servers
        std::string phone;
        std::string email;
        std::string street;
        std::string billing_country;
        std::string billing_city;
        std::string post_code;
        bool hints;
        accountsettings account_settings;
    };
}