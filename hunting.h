#ifndef HUNTING_H
#define HUNTING_H

#include <iostream>
#include <map>
#include <string>
#include <random>
#include "shooting.h"
#include "dying.h"

using namespace std; // Use the standard namespace for brevity

map<string, int> hunting(map<string, int>& game_variables)
{
    // Check if there are enough bullets to go hunting
    if (game_variables["ammunition"] > 39)
    {
        int my_shooting = shooting();
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 10);

        game_variables["ammunition"] -= dist(gen) * 3;

        if (my_shooting > 4)
        {
            cout << "You Missed -- and your dinner got away.." << endl;
        }
        else if (my_shooting < 3)
        {
            cout << "Right Between the Eyes - You got a big one!! Full bellies tonight!" << endl;
            game_variables["food"] += 52 + (my_shooting * 6);
        }
        else
        {
            cout << "Nice Shot! Right on target - Good Eatin' Tonight" << endl;
            game_variables["food"] += 48 - (my_shooting * 2);
        }
    }
    else
    {
        cout << "You need more bullets to go hunting." << endl;
    }

    // Adjust mileage
    game_variables["mileage"] -= 45;

    // Check if food is below the threshold
    if (game_variables["food"] < 14)
    {
        dying("no_food", game_variables);
    }

    return game_variables;
}

#endif // HUNTING_H