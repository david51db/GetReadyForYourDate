//
// Created by David on 4/21/2026.
//

#include <iostream>
#include "ChainEvent.h"
#include "ChoiceEvent.h"
#include "RandomEvent.h"
using namespace std;


ChainEvent::ChainEvent(): ChoiceEvent(), RandomEvent() {
}

ChainEvent::ChainEvent(const ChainEvent &obj): ChoiceEvent(obj), RandomEvent(obj) {
}

ChainEvent& ChainEvent::operator=(const ChainEvent& obj) {
    if (this==&obj) return *this;


    ChoiceEvent::operator=(obj);
    RandomEvent::operator=(obj);
    return *this;
}

ChainEvent::~ChainEvent() =default;

ostream& operator<<(ostream& os, const ChainEvent& obj) {

    os<<static_cast<const ChoiceEvent&>(obj);
    os<<static_cast<const RandomEvent&>(obj);

    return os;
}

istream& operator>>(istream &is, ChainEvent& obj) {

    is>>static_cast<ChoiceEvent&>(obj);
    is>>static_cast<RandomEvent&>(obj);

    return is;

}
