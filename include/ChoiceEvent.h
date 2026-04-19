//
// Created by David on 4/19/2026.
//

#ifndef GETREADYFORYOURDATE_CHOICEEVENT_H
#define GETREADYFORYOURDATE_CHOICEEVENT_H

#include <iostream>
#include <string>
#include "Event.h"
#include <vector>
#include "choice.h"


class ChoiceEvent: public virtual Event {
    std::vector<Choice> choices;

public:
    ChoiceEvent();
    ChoiceEvent(std::vector<Choice>& choices, std::string text, bool phase);
    ChoiceEvent(const ChoiceEvent& obj);
    ChoiceEvent& operator=(const ChoiceEvent& obj);
    ~ChoiceEvent();

    friend std::ostream& operator<<(std::ostream& os, const ChoiceEvent& obj);
    friend std::istream& operator>>(std::istream& is, ChoiceEvent& obj);

    // void trigger() override;
};

#endif //GETREADYFORYOURDATE_CHOICEEVENT_H