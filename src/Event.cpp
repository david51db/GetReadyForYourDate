//
// Created by David on 4/19/2026.
//

#include <iostream>
#include <string>
#include "Event.h"
using namespace std;

int Event::totalEvents=0;

Event::Event(): id(++totalEvents) {
    text="N/A";
    phase=0;
}

Event::Event(string& text, bool phase):id(++totalEvents) {
    this->text=text;
    this->phase=phase;
}

Event::Event(const Event &obj):id(obj.id) {
    this->text=obj.text;
    this->phase=obj.phase;
}

Event& Event::operator=(const Event& obj){
    if (this==&obj) return *this;

    this->text=obj.text;
    this->phase=obj.phase;

    return *this;
}


Event::~Event() = default;

ostream& operator<<(ostream& os, const Event& obj) {
    os<<"Text: " << obj.text<< "\n";
    os<<"Id: " << obj.id<< "\n";
    os<<"Phase: " << (obj.phase ? "Date" : "Prep") << "\n";

    return os;
}

istream& operator>>(istream& is, Event& obj) {
    cout<<"Text: ";
    is>>obj.text;

    cout<<"Phase (0 for Prep, 1 for Date): ";
    is>>obj.phase;

    return is;
}
