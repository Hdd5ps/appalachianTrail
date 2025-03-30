#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <iostream>

void instructions()
{
    std::cout << "This program simulates a trip over the Appalachian Trail from GA to ME in the present day.\n";
    std::cout << "You had saved $700 to spend for the trip.\n";
    std::cout << "You will need to spend the rest of your money on the following items:\n\n";
    std::cout << "     Backpack - you can spend $200-$300 on one\n";
    std::cout << "            the more you spend, the faster you'll go\n";
    std::cout << "     Food - the more you have, the less chance there\n";
    std::cout << "            is of getting sick\n\n";
    std::cout << "     Ammunition - $1 buys a belt of 50 bullets\n";
    std::cout << "            you will need bullets for attacks by animals\n";
    std::cout << "            and for hunting food\n\n";
    std::cout << "     Clothing - this is especially important for the cold\n";
    std::cout << "            weather you will encounter when crossing\n";
    std::cout << "            the mountains\n\n";
    std::cout << "     Miscellaneous supplies - this includes medicine and\n";
    std::cout << "            other things you will need for sickness and\n";
    std::cout << "            emergency repairs\n\n";
    std::cout << "You can spend all your money before you start your trip -\n";
    std::cout << "or you can save some of your cash to spend at towns along\n";
    std::cout << "the way when you run low. However, items cost more at\n";
    std::cout << "the towns. You can also go hunting along the way to get\n";
    std::cout << "more food.\n\n";
    std::cout << "Whenever you have to use your trusty rifle along the way,\n";
    std::cout << "you will be told to type in a word (one that sounds like a\n";
    std::cout << "gun shot). The faster you type in that word and hit the\n";
    std::cout << "'return' key, the better luck you'll have with your gun.\n\n";
    std::cout << "At each turn, all items are shown in dollar amounts\n";
    std::cout << "except bullets.\n";
    std::cout << "When asked to enter money amounts, don't use a \"$\".\n\n";
    std::cout << "Good luck!!!" << std::endl;
}

#endif // INSTRUCTIONS_H
