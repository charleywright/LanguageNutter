#include "languagenut.hpp"
#include <curl/curl.h>
#include "json.hpp"
#include "write_callback.hpp"

nlohmann::json languagenut::client::authed_request(std::string path, std::string data)
{
    CURL *curl = curl_easy_init();
    std::string url = "https://api.languagenut.com/";
    url.append(path);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    std::string body = "token=";
    body.append(this->m_token);
    if (data.length() > 0)
    {
        body.append("&");
        body.append(data);
    }
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    nlohmann::json parsed = nlohmann::json::parse(response);
    if (parsed.contains("newToken") && parsed.value("newToken", "").length() > 0)
        this->m_token = parsed.value("newToken", "");
    return parsed;
}