#ifndef FORT_H
#define FORT_H

#include <iostream>
#include <map>
#include <string>
#include "buying_routine.h"

using namespace std; // Use the standard namespace for brevity

map<string, int> fort(map<string, int>& game_variables)
{
    cout << "Enter what you wish to spend on the following:" << endl;

    // Food
    int food = buying_routine("food", 0, 9999, game_variables["cash"]);
    game_variables["cash"] -= food;
    game_variables["food"] += static_cast<int>(0.66 * food);

    // Ammo
    int ammo = buying_routine("ammo", 0, 9999, game_variables["cash"]);
    game_variables["cash"] -= ammo;
    game_variables["ammunition"] += static_cast<int>(0.66 * ammo) * 50;

    // Clothing
    int clothing = buying_routine("clothing", 0, 9999, game_variables["cash"]);
    game_variables["cash"] -= clothing;
    game_variables["clothing"] += static_cast<int>(0.66 * clothing);

    // Miscellaneous supplies
    int misc = buying_routine("miscellaneous supplies", 0, 9999, game_variables["cash"]);
    game_variables["cash"] -= misc;
    game_variables["supplies"] += static_cast<int>(0.66 * misc);

    // Mileage adjustment
    game_variables["mileage"] -= 45;

    return game_variables;
}

#endif // FORT_H