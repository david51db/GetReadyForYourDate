//
// Created by David on 4/22/2026.
//

#include <iostream>
using namespace std;
#include "RPS.h"
#include "MiniGame.h"

RPS::RPS():MiniGame(){};

RPS::RPS(std::string text, int reward):MiniGame(reward, text) {
}

RPS::RPS(const RPS &obj):MiniGame(obj) {
}

RPS &RPS::operator=(const RPS &obj) {

    if (this==&obj) return *this;

    MiniGame::operator=(obj);
    return *this;
}

RPS::~RPS()=default;

ostream& operator<<(ostream& os, const RPS& obj) {
    os<<static_cast<const MiniGame&>(obj);

    return os;
}

istream& operator>>(istream& is, RPS& obj) {
    is>>static_cast<MiniGame&>(obj);

    return is;
}



