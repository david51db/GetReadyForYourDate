//
// Created by David on 4/21/2026.
//

#ifndef GETREADYFORYOURDATE_CHAINEVENT_H
#define GETREADYFORYOURDATE_CHAINEVENT_H

#include <iostream>
#include "ChoiceEvent.h"
#include "RandomEvent.h"


class ChainEvent: public virtual RandomEvent, public virtual ChoiceEvent {
public:
    ChainEvent();
    ChainEvent(std::vector<Choice>& choices, std::string text, bool phase,
    int chance, std::string avoidStat, int avoidThreshold,
    std::string textAvoided, std::string textResult) ;
    ChainEvent(const ChainEvent& obj);
    ChainEvent& operator=(const ChainEvent& obj);
    ~ChainEvent() override;

    friend std::ostream& operator<<(std::ostream& os, const ChainEvent& obj);
    friend std::istream& operator>>(std::istream& is, ChainEvent& obj);

    void trigger(Player& player) override;

    void loadFromFile(std::ifstream &fin) override;
    std::string& getText(){return this->text;}
};



#endif //GETREADYFORYOURDATE_CHAINEVENT_H