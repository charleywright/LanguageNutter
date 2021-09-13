#include "languagenut.hpp"

languagenut::types::curriculum languagenut::client::get_curriculum(int uid)
{
    std::string body = "curriculumUid=";
    body.append(std::to_string(uid));
    json data = this->authed_request("packageController/getCurriculumData", body);
    return languagenut::types::curriculum(data);
}