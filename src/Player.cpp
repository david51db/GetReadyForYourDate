//
// Created by David on 4/18/2026.
//

#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
    name="N/A";
    charm=0;
    vibe=0;
    dignity=0;
    money=0;
}

Player::Player(string name, int charm, int dignity, int vibe, int money) {
    this->name=name;
    this->dignity=dignity;
    this->charm=charm;
    this->vibe=vibe;
    this->money=money;
}

Player::Player(const Player& obj) {
    this->name=obj.name;
    this->dignity=obj.dignity;
    this->charm=obj.charm;
    this->vibe=obj.vibe;
    this->money=obj.money;
}

Player &Player::operator=(const Player &obj) {
    if (this==&obj) return *this;

    this->name=obj.name;
    this->dignity=obj.dignity;
    this->charm=obj.charm;
    this->vibe=obj.vibe;
    this->money=obj.money;

    return *this;
}

Player::~Player() = default;

ostream& operator<<(ostream& os, const Player& obj) {
    os<<"Name: " << obj.name<< "\n";
    os<<"Charm: " << obj.charm<< "\n";
    os<<"Dignity: " << obj.dignity<< "\n";
    os<<"Vibe: " << obj.vibe<< "\n";
    os<<"Money: " << obj.money<< "\n";

    return os;
}

istream& operator>>(istream& is, Player& obj) {
    cout<<"Name: ";
    is>>obj.name;

    cout<<"Charm: ";
    is>>obj.charm;

    cout<<"Dignity: ";
    is>>obj.dignity;

    cout<<"Vibe: ";
    is>>obj.vibe;

    cout<<"Money: ";
    is>>obj.money;

    return is;
}

void Player::newPlayer() {

    string playerName;
    cin>>playerName;

    this->setName(playerName);

    this->charm=20;
    this->dignity=20;
    this->vibe=20;
    this->money=30;


}

void Player::initialisePlayer() {
    this->charm=20;
    this->dignity=20;
    this->vibe=20;
}

void Player::applyEffects(Choice& choice) {

    this->charm=choice.getCharm()+this->charm;
    this->vibe=choice.getVibe()+this->vibe;
    this->dignity=choice.getDignity()+this->dignity;
    this->money=choice.getMoney()+this->money- choice.getPrice();

    printEffects(choice.getCharm(), choice.getDignity(), choice.getVibe(), choice.getMoney());
}

void Player::applyEffects(int deltaVibe, int deltaCharm, int deltaDignity, int deltaMoney) {
    this->charm=deltaCharm+this->charm;
    this->vibe=deltaVibe+this->vibe;
    this->dignity=deltaDignity+this->dignity;
    this->money=deltaMoney+this->money;


    printEffects(deltaCharm, deltaDignity, deltaVibe, deltaMoney);
}

void Player::modifyMoney(int money) {
    this->money+=money;
}

void Player::printEffects(int dCharm, int dDignity, int dVibe, int dMoney) {
    if (dCharm)   cout << "Charm: "   << (dCharm>0   ? "+" : "") << dCharm   << "  ";
    if (dDignity) cout << "Dignity: " << (dDignity>0 ? "+" : "") << dDignity << "  ";
    if (dVibe)    cout << "Vibe: "    << (dVibe>0    ? "+" : "") << dVibe    << "  ";
    if (dMoney)   cout << "Money: "   << (dMoney>0   ? "+" : "") << dMoney   << "  ";
    cout << "\n\n";
}