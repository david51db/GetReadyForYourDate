//
// Created by David on 4/19/2026.
//

#ifndef GETREADYFORYOURDATE_RANDOMEVENT_H
#define GETREADYFORYOURDATE_RANDOMEVENT_H

#include <iostream>
#include <string>
#include "Event.h"
#include <vector>

class RandomEvent : public virtual Event{
protected:
    int chance;
    std::string avoidStat;
    int avoidThreshold;
    std::string textAvoided;
    std::string textResult;

public:
    RandomEvent();
    RandomEvent(int chance, std::string avoidStat, int avoidThreshold, std::string textAvoided, std::string textResult, std::string text, bool phase);
    RandomEvent(const RandomEvent& obj);
    RandomEvent& operator=(const RandomEvent& obj);
    ~RandomEvent() override;

    friend std::ostream& operator<<(std::ostream& os, const RandomEvent& obj);
    friend std::istream& operator>>(std::istream& is, RandomEvent& obj);

    // void trigger() override;

    void loadFromFile(std::ifstream &fin) override;
};



#endif //GETREADYFORYOURDATE_RANDOMEVENT_H