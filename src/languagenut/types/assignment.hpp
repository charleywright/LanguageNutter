#include "json.hpp"
#include "task.hpp"
#include "json_helpers.hpp"

using json = nlohmann::json;
#pragma once

namespace languagenut::types
{
    class assignment
    {
    public:
        assignment(json parsed)
        {
            this->id = get_int(parsed, "id");
            this->favourite = get_int(parsed, "favourite");
            for (json i : parsed["tasks"])
                this->tasks.push_back(task(i));
            this->language = get_int(parsed, "language");
            this->language_code = get_str(parsed, "languageCode");
            this->created_by = get_int(parsed, "createdBy");
            this->total_students_cal = get_int(parsed, "totalStudentsCal");
            this->completed = get_int(parsed, "completed");
            this->comment = get_str(parsed, "comment");
            this->homework_comment = get_str(parsed, "homework_comment");
            this->audio = get_str(parsed, "audio");
            this->due = get_str(parsed, "due");
            this->set = get_str(parsed, "set");
            this->name = get_str(parsed, "name");
            this->estimated_time = get_int(parsed, "estimated_time");
            this->is_repeatable = get_str_bool(parsed, "isRepeatable");
            this->is_practice = get_str_bool(parsed, "isPractice");
            this->is_test_mode = get_str_bool(parsed, "isTestMode");
            this->is_complete = get_str_bool(parsed, "isComplete");
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