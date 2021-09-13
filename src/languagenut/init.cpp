#include "languagenut.hpp"

void languagenut::client::init(std::string lang)
{
    std::string body = "language=";
    body.append(lang);
    json mod_translations = this->authed_request("translationController/getUserModuleTranslations", body);
    this->m_module_translations = mod_translations["translations"];
    json translations = this->authed_request("publicTranslationController/getTranslations", body);
    this->m_translations = translations["translations"];
}