#ifndef SETUP_H
#define SETUP_H

#include <map>
#include <string>

using namespace std; // Use the standard namespace for brevity

map<string, int> setup()
{
    // Set up the variables to be used in the game
    map<string, int> game_variables = {
        {"animals", 0},          // Amount spent on animals
        {"ammunition", 0},       // Amount spent on ammunition
        {"clothing", 0},         // Amount spent on clothing
        {"event_counter", 0},    // Counter in generating events
        {"game_turn", 0},        // Turn number for setting date
        {"shooting_expert_level", 0}, // Choice of shooting expertise level
        {"eating_choice", 0},    // Choice of eating
        {"food", 0},             // Amount spent on food
        {"mileage", 0},          // Total mileage for the whole trip
        {"supplies", 0},         // Amount spent on miscellaneous supplies
        {"turn_mileage", 0},     // Total mileage up through the previous turn
        {"cash", 700}            // Cash in your wallet
    };

    return game_variables;
}

#endif // SETUP_H