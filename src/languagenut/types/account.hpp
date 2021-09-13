#include "json.hpp"
#include "json_helpers.hpp"

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
            this->enable_exam_transcripts = (bool)get_int(parsed, "enableExamTranscripts");
            this->hints = (bool)get_int(parsed, "hints");
            this->show_classes_league = (bool)get_int(parsed, "showClassesLeague");
            this->show_school_ranking = (bool)get_int(parsed, "showSchoolRanking");
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
            this->name = get_str(parsed, "name");
            this->unquie_referance = get_str(parsed, "unquie_referance");
            this->phone = get_str(parsed, "phone");
            this->email = get_str(parsed, "email");
            this->street = get_str(parsed, "street");
            this->billing_country = get_str(parsed, "billing_country");
            this->billing_city = get_str(parsed, "billing_city");
            this->post_code = get_str(parsed, "post_code");
            this->hints = (bool)get_int(parsed, "hints");
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