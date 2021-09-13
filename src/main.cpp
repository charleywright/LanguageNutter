#include <iostream>
#include "languagenut/languagenut.hpp"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " username password" << std::endl;
        return 0;
    }
    std::string token = languagenut::login(std::string(argv[1]), std::string(argv[2]));
    languagenut::types::user_data acc = languagenut::get_user_data(token);
    std::cout << acc.name << std::endl;
}