#ifndef SHOOTING_H
#define SHOOTING_H

#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>

using namespace std; // Use the standard namespace for brevity

int shooting()
{
    cout << "\nYou pull your gun, aim, and pull the trigger." << endl;
    cout << "Press the spacebar as quickly as possible when ready!" << endl;

    // Simulate a delay for user reaction
    srand(time(0));                     // Seed the random number generator
    int reaction_time = rand() % 5 + 1; // Random reaction time between 1 and 5 seconds

    // Simulate waiting for the user to press the spacebar
    this_thread::sleep_for(chrono::seconds(reaction_time));

    // Determine the score based on the simulated reaction time
    int my_score = 0;
    if (reaction_time == 1)
    {
        cout << "Wham!" << endl;
        my_score = 1;
    }
    else if (reaction_time == 2)
    {
        cout << "POW!" << endl;
        my_score = 2;
    }
    else if (reaction_time == 3)
    {
        cout << "Blam!" << endl;
        my_score = 3;
    }
    else if (reaction_time == 4)
    {
        cout << "Bang!" << endl;
        my_score = 4;
    }
    else
    {
        cout << "Pop!" << endl;
        my_score = 5;
    }

    return my_score;
}

#endif // SHOOTING_H