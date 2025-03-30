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
    cout << "Do you need instructions (yes/no): ";
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

    // Ask the user for their shooting skill level
    cout << "\nHow good a shot are you with your rifle?" << endl;
    cout << "\t(1) ace marksman,  (2) good shot,  (3) fair to middlin'" << endl;
    cout << "\t(4) need more practice,  (5) shaky knees" << endl;
    int my_shooting;
    cout << "Enter one of the above -- the better you claim you are, the\n"
         << "faster you'll have to be with your gun to be successful: ";
    cin >> my_shooting;

    if (my_shooting > 5 || my_shooting < 1)
    {
        my_shooting = 0;
    }
    game_variables["shooting_expert_level"] = my_shooting;

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
            cout << "\nYou have been on the trail too long\nYour family dies in the first blizzard of winter." << endl;
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