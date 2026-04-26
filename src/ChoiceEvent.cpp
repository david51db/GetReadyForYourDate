//
// Created by David on 4/19/2026.
//

#include <iostream>
#include "ChoiceEvent.h"

#include <limits>

#include "Choice.h"
#include "Player.h"
#include "Game.h"
#include <vector>
#include <string>

#include "Exceptions.h"
#include "RPS.h"
using namespace std;
#include <sstream>
#include <fstream>


ChoiceEvent:: ChoiceEvent(): Event() {
}

ChoiceEvent:: ChoiceEvent(vector<Choice>& choices, string& text, bool phase) : Event(text, phase) {
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
    cout << "\n" << string(50, '-') << "\n\n";
    cout << this->text << "\n\n";


    cout << "Money: " << player.getMoney() << "\n\n";
    for (int i=0;i<(int)choices.size();i++) {
        cout << i+1 << ". " << choices[i].getText() << " | Price: " << choices[i].getPrice() << "\n";
    }

    cout << "Please type your answer.\n";

    int choice;
    while (true) {
        try {
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException("option must be between 1 and " + to_string(choices.size()));
            }
            if (choice < 1 || choice > (int)choices.size())
                throw InvalidInputException("option must be between 1 and " + to_string(choices.size()));
            if (player.getMoney() < choices[choice-1].getPrice()) {
                cout << "You can't afford this option! Choose another.\n";
                continue;
            }
            break;
        } catch (const InvalidInputException& e) {
            cout << e.what() << ". Try again.\n";
        }
    }

    player.applyEffects(choices[choice-1]);
    ChoiceEvent* followUp = choices[choice-1].getFollowUp();
    if (followUp != nullptr)
        followUp->trigger(player);
}