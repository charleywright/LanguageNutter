#include "languagenut.hpp"

#include <iostream>

inline std::string bool_to_str(bool b) { return b ? "true" : "false"; }

std::vector<languagenut::types::module> languagenut::client::get_module_ids(int uid, bool customContent, bool order_game_type)
{
    std::string body = "screenUid=";
    body.append(std::to_string(uid));
    body.append("&getCustomContent=");
    body.append(bool_to_str(customContent));
    body.append("&orderByGameType=");
    body.append(bool_to_str(order_game_type));
    json data = this->authed_request("screensController/getModuleIds", body);
    std::vector<languagenut::types::module> modules;
    for (json i : data["modules"])
        modules.push_back(languagenut::types::module(i));
    return modules;
}