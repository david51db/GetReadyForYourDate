//
// Created by David on 4/19/2026.
//

#include <iostream>
#include "Choice.h"
#include <vector>
#include <string>
using namespace std;

Choice::Choice() {
    text="N/A";
    deltaCharm=0;
    deltaDignity=0;
    deltaVibe=0;
    deltaMoney=0;
}

Choice::Choice(std::string text, int deltaCharm, int deltaDignity, int deltaVibe, int deltaMoney) {
    this->text=text;
    this->deltaCharm=deltaCharm;
    this->deltaDignity=deltaCharm;
    this->deltaMoney=deltaMoney;
    this->deltaVibe=deltaVibe;
}

Choice::Choice(const Choice &obj) {
    this->text=obj.text;
    this->deltaCharm=obj.deltaCharm;
    this->deltaDignity=obj.deltaCharm;
    this->deltaMoney=obj.deltaMoney;
    this->deltaVibe=obj.deltaVibe;
}

Choice &Choice::operator=(const Choice &obj) {
    if (this==&obj) return *this;

    this->text=obj.text;
    this->deltaCharm=obj.deltaCharm;
    this->deltaDignity=obj.deltaDignity;
    this->deltaMoney=obj.deltaMoney;
    this->deltaVibe=obj.deltaVibe;

    return *this;
}

Choice::~Choice() =default;

ostream& operator<<(ostream& os, const Choice& obj) {
    os<<"Text: "<<obj.text<<"\n";
    os<<"Delta Charm: "<<obj.deltaCharm<<"\n";
    os<<"Delta Dignity: "<<obj.deltaDignity<<"\n";
    os<<"Delta Vibe: "<<obj.deltaVibe<<"\n";
    os<<"Delta Money: "<<obj.deltaMoney<<"\n";

    return os;
}

istream& operator>>(istream& is, Choice& obj) {
    cout<<"Text: ";
    is>>obj.text;

    cout<<"Delta Charm: ";
    is>>obj.deltaCharm;

    cout<<"Delta Dignity: ";
    is>>obj.deltaDignity;

    cout<<"Delta Vibe: ";
    is>>obj.deltaVibe;

    cout<<"Delta Money: ";
    is>>obj.deltaMoney;

    return is;

}
