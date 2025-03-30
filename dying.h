#ifndef DYING_H
#define DYING_H

#include <iostream>
#include <string>
#include <map>

using namespace std; // Use the standard namespace for brevity

void dying(const string &reason, map<string, int> &game_variables)
{
    // Display the reason for death
    if (!reason.empty())
    {
        if (reason == "no_food")
        {
            cout << "You ran out of food and starved to death." << endl;
        }
        else if (reason == "no_doctor")
        {
            cout << "You can't afford a doctor." << endl;
        }
        else if (reason == "no_supplies")
        {
            cout << "You ran out of medical supplies." << endl;
        }
        else if (reason == "injury")
        {
            cout << "You died of injuries." << endl;
        }
    }

    // Display final messages
    cout << "\nDue to your unfortunate situation, there are a few formalities we must go through.\n"
         << endl;
    cout << "Would you like a minister?" << endl;
    cout << "Would you like a fancy funeral?" << endl;
    cout << "Would you like us to inform your next of kin?" << endl;
    cout << "\nBut your Aunt Sadie in St. Louis is really worried about you." << endl;
    cout << "That will be $4.50 for the telegraph charge.\n"
         << endl;
    cout << "We are sorry you didn't make it to the great territory of Oregon." << endl;
    cout << "Better luck next time.\n"
         << endl;
    cout << "\tSincerely," << endl;
    cout << "\tThe Oregon City Chamber of Commerce" << endl;

    // Mark the player as dead
    game_variables["dead"] = 1;
}

#endif // DYING_H