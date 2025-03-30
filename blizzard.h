#ifndef BLIZZARD_H
#define BLIZZARD_H

#include <iostream>
#include <map>
#include <string>
#include "randomnumber.h" // Include your custom random number library
#include <thread>
#include <chrono>

using namespace std; // Use the standard namespace for brevity

// Function prototypes
map<string, int> illness(map<string, int> &game_variables);
void dying(const string &reason);

map<string, int> blizzard(map<string, int> &game_variables)
{
    int base_chance_of_blizzard_over = 20;

    while (true)
    {
        cout << "\nThe Snow and wind continues to rage." << endl;
        game_variables["blizzard"] = 1; // Set blizzard flag to true
        game_variables["food"] -= 25;
        game_variables["supplies"] -= 10;
        game_variables["ammunition"] -= 300;
        game_variables["mileage"] -= 30 + getRandomNumber(1, 40);

        // Check if you have enough clothing to survive the blizzard
        if (game_variables["clothing"] < 18 + getRandomNumber(1, 3))
        {
            game_variables = illness(game_variables);
        }

        // Did the weather clear?
        if (getRandomNumber(1, 100) < base_chance_of_blizzard_over)
        {
            cout << "\nHurray! The Snow and wind start to break." << endl;
            break;
        }

        // Increase the chance of the blizzard ending
        base_chance_of_blizzard_over += 10;

        // Check if mileage is less than 1000
        if (game_variables["mileage"] < 1000)
        {
            cout << "\nThrough the wind and snow, you finally make it out of the mountains. But the wrong side." << endl;
            break;
        }

        // Check if you ran out of food
        if (game_variables["food"] < 0)
        {
            game_variables["food"] = 0;
            dying("no_food");
        }

        // Check if you ran out of supplies
        if (game_variables["supplies"] < 0)
        {
            game_variables["supplies"] = 0;
            dying("no_supplies");
        }

        // Slow down the loop for readability
        this_thread::sleep_for(chrono::seconds(5));
    }

    return game_variables;
}

#endif // BLIZZARD_H
