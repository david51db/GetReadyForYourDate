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
    std::vector<ChoiceEvent*> eventPool;
    std::vector<RandomEvent*> randomPool;
    std::vector<Partner*> partnerPool;
    bool running;
    int eventIndex;
    std::vector<ChoiceEvent*> secretFollowUps;

public:
    Game();
    Game(Player* player, Partner* partner,std::vector<Partner*> partnerPool, std::vector<Event*> events, std::vector<ChoiceEvent*> eventPool,std::vector<RandomEvent*> randomPool, bool running, int eventIndex);
    Game(const Game& obj);
    Game& operator=(const Game& obj);
    ~Game();

    friend std::ostream& operator<<(std::ostream& os, const Game& obj);
    friend std::istream& operator>>(std::istream& is, Game& obj);

    std::vector<ChoiceEvent*>&  getEvents(){return this->eventPool;}
    std::vector<ChoiceEvent*>& getFollowUps() { return secretFollowUps; }

    void loadAllEvents ();
    void connectFollowUps();
    void run();
    void initialise();
    void startNewGame();


};


#endif //GETREADYFORYOURDATE_GAME_H