/*
camping theme class
*/

#ifndef CAMPING_H
#define CAMPING_H
#include "theme.h"
#include <string>
#include <iostream>
#include <vector>

void campingTheme(std::vector<std::string> &items, std::vector<std::string> &activities) {
    items.push_back("Tent");
    items.push_back("Sleeping Bag");
    items.push_back("Flashlight");
    items.push_back("Camping Stove");
    items.push_back("First Aid Kit");

    activities.push_back("Hiking");
    activities.push_back("Fishing");
    activities.push_back("Stargazing");
    activities.push_back("Campfire Cooking");
    activities.push_back("Wildlife Watching");
}

class Camping : public Theme {
public:
    Camping() {
        std::vector<std::string> items;
        std::vector<std::string> activities;
        campingTheme(items, activities);
        setItems(items);
        setActivities(activities);
    }

    void displayTheme() override {
        std::cout << "Camping Theme:" << std::endl;
        for (const auto &item : getItems()) {
            std::cout << "- " << item << std::endl;
        }
        for (const auto &activity : getActivities()) {
            std::cout << "- " << activity << std::endl;
        }
    }
};

#endif // CAMPING_H