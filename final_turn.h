#ifndef FINAL_TURN_H
#define FINAL_TURN_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "user_stats.h"

void final_turn(std::map<std::string, int>& game) {
    std::cout << "\nYou arrived at Oregon City!\n2040 miles - Hooray!!\nA Real Pioneer!\n";

    // Calculate time and food
    int distance_traveled = game["mileage"] - game["turn_mileage"];
    double time_ratio = static_cast<double>(2040 - game["turn_mileage"]) / std::max(1.0, static_cast<double>(distance_traveled));
    game["food"] += static_cast<int>((1.0 - time_ratio) * (8 + 5 * game["eating_choice"]));

    // Calculate days passed
    int days_passed = static_cast<int>(time_ratio * 14.0);
    game["game_turn"] += days_passed;

    // Determine day of the week
    std::vector<std::string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    std::string day_name = days[days_passed % 7];

    // Determine month and day
    int game_days = game["game_turn"];
    int month_day = 0;
    std::string month_name = "";

    // Using a lookup table (array of pairs) for month names and start days
    std::pair<int, const char*> months[] = {
        {93, "July"},
        {124, "August"},
        {155, "September"},
        {185, "October"},
        {216, "November"},
        {246, "December"}
    };

    for (const auto& month : months) {
        if (game_days < month.first) {
            month_name = month.second;
            month_day = game_days - (month.first - (month.first == 93 ? 0 : months[0].first)); // Adjust to July start
            break;
        }
        if(month.second == "December"){
            month_name = month.second;
            month_day = game_days - month.first;
            break;
        }

    }

    // Output date
    std::cout << day_name << ", " << month_name << " " << month_day << ", 1847\n";

    // Display user stats
    user_stats(game);

    // Final message
    std::cout << "\tPresident Polk congratulates you\n";
    std::cout << "\tAnd wishes you a prosperous life.\n";
}

#endif // FINAL_TURN_H