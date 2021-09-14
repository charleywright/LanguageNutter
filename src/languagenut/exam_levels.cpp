#include "languagenut.hpp"

std::vector<languagenut::types::exam_level> languagenut::client::get_exam_levels(int uid)
{
    std::string body = "examUid=";
    body.append(std::to_string(uid));
    json data = this->authed_request("examTranslationController/getExamCatalogData", body);
    std::vector<languagenut::types::exam_level> exam_levels;
    for (json i : data["exams"])
        exam_levels.push_back(languagenut::types::exam_level(i));
    return exam_levels;
}