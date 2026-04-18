//
// Created by David on 4/18/2026.
//

#ifndef GETREADYFORYOURDATE_PLAYER_H
#define GETREADYFORYOURDATE_PLAYER_H

#include <iostream>
#include <string>

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
};






#endif //GETREADYFORYOURDATE_PLAYER_H