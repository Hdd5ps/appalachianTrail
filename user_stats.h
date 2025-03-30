#ifndef USER_STATS_H
#define USER_STATS_H

#include <iostream>
#include <map>
#include <string>
// Removed <variant> as it is no longer needed

void user_stats(std::map<std::string, int> &game_variables)
{
    // If any of the variables are below zero, set them to zero
    if (game_variables["food"] < 0)
    {
        game_variables["food"] = 0;
    }
    if (game_variables["ammunition"] < 0)
    {
        game_variables["ammunition"] = 0;
    }
    if (game_variables["clothing"] < 0)
    {
        game_variables["clothing"] = 0;
    }
    if (game_variables["supplies"] < 0)
    {
        game_variables["supplies"] = 0;
    }
    if (game_variables["cash"] < 0)
    {
        game_variables["cash"] = 0;
    }

    // Display the user stats
    std::cout << "Food:            " << game_variables["food"] << std::endl;
    std::cout << "Bullets:         " << game_variables["ammunition"] << std::endl;
    std::cout << "Clothing:        " << game_variables["clothing"] << std::endl;
    std::cout << "Misc. Supplies:  " << game_variables["supplies"] << std::endl;
    std::cout << "Cash:            " << game_variables["cash"] << std::endl;
}

#endif // USER_STATS_H