#ifndef RIDERS_H
#define RIDERS_H

#include <iostream>
#include <map>
#include <string>
#include "shooting.h"
#include "dying.h"
#include "randomnumber.h" // Custom random number library

using namespace std; // Use the standard namespace for brevity

map<string, int> riders(map<string, int>& game_variables)
{
    int my_tactic = 0;
    bool riders_hostile = false;

    // Calculate hostile chance
    double hostile_chance = ((game_variables["mileage"] / 100.0 - 4) * (game_variables["mileage"] / 100.0 - 4) + 72) /
                            ((game_variables["mileage"] / 100.0 - 4) * (game_variables["mileage"] / 100.0 - 4) + 12) - 1;

    if (getRandomNumber(1, 10) > hostile_chance)
    {
        return game_variables;
    }

    if (getRandomNumber(1, 10) < 3)
    {
        cout << "Strangers ahead. They don't look hostile." << endl;
        riders_hostile = false;
    }
    else
    {
        cout << "Strangers ahead. They look hostile." << endl;
        riders_hostile = true;
    }

    while (true)
    {
        cout << "\nTactics\n(1) Run (2) Attack (3) Continue (4) Circle: ";
        cin >> my_tactic;

        if (cin.fail() || my_tactic < 1 || my_tactic > 4)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Sorry, I didn't understand that." << endl;
            continue;
        }
        break;
    }

    if (riders_hostile)
    {
        if (my_tactic == 1)
        {
            // Run
            game_variables["mileage"] += 20;
            game_variables["ammunition"] -= 150;
            game_variables["animals"] -= 40;
        }
        else if (my_tactic == 2)
        {
            // Attack
            int my_shooting = shooting();
            game_variables["ammunition"] -= (my_shooting * 40) + 80;
            if (my_shooting == 1)
            {
                cout << "You drove them off." << endl;
            }
            else if (my_shooting > 4)
            {
                cout << "You got knifed\nYou have to see a doctor." << endl;
                game_variables["injury"] = 1;
            }
            else
            {
                cout << "Kinda slow" << endl;
            }
        }
        else if (my_tactic == 3)
        {
            // Continue
            if (getRandomNumber(1, 10) > 7)
            {
                cout << "They did not attack." << endl;
                riders_hostile = false;
            }
            else
            {
                game_variables["ammunition"] -= 150;
                game_variables["mileage"] -= 15;
            }
        }
        else
        {
            // Circle the wagons
            int my_shooting = shooting();
            game_variables["ammunition"] -= (my_shooting * 30) + 80;
            game_variables["mileage"] -= 25;
            if (my_shooting == 1)
            {
                cout << "You drove them off." << endl;
            }
            else if (my_shooting > 4)
            {
                cout << "You got knifed\nYou have to see a doctor." << endl;
                game_variables["injury"] = 1;
            }
            else
            {
                cout << "Kinda slow" << endl;
            }
        }
    }
    else
    {
        // Riders not hostile
        if (my_tactic == 1)
        {
            // Run
            game_variables["mileage"] += 15;
            game_variables["animals"] -= 10;
        }
        else if (my_tactic == 2)
        {
            // Attack
            game_variables["mileage"] -= 5;
            game_variables["ammunition"] -= 100;
        }
        else if (my_tactic == 3)
        {
            // Continue
            game_variables["mileage"] -= 5;
            cout << "They did not attack." << endl;
        }
        else
        {
            // Circle the wagons
            game_variables["mileage"] -= 5;
            cout << "They did not attack." << endl;
        }
    }

    if (riders_hostile)
    {
        cout << "The strangers were hostile - Check for losses." << endl;
        if (game_variables["ammunition"] < 1)
        {
            cout << "You got attacked by the strangers!" << endl;
            dying("injury", game_variables);
        }
    }
    else
    {
        cout << "The strangers were friendly, but check for possible losses." << endl;
    }

    return game_variables;
}

#endif // RIDERS_H
