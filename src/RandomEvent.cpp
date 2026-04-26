//
// Created by David on 4/19/2026.
//

#include <iostream>
#include "RandomEvent.h"
#include <vector>
#include <string>
using namespace std;
#include <fstream>
#include <sstream>

RandomEvent::RandomEvent() : Event(){
    chance=0;
    avoidStat="";
    avoidThreshold=0;
    textAvoided="N/A";
    textResult="N/A";
    deltaCharm=0;
    deltaDignity=0;
    deltaMoney=0;
    deltaVibe=0;
}

RandomEvent::RandomEvent(int deltaCharm, int deltaDignity, int deltaVibe, int deltaMoney, int chance, string& avoidStat, int avoidThreshold, string& textAvoided, string& textResult,
    string& text, bool phase) : Event(text, phase){

    this->chance=chance;
    this->avoidStat=avoidStat;
    this->avoidThreshold=avoidThreshold;
    this->textAvoided=textAvoided;
    this->textResult=textResult;
    this->deltaCharm = deltaCharm;
    this->deltaDignity = deltaDignity;
    this->deltaVibe = deltaVibe;
    this->deltaMoney = deltaMoney;
}

RandomEvent:: RandomEvent(const RandomEvent& obj): Event(obj) {
    this->chance=obj.chance;
    this->avoidStat=obj.avoidStat;
    this->avoidThreshold=obj.avoidThreshold;
    this->textAvoided=obj.textAvoided;
    this->textResult=obj.textResult;
    this->deltaCharm = obj.deltaCharm;
    this->deltaDignity = obj.deltaDignity;
    this->deltaVibe = obj.deltaVibe;
    this->deltaMoney = obj.deltaMoney;
}

RandomEvent& RandomEvent::operator=(const RandomEvent& obj) {
    if (this==&obj)return *this;


    Event::operator=(obj);
    this->chance=obj.chance;
    this->avoidStat=obj.avoidStat;
    this->avoidThreshold=obj.avoidThreshold;
    this->textAvoided=obj.textAvoided;
    this->textResult=obj.textResult;
    this->deltaCharm = obj.deltaCharm;
    this->deltaDignity = obj.deltaDignity;
    this->deltaVibe = obj.deltaVibe;
    this->deltaMoney = obj.deltaMoney;

    return *this;
}

RandomEvent::~RandomEvent()=default;

ostream& operator<<(ostream& os, const RandomEvent& obj) {

    os<< static_cast<const Event &>(obj);

    os<<"Chance: "<<obj.chance<<"\n";
    if (obj.avoidStat!="") {
        os<<"Avoid stat: "<<obj.avoidStat<<"\n";
        os<<"Avoid Threshold: "<<obj.avoidThreshold<<"\n";
        os<<"Text for avoided: "<<obj.textAvoided<<"\n";
    }
    os<<"Text for result: "<<obj.textResult<<"\n";

    return os;
}

istream& operator>>(istream& is, RandomEvent& obj) {

    is>>static_cast< Event&>(obj);

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

    return is;

}

void RandomEvent::loadFromFile(ifstream &fin) {
    string line;
    string token;

    getline(fin , line);

    while (line.empty()&&!fin.eof())getline(fin, line);

    stringstream ss(line);
    getline(ss, token, '|');

    this->text=token;
    getline(ss, token, '|');

    this->phase=stoi(token);
    getline(ss, token, '|');

    this->chance=stoi(token);
    getline(ss, token, '|');

    this->avoidStat=token;
    getline(ss, token, '|');

    this->avoidThreshold=stoi(token);
    getline(fin, line);
    stringstream ss2(line);

    getline(ss2, token, '|');
    this->textResult=token;

    getline(ss2, token, '|');
    this->deltaCharm=stoi(token);

    getline(ss2, token, '|');
    this->deltaDignity=stoi(token);

    getline(ss2, token, '|');
    this->deltaVibe=stoi(token);

    getline(ss2, token);
    this->deltaMoney=stoi(token);

    getline(fin, line);
    this->textAvoided=line;

    getline(fin, line);


}

void RandomEvent::trigger(Player &player) {
    cout << "\n" << string(50, '-') << "\n\n";
    cout<<text;

    if (this->avoidStat=="") {
        player.applyEffects(deltaVibe, deltaCharm, deltaDignity, deltaMoney);
        cout<<textResult<<"\n\n";
    }
    else {
        if (avoidStat=="dignity") {
            if (player.getDignity()>=avoidThreshold) {
                cout<<textAvoided<<"\n\n";

            }
            else{ cout<<textResult<<"\n\n";
                player.applyEffects(deltaVibe, deltaCharm, deltaDignity, deltaMoney);
            }
        }
        else if (avoidStat=="charm") {
            if (player.getCharm()>=avoidThreshold){cout<<textAvoided<<"\n\n";}
            else {
                cout<<textResult<<"\n\n";
                player.applyEffects(deltaVibe, deltaCharm, deltaDignity, deltaMoney);
            }
        }
        else if (avoidStat=="vibe") {
            if (player.getVibe()>=avoidThreshold) {
                cout<<textAvoided<<"\n\n";
            }
            else {
                cout<<textResult<<"\n\n";
                player.applyEffects(deltaVibe, deltaCharm, deltaDignity, deltaMoney);
            }
        }
    }
}

bool RandomEvent::checkAvoid(Player& player) const{
    if (avoidStat == "") return false;

    if (avoidStat == "dignity") return player.getDignity() >= avoidThreshold;
    if (avoidStat == "charm") return player.getCharm() >= avoidThreshold;
    if (avoidStat == "vibe") return player.getVibe() >= avoidThreshold;

    return false;
}