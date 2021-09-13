#include "languagenut.hpp"

std::vector<languagenut::types::achievement> languagenut::client::get_achievements()
{
    json data = this->authed_request("userDataController/getUserAchievements");
    std::vector<languagenut::types::achievement> achievements;
    for (json i : data["achievements"])
        achievements.push_back(languagenut::types::achievement(i));
    return achievements;
}