#include "languagenut.hpp"
#include <curl/curl.h>
#include "json.hpp"
#include "write_callback.hpp"
#include <chrono>

bool languagenut::client::login(std::string username, std::string password)
{
    std::string epoch = std::to_string(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
    std::string url = "https://api.languagenut.com/loginController/attemptlogin?cacheBreaker=";
    url.append(epoch);
    curl_easy_setopt(this->m_curl, CURLOPT_URL, url.c_str());
    std::string body = "apiVersion=8&languagenutTimeMarker=";
    body.append(epoch);
    body.append("&lastLanguagenutTimeMarker=");
    body.append(epoch);
    body.append("&username=");
    body.append(username);
    body.append("&pass=");
    body.append(password);
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