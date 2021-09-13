#include <iostream>
#include "languagenut/languagenut.hpp"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " username password" << std::endl;
        return 0;
    }

    languagenut::client client;
    bool valid = client.login(argv[1], argv[2]);
    if (!valid)
    {
        std::cout << "Invalid username or password" << std::endl;
        return 0;
    }
    client.init();
    languagenut::types::user_data d = client.get_user_data();
    std::cout << d.gold_medals << std::endl;
}