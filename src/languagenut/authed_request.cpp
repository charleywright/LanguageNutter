#include "languagenut.hpp"
#include <curl/curl.h>
#include "json.hpp"
#include "write_callback.hpp"
#include <chrono>

nlohmann::json languagenut::client::authed_request(std::string path, std::string data)
{
    std::string url = "https://api.languagenut.com/";
    url.append(path);
    url.append("?cacheBreaker=");
    std::string epoch = std::to_string(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
    url.append(epoch);
    curl_easy_setopt(this->m_curl, CURLOPT_URL, url.c_str());
    std::string body = "apiVersion=8&token=";
    body.append(this->m_token);
    body.append("&languagenutTimeMarker=");
    body.append(epoch);
    body.append("&lastLanguagenutTimeMarker");
    body.append(epoch);
    if (data.length() > 0)
    {
        body.append("&");
        body.append(data);
    }
    curl_easy_setopt(this->m_curl, CURLOPT_POSTFIELDS, body.c_str());
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    curl_easy_setopt(this->m_curl, CURLOPT_HTTPHEADER, headers);
    std::string response;
    curl_easy_setopt(this->m_curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(this->m_curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_perform(this->m_curl);
    nlohmann::json parsed = nlohmann::json::parse(response);
    if (parsed.contains("newToken") && parsed.value("newToken", "").length() > 0)
        this->m_token = parsed.value("newToken", "");
    return parsed;
}