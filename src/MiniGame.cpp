//
// Created by David on 4/21/2026.
//

#include <iostream>
#include "MiniGame.h"
using namespace std;

MiniGame::MiniGame() {
    this->reward=0;
}

MiniGame::MiniGame(int reward) {
    this->reward=reward;
}

MiniGame::MiniGame(const MiniGame &obj) {
    this->reward=obj.reward;
}

MiniGame &MiniGame::operator=(const MiniGame &obj) {
    if (this==&obj) return *this;

    this->reward=obj.reward;
    return *this;
}

MiniGame::~MiniGame() =default;

ostream& operator<<(ostream& os, const MiniGame& obj) {

    os<<"Reward: \n"<<obj.reward;

    return os;
}

istream& operator>>(istream& is, MiniGame& obj) {

    cout<<"Reward: ";
    is>>obj.reward;

    return is;
}
