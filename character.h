/*
Charaacter setters and getters
*/
#ifndef __CHARACTER_H__
#define __CHARACTER_H__


#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Character
{
private:
    string name;
    int health;
    int strength;
    int defense;
    int speed;
    int level;
    int experience;
    int maxHealth;
    int maxStrength;
    int maxDefense;
    int maxSpeed;

public:
    Character(string name, int health, int strength, int defense, int speed)
        : name(name), health(health), strength(strength), defense(defense), speed(speed),
          level(1), experience(0), maxHealth(health), maxStrength(strength),
          maxDefense(defense), maxSpeed(speed) {}

    // Getters
    string getName() const { return name; }
    int getHealth() const { return health; }
    int getStrength() const { return strength; }
    int getDefense() const { return defense; }
    int getSpeed() const { return speed; }
    int getLevel() const { return level; }
    int getExperience() const { return experience; }

    // Setters
    void setName(string newName) { name = newName; }
    void setHealth(int newHealth) { health = newHealth; }
    void setStrength(int newStrength) { strength = newStrength; }
    void setDefense(int newDefense) { defense = newDefense; }
    void setSpeed(int newSpeed) { speed = newSpeed; }
};
    void setLevel(int newLevel) { level = newLevel; }
    void setExperience(int newExperience) { experience = newExperience; }

    // Other methods
    void levelUp()
    {
        level++;
        maxHealth += 10;
        maxStrength += 2;
        maxDefense += 2;
        maxSpeed += 1;
        health = maxHealth;
    }

    void gainExperience(int exp)
    {
        experience += exp;
        if (experience >= 100)
        {
            levelUp();
            experience -= 100;
        }
    }
};  
#endif // __CHARACTER_H__

