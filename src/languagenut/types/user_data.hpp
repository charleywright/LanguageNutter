#include "json.hpp"

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
            this->introduction_video = parsed.value("IntroductionVideo", "");
            this->user_type = parsed.value("userType", "");
            this->user_name = parsed.value("userName", "");
            this->name = parsed.value("name", "");
            if (parsed["displayName"].type_name() == "null")
                parsed["displayName"] = "";
            this->display_name = parsed.value("displayName", "");
            this->gold_medals = std::stoi(parsed.value("goldMedals", ""));
            this->silver_medals = std::stoi(parsed.value("silverMedals", ""));
            this->bronze_medals = std::stoi(parsed.value("bronzeMedals", ""));
            this->total_score = std::stoi(parsed.value("totalScore", ""));
            this->rank = std::stoi(parsed.value("rank", ""));
            this->country = parsed.value("country", "");
            this->style = parsed.value("style", "");
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
            this->override_logo = parsed.value("overrideLogo", "");
            this->account_name = parsed.value("acocuntName", "");
            this->days_left_of_subscription = parsed.value("daysLeftOfSubscription", 0);
            this->words_learnt = parsed.value("wordsLearnt", 0);
            this->is_live = parsed.value("isLive", true);
            this->account_uid = std::stoi(parsed.value("accountUid", ""));
            if (parsed["secondLoginType"].type_name() == "null")
                parsed["secondLoginType"] = "";
            this->second_login_type = parsed.value("secondLoginType", "");
            this->user_uid = std::stoi(parsed.value("userUid", ""));
            this->tested = (bool)parsed.value("tested", 1);
            this->account_type = parsed.value("account_type", "");
            this->account_settings = accountsettings(parsed["accountSettings"]);
            this->homework_counter = std::stoi(parsed.value("homeworkCounter", ""));
            this->is_cefr = (bool)std::stoi(parsed.value("is_cefr", ""));
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