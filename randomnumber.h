#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random> // Required for std::mt19937 and std::uniform_int_distribution

// Removed duplicate definition of getRandomNumber(int, int)

// Function to generate a random number between min and max (inclusive)
static inline int getRandomNumber(int min, int max)
{
    static std::mt19937 gen(static_cast<unsigned int>(::time(0))); // Mersenne Twister engine
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

float getRandomFloat(float min, float max) {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Generate a random number between min and max
    float num = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min) + min;
    return num;
}

double getRandomDouble(double min, double max) {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Generate a random number between min and max
    double num = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) * (max - min) + min;
    return num;
}

#endif // RANDOMNUMBER_H