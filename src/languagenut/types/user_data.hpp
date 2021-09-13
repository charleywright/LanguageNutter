#include "json.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class user_data
    {
    public:
        user_data(json parsed)
        {
            for (json i : parsed["additionalVocabScreens"])
                this->additional_vocab_screens.push_back(vocab_screen(i));
            this->introduction_video = get_str(parsed, "IntroductionVideo");
            this->user_type = get_str(parsed, "userType");
            this->user_name = get_str(parsed, "userName");
            this->name = get_str(parsed, "name");
            this->display_name = get_str(parsed, "displayName");
            this->gold_medals = get_int(parsed, "goldMedals");
            this->silver_medals = get_int(parsed, "silverMedals");
            this->bronze_medals = get_int(parsed, "bronzeMedals");
            this->total_score = get_int(parsed, "totalScore");
            this->rank = get_int(parsed, "rank");
            this->country = get_str(parsed, "country");
            this->style = get_str(parsed, "style");
            for (std::string i : parsed["curriculum"])
                this->curriculum.push_back(std::stoi(i));
            for (std::string i : parsed["groups"])
                this->groups.push_back(i);
            for (json i : parsed["primaryEndDates"])
                this->primary_end_dates.push_back(i.value("end_date", ""));
            for (json i : parsed["secondaryEndDates"])
                this->secondary_end_dates.push_back(i.value("end_date", ""));
            for (json i : parsed["ESOLEndDates"])
                this->esol_end_dates.push_back(i.value("end_date", ""));
            this->override_logo = get_str(parsed, "overrideLogo");
            this->account_name = get_str(parsed, "acocuntName");
            this->days_left_of_subscription = get_int(parsed, "daysLeftOfSubscription");
            this->words_learnt = get_int(parsed, "wordsLearnt");
            this->is_live = parsed.value("isLive", true);
            this->account_uid = get_int(parsed, "accountUid");
            this->second_login_type = get_str(parsed, "secondLoginType");
            this->user_uid = get_int(parsed, "userUid");
            this->tested = (bool)get_int(parsed, "tested");
            this->account_type = get_str(parsed, "account_type");
            this->account_settings = accountsettings(parsed["accountSettings"]);
            this->homework_counter = get_int(parsed, "homeworkCounter");
            this->is_cefr = (bool)get_int(parsed, "is_cefr");
        };
        std::vector<types::vocab_screen> additional_vocab_screens;
        std::string introduction_video;
        // defined_support: null;
        std::string user_type;
        std::string user_name;
        std::string name;
        std::string display_name;
        int gold_medals;
        int silver_medals;
        int bronze_medals;
        int total_score;
        int rank;
        std::string country;
        std::string style;
        std::vector<int> curriculum;
        std::vector<std::string> groups;
        std::vector<std::string> primary_end_dates;
        std::vector<std::string> secondary_end_dates;
        std::vector<std::string> esol_end_dates;
        std::string override_logo;
        std::string account_name;
        int days_left_of_subscription;
        int words_learnt;
        bool is_live;
        int account_uid;
        std::string second_login_type;
        int user_uid;
        bool tested;
        std::string account_type;
        accountsettings account_settings;
        // isMessageDisplay: null
        int homework_counter;
        // customContentTeacherScreens: []
        bool is_cefr;
    };
}