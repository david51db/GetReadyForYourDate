//
// Created by David on 4/22/2026.
//

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
#include "Game.h"
using namespace std;
#include <fstream>

Game::Game() {
    this->player= new Player();
    this->partner= new Partner();
    //vector - empty
    //vector - empty
    this->running= false;
    this->eventIndex=0;
}

Game::Game(Player *player, Partner *partner,std::vector<Partner*> partnerPool, std::vector<Event *> events,std::vector<ChoiceEvent*> eventPool, std::vector<RandomEvent *> randomPool, bool running, int eventIndex) {
    this->player = new Player(*player);
    this->partner = new Partner(*partner);
    this->partnerPool=partnerPool;
    this->events=events;
    this->eventPool=eventPool;
    this->randomPool=randomPool;
    this->secretFollowUps=secretFollowUps;
    this->running=running;
    this->eventIndex=eventIndex;

}

Game::Game(const Game &obj) {
    this->player= new Player(*obj.player);
    this->partner= new Partner(*obj.partner);

    // for (auto e : obj.eventPool) {
    //     if (auto chainPtr = dynamic_cast<ChainEvent*>(e)) {
    //         eventPool.push_back(new ChainEvent(*chainPtr));
    //     } else if (auto choicePtr = dynamic_cast<ChoiceEvent*>(e)) {
    //         eventPool.push_back(new ChoiceEvent(*choicePtr));
    //     } else if (auto randomPtr = dynamic_cast<RandomEvent*>(e)) {
    //         eventPool.push_back(new RandomEvent(*randomPtr));
    //     }
    // }
//whatever partner pool
    for (auto r : obj.randomPool) {
        if (auto chainPtr = dynamic_cast<ChainEvent*>(r)) {
            randomPool.push_back(new ChainEvent(*chainPtr));
        } else {
            randomPool.push_back(new RandomEvent(*r));
        }
    }
    //whatever secret followups
    this->running=obj.running;
    this->eventIndex=obj.eventIndex;
}

Game &Game::operator=(const Game &obj) {
    if (this==&obj) return *this;

    delete player;
    delete partner;


    for(auto e : eventPool) delete e;
    for(auto r : randomPool) delete r;
    for(auto f : secretFollowUps) delete f;
    for(auto p : partnerPool) delete p;

    eventPool.clear();
    randomPool.clear();
    secretFollowUps.clear();
    partnerPool.clear();

    this->player= new Player(*obj.player);
    this->partner= new Partner(*obj.partner);

    // for (auto e : obj.eventPool) {
    //     if (auto chainPtr = dynamic_cast<ChainEvent*>(e)) {
    //         eventPool.push_back(new ChainEvent(*chainPtr));
    //     } else if (auto choicePtr = dynamic_cast<ChoiceEvent*>(e)) {
    //         eventPool.push_back(new ChoiceEvent(*choicePtr));
    //     } else if (auto randomPtr = dynamic_cast<RandomEvent*>(e)) {
    //         eventPool.push_back(new RandomEvent(*randomPtr));
    //     }
    // }

    for (auto r : obj.randomPool) {
        if (auto chainPtr = dynamic_cast<ChainEvent*>(r)) {
            randomPool.push_back(new ChainEvent(*chainPtr));
        } else {
            randomPool.push_back(new RandomEvent(*r));
        }
    }

    for (auto s : obj.secretFollowUps) {
        secretFollowUps.push_back(new ChoiceEvent(*s));
    }

    this->running=obj.running;
    this->eventIndex=obj.eventIndex;

    return *this;
}

Game::~Game() {
    delete player;
    delete partner;
    for(auto e : eventPool) delete e;
    for(auto r : randomPool) delete r;
    for(auto s : secretFollowUps) delete s;
    for (auto p: partnerPool) delete p;
    partnerPool.clear();
    eventPool.clear();
    randomPool.clear();
    secretFollowUps.clear();
}

ostream& operator<<(ostream& os, const Game& obj) {
    os<<"Player: \n"<<*obj.player<<"\n";
    os<<"Partner: \n"<<*obj.partner<<"\n";
    os<<"Events: \n";

    for (auto e: obj.eventPool) {
        os<<*e<<"\n";
    }

    os<<"Random Pool: \n";

    for (auto r: obj.randomPool) {
        os<<*r<<"\n";
    }

    os<<"Running: "<<obj.running<<"\n";
    os<<"Event Index: "<<obj.eventIndex<<"\n";

    return os;
}


istream& operator>>(istream& is, Game& obj) {

    cout<<"Player: \n";
    is>>*obj.player;

    cout<<"Partner: \n";
    is>>*obj.partner;


    int nrEvents;
    int nrRandomPool;

    cout<<"Number of Events: \n";
    is>>nrEvents;

    for (int i=0;i<nrEvents;i++) {
        ChoiceEvent* e = new ChoiceEvent();
        is >> *e;
        obj.eventPool.push_back(e);
    }

    cout<<"Number of Random Pool Events: \n";
    is>>nrRandomPool;

    for (int i=0;i<nrRandomPool;i++) {
        RandomEvent* r= new RandomEvent();
        is>>*r;
        obj.randomPool.push_back(r);
    }

    cout<<"Running: ";
    is>>obj.running;

    cout<<"Event Index: ";
    is>>obj.eventIndex;

    return is;
}

void Game::loadAllEvents() {
    ifstream finChoice("data/choiceEvents.txt");

    if (!finChoice.is_open())cout<<"could not open finchoice";

    if (finChoice.is_open()) {
        while (finChoice.peek()!=EOF) {
            finChoice>>ws;
            if (finChoice.eof()) break;

            ChoiceEvent* ce=new ChoiceEvent();
            ce->loadFromFile(finChoice);
            eventPool.push_back(ce);
        }
    }
    finChoice.close();

    ifstream finRandom("data/randomEvents.txt");
    if (!finRandom.is_open())cout<<"could not open finrandom";

    if (finRandom.is_open()) {
        while (finRandom.peek()!=EOF) {
            finRandom>>ws;
            if (finRandom.eof()) break;

            RandomEvent* re=new RandomEvent();
            re->loadFromFile(finRandom);
            randomPool.push_back(re);
        }
    }
    finRandom.close();

    ifstream finChain("data/chainEvents.txt");
    if (!finChain.is_open())cout<<"could not open finchain";

    if (finChain.is_open()) {
        while (finChain.peek()!=EOF) {
            finChain>>ws;
            if (finChain.eof()) break;

            ChainEvent* che=new ChainEvent();
            che->loadFromFile(finChain);
            randomPool.push_back(che);
        }
    }
    finChain.close();

    ifstream finFollow("data/followUpEvents.txt");

    if (!finFollow.is_open())cout<<"could not open finfollow";

    if (finFollow.is_open()) {
        while (finFollow.peek()!=EOF) {
            finFollow>>ws;
            if (finFollow.eof()) break;

            ChoiceEvent* fe=new ChoiceEvent();
            fe->loadFromFile(finFollow);
            secretFollowUps.push_back(fe);
        }
    }
    finFollow.close();
}

void Game::connectFollowUps() {

    for (Event* e: eventPool) {
        ChoiceEvent* ce=dynamic_cast<ChoiceEvent*>(e);
        if (ce!=nullptr) {
            for (Choice& c: ce->getChoices()) {
                int id=c.getFollowUpId();

                if (id>=0&&id<(int)secretFollowUps.size())c.setFollowUpPointer(secretFollowUps[id]);
            }
        }
    }

    for (RandomEvent* r : randomPool) {
        ChainEvent* che = dynamic_cast<ChainEvent*>(r);
        if (che != nullptr) {
            for (Choice& c : che->getChoices()) {
                int id = c.getFollowUpId();
                if (id >= 0 && id < (int)secretFollowUps.size()) {
                    c.setFollowUpPointer(secretFollowUps[id]);
                }
            }
        }
    }


}

void Game::initialise() {

    player->initialisePlayer();

}


void Game::run() {


    cout<<"Welcome!\n\n";
    cout<<"What is your name?";

    this->initialise();

    int choice;
    do {

        cout<<"\n\n";
        cout << "\n===== GET READY FOR YOUR DATE =====\n";
        cout << "1. Start new game\n";
        cout << "2. Load game\n";
        cout << "3. View stats\n";
        cout << "0. Exit\n\n";
        cout << "Choice:\n";
        cin >> choice;

        switch (choice) {
            case 1: this->startNewGame();
            case 2: ;
            case 3: cout<<*player;

        }
    }while (choice!=0);
}

void Game::startNewGame() {


}
