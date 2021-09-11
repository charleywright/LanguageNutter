#include <iostream>
#include "languagenut/languagenut.hpp"

int main()
{
    std::string token = languagenut::login("CharlesW", "badger7179");
    std::vector<languagenut::types::global_user> users = languagenut::get_global_rankings(token, 5000);
    for (languagenut::types::global_user u : users)
    {
        std::cout << u.flag << std::endl;
    }
}