#include "languagenut.hpp"

languagenut::types::skills languagenut::client::get_skills()
{
    json data = this->authed_request("skillsController/getStudent");
    return languagenut::types::skills(data);
}