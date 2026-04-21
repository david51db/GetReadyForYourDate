//
// Created by David on 4/21/2026.
//

#include "Ad.h"
#include "MiniGame.h"
#include <iostream>
using namespace std;

Ad::Ad():MiniGame() {
    duration=0;
}

Ad::Ad(int duration, int reward, string text): MiniGame(reward, text) {
    this->duration=duration;
}

Ad::Ad(const Ad &obj):MiniGame(obj) {
    this->duration=duration;
}

Ad& Ad::operator=(const Ad& obj) {
    if (this==&obj) return *this;

    MiniGame::operator=(obj);

    this->duration=duration;
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
