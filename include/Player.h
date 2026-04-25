//
// Created by David on 4/18/2026.
//

#ifndef GETREADYFORYOURDATE_PLAYER_H
#define GETREADYFORYOURDATE_PLAYER_H

#include <iostream>
#include <string>

#include "Choice.h"

class Player {
    std::string name;
    int charm;
    int dignity;
    int vibe;
    int money;

public:
    Player();
    Player(std::string name, int charm, int dignity, int vibe, int money);
    Player(const Player& obj);
    Player& operator=(const Player& obj);
    ~Player();

    friend std::ostream& operator<<(std::ostream& os, const Player& obj);
    friend std::istream& operator>>(std::istream& is, Player& obj);

    void setName(std::string name){this->name=name;}
    int getDignity(){return this->dignity;}
    int getVibe(){return this->vibe;}
    int getCharm(){return this->charm;}
    int getMoney(){return this->money;}
    void modifyMoney(int);
    void initialisePlayer();
    void newPlayer();
    void applyEffects(Choice& choice);
    void applyEffects(int, int, int, int);
    void printEffects(int deltaCharm, int deltaDignity, int deltaVibe, int deltaMoney);
};






#endif //GETREADYFORYOURDATE_PLAYER_H