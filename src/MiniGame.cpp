//
// Created by David on 4/21/2026.
//

#include <iostream>
#include "MiniGame.h"
using namespace std;

MiniGame::MiniGame() {
    this->reward=0;
    this->text="N/A";
}

MiniGame::MiniGame(int reward, string text) {
    this->reward=reward;
    this->text=text;
}

MiniGame::MiniGame(const MiniGame &obj) {
    this->reward=obj.reward;
    this->text=obj.text;
}

MiniGame &MiniGame::operator=(const MiniGame &obj) {
    if (this==&obj) return *this;

    this->reward=obj.reward;
    this->text=obj.text;
    return *this;
}

MiniGame::~MiniGame() =default;

ostream& operator<<(ostream& os, const MiniGame& obj) {

    os<<"Reward: \n"<<obj.reward;
    os<<"Text: \n"<<obj.text;

    return os;
}

istream& operator>>(istream& is, MiniGame& obj) {

    cout<<"Reward: ";
    is>>obj.reward;

    cout<<"Text: ";
    is>>obj.text;

    return is;
}
