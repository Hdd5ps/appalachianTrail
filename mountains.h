#ifndef MOUNTAINS_H
#define MOUNTAINS_H

#include <iostream>
#include <map>
#include <string>
#include "randomnumber.h" // Custom random number library

using namespace std; // Use the standard namespace for brevity

map<string, int> mountains(map<string, int>& game_variables)
{
    // Get mileage
    double mileage = game_variables["mileage"];
    double mountain_check = 9 - ((mileage / 100 - 15) * (mileage / 100 - 15) + 72) /
                                    ((mileage / 100 - 15) * (mileage / 100 - 15) + 12);

    // Check if you are caught in the mountains
    if (getRandomNumber(1, 10) > mountain_check)
    {
        if (game_variables["south_pass_flag"])
        {
            // Check for a blizzard in the mountains
            if (getRandomNumber(1, 100) < 81)
            {
                cout << "You have been caught in a Blizzard in the Mountain Pass - Time and Supplies lost." << endl;
                game_variables["supplies"] -= 10;
                game_variables["mileage"] -= 50;
            }
            else
            {
                cout << "You made it safely through the South Pass -- No Snow" << endl;
                if (mileage < 1700)
                {
                    game_variables["South_Pass_Mileage_Flag"] = 1;
                    return game_variables;
                }
            }
        }
        else
        {
            cout << "\nYou find yourself in some rugged mountains." << endl;
            game_variables["mileage"] -= 60;

            // Check for a blizzard in rugged mountains (33% chance)
            if (getRandomNumber(1, 100) < 34)
            {
                cout << "You have been caught in a Blizzard in the Mountain Pass - Time and Supplies lost." << endl;
                game_variables["supplies"] -= 10;
                game_variables["mileage"] -= 50;
            }
            else if (getRandomNumber(1, 100) > 10)
            {
                cout << "\nWagon Damaged! - Lose time and supplies.\nThe going gets slow." << endl;
                game_variables["supplies"] -= 5;
                game_variables["ammunition"] -= 200;
                game_variables["clothing"] -= getRandomNumber(1, 40);
                game_variables["mileage"] -= 30 + getRandomNumber(1, 40);
            }
            else
            {
                cout << "\nYou got lost - lose valuable time trying to find the trail!" << endl;
                game_variables["mileage"] -= 60;
            }
        }
    }

    return game_variables;
}

#endif // MOUNTAINS_H