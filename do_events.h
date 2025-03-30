#ifndef DO_EVENTS_H
#define DO_EVENTS_H

#include <iostream>
#include <map>
#include <string>
#include "randomnumber.h" // Include your custom random number library
#include <thread>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include "shooting.h" // Ensure this header defines the shooting() function
#include "dying.h"    // Ensure this header defines the dying() function
#include "illness.h"  // Ensure this header defines the illness() function

using namespace std; // Use the standard namespace for brevity

map<string, int> do_events(map<string, int> &game_variables)
{
    // Ensure game_variables is passed correctly
    if (game_variables.empty())
    {
        cerr << "Error: game_variables is not initialized." << endl;
        return game_variables;
    }

    double ifrandom = getRandomNumber(1, 100);
    if (ifrandom < 50)
    {
        game_variables["event_counter"] += 1;
        int new_event = game_variables["event_counter"];

        switch (new_event)
        {
        case 1:
            cout << "Wagon breaks down - lose time and supplies fixing it" << endl;
            game_variables["supplies"] -= 8;
            game_variables["mileage"] -= getRandomNumber(1, 5);
            break;
        case 2:
            cout << "Ox injures leg - slows you down for the rest of trip" << endl;
            game_variables["animals"] -= 20;
            game_variables["mileage"] -= 25;
            break;
        case 3:
            cout << "Bad Luck - Your daughter broke her arm\nYou had to stop and use supplies to make a sling." << endl;
            game_variables["supplies"] -= 5;
            game_variables["mileage"] -= 5;
            break;
        case 4:
            cout << "Ox wanders off - spend time looking for it." << endl;
            game_variables["mileage"] -= 17;
            break;
        case 5:
            cout << "Your son gets lost - spend half the day looking for him" << endl;
            game_variables["mileage"] -= 10;
            break;
        case 6:
            cout << "Unsafe water - lose time looking for a clean spring." << endl;
            game_variables["mileage"] -= getRandomNumber(1, 10) + 2;
            break;
        case 7:
            cout << "Heavy rains - time and supplies lost" << endl;
            game_variables["food"] -= 10;
            game_variables["ammunition"] -= 500;
            game_variables["supplies"] -= 15;
            game_variables["mileage"] -= getRandomNumber(1, 10) + 5;
            break;
        case 8:
            cout << "Bandits Attack!" << endl;
            {
                int my_shooting = shooting();
                game_variables["ammunition"] -= (my_shooting * 20);
                if (game_variables["ammunition"] < 1)
                {
                    cout << "You ran out of bullets - They get lots of cash" << endl;
                    game_variables["cash"] /= 3;
                    cout << "You got shot in the leg and they took one of your oxen." << endl;
                    game_variables["injury"] = 1; // Set injury flag to true
                    cout << "Better have a doc look at your wound." << endl;
                    game_variables["supplies"] -= 5;
                    game_variables["animals"] -= 20;
                }
                else
                {
                    cout << "Quickest draw outside of Dodge City!!\nYou got 'em!" << endl;
                }
            }
            break;
        case 9:
            cout << "There was a fire in your wagon - Food and supplies damaged!" << endl;
            game_variables["food"] -= 40;
            game_variables["ammunition"] -= 400;
            game_variables["mileage"] -= 15;
            game_variables["supplies"] -= getRandomNumber(1, 8) + 3;
            break;
        case 10:
            cout << "Lose your way in heavy fog - Time is lost" << endl;
            game_variables["mileage"] -= 10 + getRandomNumber(1, 5);
            break;
        case 11:
            cout << "You killed a poisonous snake after it bit you" << endl;
            game_variables["ammunition"] -= 10;
            game_variables["supplies"] -= 5;
            if (game_variables["supplies"] < 1)
            {
                cout << "You die of snakebite since you have no medicine" << endl;
                dying("no_supplies", game_variables);
            }
            break;
        case 12:
            cout << "Wagon gets swamped fording river - lose food and clothes." << endl;
            game_variables["food"] -= 30;
            game_variables["clothing"] -= 20;
            game_variables["mileage"] -= 20 + getRandomNumber(1, 20);
            break;
        case 13:
            cout << "Wild animals attack!" << endl;
            if (game_variables["ammunition"] < 40)
            {
                cout << "You were too low on bullets - The wolves overpowered you" << endl;
                game_variables["injury"] = 1; // Set injury flag to true
            }
            else
            {
                int my_shooting = shooting();
                if (my_shooting > 2)
                {
                    cout << "Slow on the draw - They got at your food and clothes." << endl;
                }
                else
                {
                    cout << "Nice Shootin' Partner - They didn't get much." << endl;
                }
                game_variables["food"] -= (my_shooting * 8);
                game_variables["clothing"] -= (my_shooting * 4);
                game_variables["ammunition"] -= (my_shooting * 20);
            }
            break;
        case 14:
            cout << "Cold Weather!!" << endl;
            if (game_variables["clothing"] > getRandomNumber(1, 4) + 22)
            {
                cout << "You have enough clothing to keep you warm." << endl;
            }
            else
            {
                cout << "You don't have enough clothing to keep you warm." << endl;
                game_variables = illness(game_variables);
            }
            break;
        case 15:
            cout << "Hail Storm - Supplies Damaged" << endl;
            game_variables["ammunition"] -= 200;
            game_variables["supplies"] -= 4 + getRandomNumber(1, 3);
            game_variables["mileage"] -= 5 + getRandomNumber(1, 10);
            break;
        default:
            cout << "Helpful indians show you where to find more food." << endl;
            game_variables["food"] += 14;
            break;
        }
    }

    return game_variables;
}

#endif // DO_EVENTS_HgetRandomN