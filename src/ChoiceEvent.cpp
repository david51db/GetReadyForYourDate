//
// Created by David on 4/19/2026.
//

#include <iostream>
#include "ChoiceEvent.h"
#include "Choice.h"
#include "Player.h"
#include <vector>
#include <string>
using namespace std;
#include <sstream>
#include <fstream>


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

void ChoiceEvent::loadFromFile(ifstream &fin) {
    string line;
    string token;

    getline(fin, line);

    while (line.empty()&&!fin.eof())getline(fin, line);

    stringstream ss(line);
    getline(ss, token, '|');
    this->text=token;

    getline(ss, token);
    this->phase=stoi(token);

    choices.clear();

    while (getline(fin, line)) {
        if (line=="---") break;

        if (line.empty())continue;

        Choice c;
        c.parseFromString(line);
        choices.push_back(c);
    }
}

void ChoiceEvent::trigger(Player& player) {
    cout<<this->text<<"\n";

    for (int i=0;i<choices.size();i++) {
        cout<<i+1<<". "<<choices[i].getText()<<" | Price: ";
        cout<<choices[i].getPrice()<<"\n";
    }

    cout<<"Please type your answer.\n";

    int choice;
    cin>>choice;

    for (int i=0;i<choices.size();i++) {
        if (choice-1==i)player.applyEffects(choices[i]);
    }

    ChoiceEvent* followUp = choices[choice-1].getFollowUp();
    if (followUp != nullptr) {
        followUp->trigger(player);
    }

}
