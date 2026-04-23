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
    avoidStat="N/A";
    avoidThreshold=0;
    textAvoided="N/A";
    textResult="N/A";
}

RandomEvent::RandomEvent(int chance, string avoidStat, int avoidThreshold, string textAvoided, string textResult,
    string text, bool phase) : Event(text, phase){

    this->chance=chance;
    this->avoidStat=avoidStat;
    this->avoidThreshold=avoidThreshold;
    this->textAvoided=textAvoided;
    this->textResult=textResult;
}

RandomEvent:: RandomEvent(const RandomEvent& obj): Event(obj) {
    this->chance=obj.chance;
    this->avoidStat=obj.avoidStat;
    this->avoidThreshold=obj.avoidThreshold;
    this->textAvoided=obj.textAvoided;
    this->textResult=obj.textResult;
}

RandomEvent& RandomEvent::operator=(const RandomEvent& obj) {
    if (this==&obj)return *this;


    Event::operator=(obj);
    this->chance=obj.chance;
    this->avoidStat=obj.avoidStat;
    this->avoidThreshold=obj.avoidThreshold;
    this->textAvoided=obj.textAvoided;
    this->textResult=obj.textResult;

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
    getline(ss, token);

    this->avoidThreshold=stoi(token);
    getline(ss, token);

    getline(fin, line);
    this->textResult=line;

    getline(fin, line);
    this->textAvoided=line;

    getline(fin, line);


}

