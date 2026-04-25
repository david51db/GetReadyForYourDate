//
// Created by David on 4/21/2026.
//

#include "Ad.h"
#include "MiniGame.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
Ad::Ad():MiniGame() {
    duration=0;
}

Ad::Ad(int duration, int reward, string text): MiniGame(reward, text) {
    this->duration=duration;
}

Ad::Ad(const Ad &obj):MiniGame(obj) {
    this->duration=obj.duration;
}

Ad& Ad::operator=(const Ad& obj) {
    if (this==&obj) return *this;

    MiniGame::operator=(obj);

    this->duration=obj.duration;
    return *this;
}

Ad::~Ad() =default;

ostream& operator<<(ostream& os, const Ad& obj) {

    os<<static_cast<const MiniGame&>(obj);

    os<<"Duration: "<<obj.duration;

    return os;
}

istream& operator>>(istream& is, Ad& obj) {

    is>>static_cast<MiniGame&>(obj);


    cout<<"Duration: ";
    is>>obj.duration;


    return is;

}

void Ad::loadFromFile(ifstream &fin) {
    string line;
    string token;

    getline(fin, line);

    while (line.empty()&&!fin.eof())getline(fin, line);

    stringstream ss(line);
    getline(ss, token, '|');
    this->text=token;

    getline(ss, token, '|');
    this->duration=stoi(token);

    getline(ss, token);
    this->reward=stoi(token);
}


int Ad::play() {
    cout << "\n=== WATCHING AD ===\n";
    cout << "Watching a " << duration << " second ad...\n";
    cout<<text;
    cout << "Press Enter to skip.\n";
    cin.ignore();
    cin.get();
    cout << "Ad finished! +" << getReward() << " money.\n";
    return getReward();
}
