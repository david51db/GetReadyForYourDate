//
// Created by David on 4/19/2026.
//

#include <iostream>
#include "Choice.h"
#include "ChoiceEvent.h"
#include <vector>
#include <string>
using namespace std;

Choice::Choice() {
    price=0;
    text="N/A";
    deltaCharm=0;
    deltaDignity=0;
    deltaVibe=0;
    deltaMoney=0;
    followUp=nullptr;
}

Choice::Choice(int price, std::string text, int deltaCharm, int deltaDignity, int deltaVibe, int deltaMoney, ChoiceEvent* followUp) {
    this->price=price;
    this->text=text;
    this->deltaCharm=deltaCharm;
    this->deltaDignity=deltaDignity;
    this->deltaMoney=deltaMoney;
    this->deltaVibe=deltaVibe;
    this->followUp=followUp;
}

Choice::Choice(const Choice &obj) {
    this->price=obj.price;
    this->text=obj.text;
    this->deltaCharm=obj.deltaCharm;
    this->deltaDignity=obj.deltaDignity;
    this->deltaMoney=obj.deltaMoney;
    this->deltaVibe=obj.deltaVibe;
    this->followUp=obj.followUp;
}

Choice &Choice::operator=(const Choice &obj) {
    if (this==&obj) return *this;

    this->price=obj.price;
    this->text=obj.text;
    this->deltaCharm=obj.deltaCharm;
    this->deltaDignity=obj.deltaDignity;
    this->deltaMoney=obj.deltaMoney;
    this->deltaVibe=obj.deltaVibe;
    this->followUp=obj.followUp;

    return *this;
}

Choice::~Choice() =default;

ostream& operator<<(ostream& os, const Choice& obj) {
    os<<"Text: "<<obj.text<<"\n";
    os<<"Price: "<<obj.price<<"\n";
    os<<"Delta Charm: "<<obj.deltaCharm<<"\n";
    os<<"Delta Dignity: "<<obj.deltaDignity<<"\n";
    os<<"Delta Vibe: "<<obj.deltaVibe<<"\n";
    os<<"Delta Money: "<<obj.deltaMoney<<"\n";
    if (obj.followUp!=nullptr) os<<"Follow Up Question\n"<<*obj.followUp<<"\n";

    return os;
}

istream& operator>>(istream& is, Choice& obj) {
    cout<<"Text: ";
    is>>obj.text;

    cout<<"Price: ";
    is>>obj.price;

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
