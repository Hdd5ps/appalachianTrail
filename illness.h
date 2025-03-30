#ifndef ILLNESS_H
#define ILLNESS_H

#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include "randomnumber.h" // Include the randomnumber.h header
#include "dying.h"        // Include the dying.h header to avoid undefined reference

using namespace std; // Use the standard namespace for brevity

map<string, int> illness(map<string, int>& game_variables)
{
    // Generate a random value
    int random_value = getRandomNumber(1, 100);
    int eating_choice = game_variables["eating_choice"];

    if (random_value < 10 + 35 * (eating_choice - 1))
    {
        cout << "Wild Illness - Medicine Used." << endl;
        game_variables["mileage"] -= 5;
        game_variables["supplies"] -= 2;
    }
    else if (random_value < 100 - (40 / pow(4, eating_choice - 1)))
    {
        cout << "Bad Illness - Medicine Used." << endl;
        game_variables["mileage"] -= 5;
        game_variables["supplies"] -= 5;
    }
    else
    {
        cout << "Serious Illness - You must stop for Medical Attention." << endl;
        game_variables["illness"] = 0; // Reset illness flag
        game_variables["supplies"] -= 10;
    }

    // Check if supplies are critically low
    if (game_variables["supplies"] < 10)
    {
        dying("no_supplies", game_variables); // Call dying function with game_variables
    }

    return game_variables;
}

#endif // ILLNESS_H