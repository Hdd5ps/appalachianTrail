#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "setup.h"
#include "instructions.h"
#include "initial_purchases.h"
#include "game_loop.h"
#include "do_events.h"
#include "riders.h"
#include "mountains.h"
#include "final_turn.h"
#include "dying.h"

using namespace std;

void start_game()
{
    // Initialize game variables
    map<string, int> game_variables = setup();

    // Ask if the user needs instructions
    string input;
    cout << "Do you need instructions on how to navigate the Appalachian Trail (yes/no): ";
    cin >> input;
    if (input == "yes")
    {
        instructions();
    }

    // Define game week dates
    vector<string> game_week_dates = {
        "March 29", "April 12", "April 26", "May 10", "May 24", "June 7", "June 21", "July 5", "July 19",
        "August 2", "August 16", "August 31", "September 13", "September 27", "October 11", "October 25",
        "November 8", "November 22", "December 6", "December 20"};

    // Ask the user for their hiking skill level
    cout << "\nHow experienced are you as a hiker?" << endl;
    cout << "\t(1) Expert hiker,  (2) Experienced,  (3) Intermediate" << endl;
    cout << "\t(4) Beginner,  (5) First time on a trail" << endl;
    int my_hiking_skill;
    cout << "Enter one of the above -- the better you claim you are, the\n"
         << "more prepared you'll need to be for the challenges ahead: ";
    cin >> my_hiking_skill;

    if (my_hiking_skill > 5 || my_hiking_skill < 1)
    {
        my_hiking_skill = 0;
    }
    game_variables["hiking_skill_level"] = my_hiking_skill;

    // Perform initial purchases
    game_variables = initial_purchases(game_variables);
    game_variables["game_turn"] = -1;

    // Main game loop
    while (true)
    {
        game_variables["game_turn"] += 1;

        if (game_variables["game_turn"] < 19)
        {
            if (game_variables["mileage"] > 2040)
            {
                final_turn(game_variables);
                break;
            }

            cout << "\nMonday, " << game_week_dates[game_variables["game_turn"]] << ", 1847" << endl;

            game_loop(game_variables);
            if (game_variables["dead"])
            {
                break;
            }

            do_events(game_variables);
            if (game_variables["dead"])
            {
                break;
            }

            riders(game_variables);
            if (game_variables["dead"])
            {
                break;
            }

            // Check if the player has reached the mountains
            if (game_variables["mileage"] > 950)
            {
                game_variables = mountains(game_variables);
                if (game_variables["dead"])
                {
                    break;
                }
            }
        }
        else
        {
<<<<<<< HEAD
            cout << "\nYou have been on the Appalachian Trail for too long.\n"
                 << "You and your group succumb to the harsh winter conditions." << endl;
=======
            cout << "\nYou have been on the trail too long\nYou die in the first blizzard of winter." << endl;
>>>>>>> dc11e1a30e7b57705d3c7c391a2bd67c20fdeaa6
            dying("", game_variables);
            break;
        }
    }
}

int main()
{
    start_game();
    return 0;
}
