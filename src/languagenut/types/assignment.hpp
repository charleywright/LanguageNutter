#include <sstream>
#include "json.hpp"
#include "task.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    bool str_to_bool(std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::istringstream is(str);
        bool b;
        is >> std::boolalpha >> b;
        return b;
    }

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