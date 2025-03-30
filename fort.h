#ifndef FORT_H
#define FORT_H

#include <iostream>
#include <map>
#include <string>
#include "buying_routine.h"

using namespace std; // Use the standard namespace for brevity

map<string, int> fort(map<string, int>& game_variables)
{
    cout << "You have reached a resupply point along the Appalachian Trail." << endl;
    cout << "Enter how much you wish to spend on the following items:" << endl;

    // Food
    int food = buying_routine("food (essential for energy during the hike)", 0, 9999, game_variables["cash"]);
    game_variables["cash"] -= food;
    game_variables["food"] += static_cast<int>(0.66 * food);

    // First Aid Supplies
    int first_aid = buying_routine("first aid supplies (for treating injuries and illnesses)", 0, 9999, game_variables["cash"]);
    game_variables["cash"] -= first_aid;
    game_variables["first_aid"] += static_cast<int>(0.66 * first_aid);

    // Clothing
    int clothing = buying_routine("clothing (to stay warm and dry in changing weather)", 0, 9999, game_variables["cash"]);
    game_variables["cash"] -= clothing;
    game_variables["clothing"] += static_cast<int>(0.66 * clothing);

    // Miscellaneous supplies
    int misc = buying_routine("miscellaneous supplies (maps, water filters, tools, etc.)", 0, 9999, game_variables["cash"]);
    game_variables["cash"] -= misc;
    game_variables["supplies"] += static_cast<int>(0.66 * misc);

    // Mileage adjustment
    cout << "You take some time to rest and prepare for the next section of the trail." << endl;
    game_variables["mileage"] -= 45;

    return game_variables;
}

#endif // FORT_H