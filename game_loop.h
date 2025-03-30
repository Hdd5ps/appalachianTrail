#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <iostream>
#include <map>
#include <string>
#include <limits>
#include "user_stats.h"
#include "dying.h"
#include "fort.h"
#include "hunting.h"
#include "randomnumber.h" // Custom random number library

using namespace std; // Use the standard namespace for brevity

map<string, int> game_loop(map<string, int>& game_variables)
{
    int input_x = 0;

    // Ensure no negative values for resources
    game_variables["food"] = max(0, game_variables["food"]);
    game_variables["ammunition"] = max(0, game_variables["ammunition"]);
    game_variables["clothing"] = max(0, game_variables["clothing"]);
    game_variables["supplies"] = max(0, game_variables["supplies"]);

    if (game_variables["food"] < 13)
    {
        cout << "\n\nYou'd better do some hunting or buy food and soon!!!!" << endl;
    }

    // Update turn mileage
    game_variables["turn_mileage"] = game_variables["mileage"];

    // Handle illness or injury
    if (game_variables["illness"] || game_variables["injury"])
    {
        game_variables["cash"] -= 20;
        game_variables["illness"] = 0;
        game_variables["injury"] = 0;
        if (game_variables["cash"] < 0)
        {
            dying("no_doctor", game_variables);
        }
        cout << "Doctor's Bill is $20." << endl;
    }

    // Display mileage
    if (game_variables["South_Pass_Mileage_Flag"])
    {
        cout << "Total Mileage:   950" << endl;
    }
    else
    {
        cout << "Total Mileage:   " << game_variables["mileage"] << endl;
    }

    // Display user stats
    user_stats(game_variables);

    // Handle user input for actions
    if (!game_variables["fort_flag"])
    {
        while (true)
        {
            cout << "\nDo you want to (1) Hunt, or (2) Continue: ";
            cin >> input_x;

            if (cin.fail() || input_x < 1 || input_x > 2)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Sorry, I didn't understand that." << endl;
                continue;
            }

            if (input_x == 2 && game_variables["ammunition"] < 39)
            {
                cout << "TOUGH -- You need more bullets to go hunting." << endl;
            }
            else
            {
                game_variables["fort_flag"] = 1;
                break;
            }
        }
    }
    else
    {
        while (true)
        {
            cout << "\nDo you want to (1) Stop at the next fort, (2) Hunt, or (3) Continue: ";
            cin >> input_x;

            if (cin.fail() || input_x < 1 || input_x > 3)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Sorry, I didn't understand that." << endl;
                continue;
            }

            if (input_x == 2 && game_variables["ammunition"] < 39)
            {
                cout << "TOUGH -- You need more bullets to go hunting." << endl;
            }
            else
            {
                break;
            }
        }
    }

    // Handle user choices
    if (input_x == 1)
    {
        game_variables = fort(game_variables);
    }
    else if (input_x == 2)
    {
        game_variables = hunting(game_variables);
    }

    // Check for starvation
    if (game_variables["food"] < 14)
    {
        dying("no_food", game_variables);
    }

    // Handle eating choice
    while (true)
    {
        cout << "Do you want to eat (1) Poorly, (2) Moderately, or (3) Well: ";
        cin >> input_x;

        if (cin.fail() || input_x < 1 || input_x > 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Sorry, I didn't understand that." << endl;
            continue;
        }

        if ((game_variables["food"] - (8 - 5 * input_x)) < 0)
        {
            cout << "You can't eat that well." << endl;
        }
        else
        {
            break;
        }
    }

    // Update game variables
    game_variables["food"] -= (8 + 5 * input_x);

    // Random mileage calculation
    game_variables["mileage"] += 200 + (game_variables["animals"] - 220) / 5 + getRandomNumber(1, 10);

    game_variables["insufficient_clothing"] = 0;
    game_variables["blizzard"] = 0;

    return game_variables;
}

#endif // GAME_LOOP_H