//
// Created by David on 4/19/2026.
//

#include <iostream>
#include "ChoiceEvent.h"
#include "Choice.h"
#include <vector>
#include <string>
using namespace std;


ChoiceEvent:: ChoiceEvent(): Event() {
}

ChoiceEvent:: ChoiceEvent(vector<Choice>& choices, string text, bool phase) : Event(text, phase) {
    this->choices=choices;
}

ChoiceEvent::ChoiceEvent(const ChoiceEvent &obj) : Event(obj){
    this->choices=obj.choices;
}

ChoiceEvent& ChoiceEvent::operator=(const ChoiceEvent &obj) {
    if (this==&obj) return *this;

    Event::operator=(obj);
    this->choices=obj.choices;

    return *this;
}

ChoiceEvent:: ~ChoiceEvent()=default;

ostream &operator<<(ostream &os, const ChoiceEvent &obj) {

    os<< static_cast<const Event &>(obj);
    for (int c=0;c<obj.choices.size();c++) {
        os<<"Choice "<<c+1<<" :\n";
        os<<obj.choices[c]<<"\n";
    }
    os<<"\n";

    return os;

}

istream& operator>>(istream &is, ChoiceEvent &obj) {

    is>>static_cast<Event &>(obj);

    for (int c=0;c<obj.choices.size();c++) {
        cout<<"Choice "<<c+1<<" :\n";
        is>>obj.choices[c];
        cout<<"\n";
    }
    cout<<"\n";
    return is;
}
