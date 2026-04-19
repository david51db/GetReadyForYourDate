//
// Created by David on 4/19/2026.
//

#ifndef GETREADYFORYOURDATE_CHOICE_H
#define GETREADYFORYOURDATE_CHOICE_H

#include <iostream>
#include <string>
#include <vector>

class Choice {
    std::string text;
    int deltaCharm;
    int deltaDignity;
    int deltaVibe;
    int deltaMoney;

public:
    Choice();
    Choice(std::string text, int deltaCharm, int deltaDignity, int deltaVibe, int deltaMoney);
    Choice(const Choice& obj);
    Choice& operator=(const Choice& obj);
    ~Choice();

    friend std::ostream& operator<<(std::ostream& os, const Choice& obj);
    friend std::istream& operator>>(std::istream& is, Choice& obj);
};



#endif //GETREADYFORYOURDATE_CHOICE_H

