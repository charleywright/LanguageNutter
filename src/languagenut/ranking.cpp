#include "languagenut.hpp"

std::vector<languagenut::types::user> languagenut::client::get_school_rankings()
{
    json data = this->authed_request("highscoreController/studentsAllAccount");
    std::vector<languagenut::types::user> users;
    for (json i : data["list"])
        users.push_back(languagenut::types::user(i));
    return users;
}

std::vector<languagenut::types::class_> languagenut::client::get_class_rankings()
{
    std::string body = "from=0&to=";
    body.append(std::to_string(INT32_MAX));
    json data = this->authed_request("highscoreController/classes", body);
    std::vector<languagenut::types::class_> classes;
    for (json i : data["list"])
        classes.push_back(languagenut::types::class_(i));
    return classes;
}

std::vector<languagenut::types::global_user> languagenut::client::get_global_rankings(int padding)
{
    std::string body = "number=";
    body.append(std::to_string(padding));
    json data = this->authed_request("userDataController/getUserScore", body);
    std::vector<languagenut::types::global_user> users;
    for (json i : data["scores"])
        users.push_back(languagenut::types::global_user(i));
    return users;
}