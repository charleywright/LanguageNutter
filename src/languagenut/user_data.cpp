#include "languagenut.hpp"

languagenut::types::user_data languagenut::client::get_user_data()
{
    json data = this->authed_request("userDataController/getUserData");
    return languagenut::types::user_data(data);
}