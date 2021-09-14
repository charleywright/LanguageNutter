#include "languagenut.hpp"

std::vector<languagenut::types::verb> languagenut::client::get_verb_categories(std::string lang, int verbUid)
{
    std::string body = "toIetf=";
    body.append(lang);
    if (verbUid != 0)
    {
        body.append("&verbUid=");
        body.append(std::to_string(verbUid));
    }
    json data = this->authed_request("verbTranslationController/getVerbCategories", body);
    std::vector<languagenut::types::verb> verbs;
    for (json i : data["verbs"])
        verbs.push_back(languagenut::types::verb(i));
    return verbs;
}