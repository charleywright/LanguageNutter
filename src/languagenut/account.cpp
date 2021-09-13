#include "languagenut.hpp"
#include "json.hpp"

languagenut::types::account languagenut::client::get_account()
{
    nlohmann::json res = this->authed_request("accountController/getInformation");
    types::account acc(res["account"]);
    return acc;
}