#include "languagenut.hpp"
#include <curl/curl.h>
#include "json.hpp"
#include "write_callback.hpp"

#include <iostream>

bool languagenut::client::login(std::string username, std::string password)
{
    curl_easy_setopt(this->m_curl, CURLOPT_URL, "https://api.languagenut.com/loginController/attemptlogin");
    std::string body = std::string("username=").append(username).append("&pass=").append(password);
    curl_easy_setopt(this->m_curl, CURLOPT_POSTFIELDS, body.c_str());
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    curl_easy_setopt(this->m_curl, CURLOPT_HTTPHEADER, headers);
    std::string response;
    curl_easy_setopt(this->m_curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(this->m_curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_perform(this->m_curl);
    nlohmann::json parsed = nlohmann::json::parse(response);
    this->m_token = parsed.value("newToken", "");
    return this->m_token.length() > 0;
}