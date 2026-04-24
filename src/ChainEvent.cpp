//
// Created by David on 4/21/2026.
//

#include <iostream>
#include "ChainEvent.h"
#include "ChoiceEvent.h"
#include "RandomEvent.h"
using namespace std;
#include <fstream>
#include <sstream>

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


void ChainEvent::loadFromFile(ifstream &fin) {
    string line, token;

    getline(fin, line);

    while (line.empty() && !fin.eof())getline(fin, line);

    stringstream ss1(line);

    getline(ss1, token, '|');
    this->text = token;

    getline(ss1, token, '|');
    this->phase = std::stoi(token);
    getline(ss1, token, '|');
    this->chance = std::stoi(token);

    getline(ss1, token, '|');
    this->avoidStat = token;

    getline(ss1, token);
    this->avoidThreshold = stoi(token);

    getline(fin, line);

    stringstream ss2(line);

    getline(ss2, token, '|');
    this->textResult = token;

    getline(ss2, token);
    this->textAvoided = token;

    getline(fin, line);
    int nrChoices=stoi(line);

    choices.clear();
    for (int i=0;i<nrChoices;i++) {
        getline(fin, line);
        Choice c;
        c.parseFromString(line);
        choices.push_back(c);
    }
    getline(fin, line);
}

void ChainEvent::trigger(Player& player) {
    cout << text << "\n";
    bool avoided = this->checkAvoid(player);
    if (!avoided) {
        cout << textResult << "\n\n";
        player.applyEffects(deltaVibe, deltaCharm, deltaDignity, deltaMoney);
        ChoiceEvent::trigger(player);
    }


}


