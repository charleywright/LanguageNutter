#include "languagenut.hpp"

std::vector<languagenut::types::curriculum_data> languagenut::client::get_curriculums()
{
    json data = this->authed_request("packageController/getCurriculums");
    std::vector<languagenut::types::curriculum_data> curriculums;
    for (json i : data["curriculumsData"])
        curriculums.push_back(languagenut::types::curriculum_data(i));
    return curriculums;
}