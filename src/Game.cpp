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

Game::Game() {
    this->player= new Player();
    this->partner= new Partner();
    //vector - empty
    //vector - empty
    this->running= false;
    this->eventIndex=0;
}

Game::Game(Player *player, Partner *partner, std::vector<Event *> events, std::vector<RandomEvent *> randomPool, bool running, int eventIndex) {
    this->player= player; //merge...?
    this->partner=partner;
    this->events=events;
    this->randomPool=randomPool;
    this->running=running;
    this->eventIndex=eventIndex;

}

Game::Game(const Game &obj) {
    this->player= new Player(*obj.player);
    this->partner= new Partner(*obj.partner);
    this->events= obj.events;
    this->randomPool=obj.randomPool;
    this->running=obj.running;
    this->eventIndex=obj.eventIndex;
}

Game &Game::operator=(const Game &obj) {
    if (this==&obj) return *this;

    delete player;
    delete partner;

    this->player= new Player(*obj.player);
    this->partner= new Partner(*obj.partner);
    this->events= obj.events;
    this->randomPool=obj.randomPool;
    this->running=obj.running;
    this->eventIndex=obj.eventIndex;

    return *this;
}

Game::~Game() {
    delete player;
    delete partner;
}

ostream& operator<<(ostream& os, const Game& obj) {
    os<<"Player: \n"<<*obj.player<<"\n";
    os<<"Partner: \n"<<*obj.partner<<"\n";
    os<<"Events: \n";

    for (auto e: obj.events) {
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
        obj.events.push_back(e);
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