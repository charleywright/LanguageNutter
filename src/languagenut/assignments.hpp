#include <string>
#include <vector>
#include <curl/curl.h>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include "write_callback.hpp"
#include "json.hpp"

using json = nlohmann::json;

namespace languagenut
{
    bool str_to_bool(std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::istringstream is(str);
        bool b;
        is >> std::boolalpha >> b;
        return b;
    }
}

namespace languagenut::types
{
    class task
    {
    public:
        task(json parsed)
        {
            this->translation = std::stoi(parsed.value("translation", ""));
            this->rel_module_uid = std::stoi(parsed.value("rel_module_uid", ""));
            this->type = parsed.value("type", this->type);
            this->game_type = parsed.value("gameType", this->game_type);
            this->title = std::stoi(parsed.value("title", ""));
            this->game_uid = std::stoi(parsed.value("game_uid", ""));
            this->game_translation = std::stoi(parsed.value("gameTranslation", ""));
            this->game_link = parsed.value("gameLink", this->game_link);
            if (parsed["catalog_uid"].type_name() == "null")
            {
                this->catalog_uid = 0;
            }
            else
                this->catalog_uid = std::stoi(parsed.value("catalog_uid", ""));
            this->game_title = std::stoi(parsed.value("gameTitle", ""));
            this->feature_uid = std::stoi(parsed.value("feature_uid", ""));
            this->name = parsed.value("name", this->name);
            for (std::string i : parsed["gameTranslations"])
                this->game_translations.push_back(std::stoi(i));
            this->base.push_back(parsed["base"][0]);
            this->base.push_back(parsed["base"][1]);
            this->base.push_back("null");
            this->base.push_back(parsed["base"][3]);
            this->base.push_back(parsed["base"][4]);
            this->base.push_back(parsed["base"][5]);
            for (std::string i : parsed["module_translations"])
                this->module_translations.push_back(std::stoi(i));
        };
        int translation;
        int rel_module_uid;
        std::string type;
        std::string game_type;
        int title;
        int game_uid;
        int game_translation;
        std::string game_link;
        int catalog_uid;
        int game_title;
        int feature_uid;
        std::string name;
        std::vector<int> game_translations;
        std::vector<std::string> base;
        // gameResults
        std::vector<int> module_translations;
    };

    class assignment
    {
    public:
        assignment(json parsed)
        {
            this->id = std::stoi(parsed.value("id", ""));
            this->favourite = std::stoi(parsed.value("favourite", ""));
            for (auto i : parsed["tasks"])
                this->tasks.push_back(task(i));
            this->language = std::stoi(parsed.value("language", ""));
            this->language_code = parsed.value("languageCode", this->language_code);
            this->created_by = std::stoi(parsed.value("createdBy", ""));
            this->total_students_cal = std::stoi(parsed.value("totalStudentsCal", ""));
            this->completed = parsed.value("completed", this->completed);
            this->comment = parsed.value("comment", this->comment);
            this->homework_comment = parsed.value("homework_comment", this->homework_comment);
            this->audio = parsed.value("audio", this->audio);
            this->due = parsed.value("due", this->due);
            this->set = parsed.value("set", this->set);
            this->name = parsed.value("name", this->name);
            this->estimated_time = parsed.value("estimated_time", this->estimated_time);
            this->is_repeatable = str_to_bool(parsed.value("isRepeatable", "false"));
            this->is_practice = str_to_bool(parsed.value("isPractice", "false"));
            this->is_test_mode = str_to_bool(parsed.value("isTestMode", "false"));
            this->is_complete = str_to_bool(parsed.value("isComplete", "false"));
        };
        int id;
        int favourite;
        std::vector<task> tasks;
        int language;
        std::string language_code;
        // totalStudents
        int created_by;
        int total_students_cal;
        int completed;
        std::string comment;
        std::string homework_comment;
        std::string audio;
        std::string due;
        std::string set;
        std::string name;
        int estimated_time;
        bool is_repeatable;
        // isEmail
        bool is_practice;
        bool is_test_mode;
        bool is_complete;
    };
}

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