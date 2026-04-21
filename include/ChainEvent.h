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
    ChainEvent(const ChainEvent& obj);
    ChainEvent& operator=(const ChainEvent& obj);
    ~ChainEvent() override;

    friend std::ostream& operator<<(std::ostream& os, const ChainEvent& obj);
    friend std::istream& operator>>(std::istream& is, ChainEvent& obj);

    // void trigger() override;
};



#endif //GETREADYFORYOURDATE_CHAINEVENT_H