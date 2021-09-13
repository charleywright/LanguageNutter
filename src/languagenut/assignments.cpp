#include "languagenut.hpp"

std::vector<languagenut::types::assignment> languagenut::client::get_assignments()
{
    json data = this->authed_request("assignmentController/getViewableAll");
    std::vector<languagenut::types::assignment> assignments;
    for (json i : data["homework"])
        assignments.push_back(languagenut::types::assignment(i));
    return assignments;
}