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
    int deltaCharm;
    int deltaDignity;
    int deltaVibe;
    int deltaMoney;

    bool checkAvoid(Player& player) const;
public:
    RandomEvent();
    RandomEvent(int deltaCharm, int deltaDignity, int deltaVibe, int deltaMoney, int chance, std::string &avoidStat,
                int avoidThreshold, std::string &textAvoided, std::string& textResult, std::string &text, bool phase);
    RandomEvent(const RandomEvent& obj);
    RandomEvent& operator=(const RandomEvent& obj);
    ~RandomEvent() override;

    friend std::ostream& operator<<(std::ostream& os, const RandomEvent& obj);
    friend std::istream& operator>>(std::istream& is, RandomEvent& obj);

    void trigger(Player& player) override;

    void loadFromFile(std::ifstream &fin) override;

    int getChance() const {return this->chance;}
    int getPhase() const {return this->phase;}
    std::string& getText() override{return this->text;}
};



#endif //GETREADYFORYOURDATE_RANDOMEVENT_H