#ifndef INITIAL_PURCHASES_H
#define INITIAL_PURCHASES_H

#include <iostream>
#include <map>
#include <string>
#include "buying_routine.h"

using namespace std; // Use the standard namespace for brevity

map<string, int> initial_purchases(map<string, int>& game_variables)
{
    // Oxen Team
    int oxen = buying_routine("oxen team", 200, 300, game_variables["cash"]);
    game_variables["cash"] -= oxen;

    // Food
    int food = buying_routine("food", 1, 99999, game_variables["cash"]);
    game_variables["cash"] -= food;

    // Ammo
    int ammo = buying_routine("ammunition", 1, 99999, game_variables["cash"]);
    game_variables["cash"] -= ammo;

    // Clothing
    int clothing = buying_routine("clothing", 1, 99999, game_variables["cash"]);
    game_variables["cash"] -= clothing;

    // Miscellaneous Supplies
    int misc = buying_routine("miscellaneous supplies", 1, 99999, game_variables["cash"]);
    game_variables["cash"] -= misc;

    // Calculate total remaining cash
    int total = 700 - oxen - clothing - ammo - food - misc;
    if (total < 0)
    {
        cout << "You Overspent -- You only had $700 to spend. Try Again." << endl;
        return initial_purchases(game_variables); // Restart the process
    }

    ammo *= 50; // Convert ammo to bullets
    cout << "After all your purchases, you now have " << total << " dollars left." << endl;

    // Update game variables
    game_variables["cash"] = total;
    game_variables["animals"] = oxen;
    game_variables["ammunition"] = ammo;
    game_variables["clothing"] = clothing;
    game_variables["food"] = food;
    game_variables["supplies"] = misc;

    return game_variables;
}

#endif // INITIAL_PURCHASES_H