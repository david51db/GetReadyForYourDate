//
// Created by David on 4/22/2026.
//

#ifndef GETREADYFORYOURDATE_GAME_H
#define GETREADYFORYOURDATE_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "Partner.h"
#include "Player.h"
#include "Event.h"
#include "Choice.h"
#include "ChainEvent.h"
#include "ChoiceEvent.h"
#include "RandomEvent.h"



class Game {
    Player* player;
    Partner* partner;
    std::vector<Event*> events;
    std::vector<RandomEvent*> randomPool;
    bool running;
    int eventIndex;

public:
    Game();
    Game(Player* player, Partner* partner, std::vector<Event*> events, std::vector<RandomEvent*> randomPool, bool running, int eventIndex);
    Game(const Game& obj);
    Game& operator=(const Game& obj);
    ~Game();

    friend std::ostream& operator<<(std::ostream& os, const Game& obj);
    friend std::istream& operator>>(std::istream& is, Game& obj);

};


#endif //GETREADYFORYOURDATE_GAME_H