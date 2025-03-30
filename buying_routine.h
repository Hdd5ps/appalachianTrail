#ifndef BUYING_ROUTINE_H
#define BUYING_ROUTINE_H

#include <iostream>
#include <string>
#include <limits>

int buying_routine(const std::string& object_name, int min_amount, int max_amount, int wallet)
{
    int my_purchase = 0;

    while (true)
    {
        std::cout << "Wallet: " << wallet << ". How much do you want to spend on your " << object_name << ": ";
        std::cin >> my_purchase;

        // Validate input
        if (!std::cin)
        {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Sorry, I didn't understand that." << std::endl;
            continue;
        }

        if (my_purchase < min_amount)
        {
            std::cout << "Sorry, that is not enough." << std::endl;
        }
        else if (my_purchase > max_amount)
        {
            std::cout << "Sorry, that is too much." << std::endl;
        }
        else if (my_purchase > wallet)
        {
            std::cout << "You don't have that much - keep your spending down." << std::endl;
        }
        else
        {
            break; // Valid input
        }
    }

    return my_purchase;
}

#endif // BUYING_ROUTINE_H