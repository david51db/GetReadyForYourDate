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


ChainEvent::ChainEvent(vector<Choice>& choices, string text, bool phase,
                       int chance, string avoidStat, int avoidThreshold,
                       string textAvoided, string textResult)
    : Event(text, phase),
      ChoiceEvent(choices, text, phase),
      RandomEvent(chance, avoidStat, avoidThreshold, textAvoided, textResult, text, phase) {
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

    os<<static_cast<const Event&>(obj);


    for (int c=0;c<obj.choices.size();c++) {
        os<<"Choice "<<c+1<<" :\n";
        os<<obj.choices[c]<<"\n";
    }
    os<<"\n";


    os<<"Chance: "<<obj.chance<<"\n";
    if (obj.avoidStat!="") {
        os<<"Avoid stat: "<<obj.avoidStat<<"\n";
        os<<"Avoid Threshold: "<<obj.avoidThreshold<<"\n";
        os<<"Text for avoided: "<<obj.textAvoided<<"\n";
    }
    os<<"Text for result: "<<obj.textResult<<"\n";

    return os;
}

istream& operator>>(istream &is, ChainEvent& obj) {

    is>>static_cast<Event&>(obj);

    cout<<"Chance: ";
    is>>obj.chance;

    cout<<"Avoid Stat (Enter blank for positive random event): ";
    is>>obj.avoidStat;

    if (obj.avoidStat!="") {
        cout<<"Avoid Threshold: ";
        is>>obj.avoidThreshold;

        cout<<"Text for avoided: ";
        is>>obj.textAvoided;
    }

    cout<<"Text for result: ";
    is>>obj.textResult;

    for (int c=0;c<obj.choices.size();c++) {
        cout<<"Choice "<<c+1<<" :\n";
        is>>obj.choices[c];
        cout<<"\n";
    }
    cout<<"\n";





    return is;

}
