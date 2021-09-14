#include "languagenut.hpp"

std::vector<languagenut::types::verb_translation> languagenut::client::get_verb_translations(int uid, int game_id, std::string from, std::string to)
{
    std::string body = "verbUid=";
    body.append(std::to_string(uid));
    body.append("&gameId=");
    body.append(std::to_string(game_id));
    body.append("&fromLanguage=");
    body.append(from);
    body.append("&toLanguage=");
    body.append(to);
    json data = this->authed_request("verbTranslationController/getVerbTranslations", body);
    std::vector<languagenut::types::verb_translation> translations;
    for (json i : data["verbTranslations"])
        translations.push_back(languagenut::types::verb_translation(i));
    return translations;
}