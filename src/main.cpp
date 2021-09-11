#include <iostream>
#include "languagenut/languagenut.hpp"

int main()
{
    std::string token = languagenut::login("CharlesW", "badger7179");
    std::vector<languagenut::types::assignment> a = languagenut::get_assignments(token);
}