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

#include "Ad.h"
#include "RPS.h"
using namespace std;
#include <fstream>
#include "Trait.h"
#include <limits>
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


    for (auto pp: obj.partnerPool) {
        os<<*pp<<"\n";
    }

    for (auto t: obj.traitPool) {
        os<<*t<<"\n";
    }
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

    ifstream finTraits("data/traits.txt");
    if (!finTraits.is_open())cout<<"could not open fintraits";

    if (finTraits.is_open()) {
        while (finTraits.peek()!=EOF) {
            finTraits>>ws;
            if (finTraits.eof()) break;

            Trait* t=new Trait();
            t->loadFromFile(finTraits);
            traitPool.push_back(t);
        }
    }

    ifstream finPartners("data/partners.txt");
    if (!finPartners.is_open())cout<<"could not open finpartners";

    if (finPartners.is_open()) {
        while (finPartners.peek()!=EOF) {
            finPartners>>ws;
            if (finPartners.eof()) break;

            Partner* p=new Partner();
            p->loadFromFile(finPartners);
            p->loadTraits(traitPool);
            partnerPool.push_back(p);
        }
    }

    ifstream finAds("data/ads.txt");
    if (!finAds.is_open())cout<<"could not open finads";

    if (finAds.is_open()) {
        while (finAds.peek()!=EOF) {
            finAds>>ws;
            if (finAds.eof()) break;

            Ad* a=new Ad();
            a->loadFromFile(finAds);
            adPool.push_back(a);
        }
    }

}

void Game::connectFollowUps() {

    for (Event* e: eventPool) {
        ChoiceEvent* ce=dynamic_cast<ChoiceEvent*>(e);
        if (ce!=nullptr) {
            for (Choice& c: ce->getChoices()) {
                int id=c.getFollowUpId();

                if (id>=101&&(id-101)<(int)secretFollowUps.size())c.setFollowUpPointer(secretFollowUps[id-101]);
            }
        }
    }

    for (RandomEvent* r : randomPool) {
        ChainEvent* che = dynamic_cast<ChainEvent*>(r);
        if (che != nullptr) {
            for (Choice& c : che->getChoices()) {
                int id = c.getFollowUpId();
                if (id >= 101 && (id-101) < (int)secretFollowUps.size()) {
                    c.setFollowUpPointer(secretFollowUps[id-101]);
                }
            }
        }
    }


}

void Game::initialise() {

    player->newPlayer();

}


void Game::run() {


    cout<<"Welcome!\n";
    cout<<"What is your name?\n";

    this->initialise();

    int choice;
    do {

        cout<<"\n";
        cout << "\n===== GET READY FOR YOUR DATE =====\n";
        cout << "1. Start new game\n";
        cout << "2. Load game\n";
        cout << "3. View stats\n";
        cout << "0. Exit\n\n";
        cout << "Choice:\n";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: this->startNewGame(); break;
            case 2: break;
            case 3: cout<<*player; break;

        }
    }while (choice!=0);
}

void Game::startNewGame() {

    player->initialisePlayer();
    this->selectPartner();
    this->drawEvents();
    this->playEvents();
    this->playEnding();


}

void Game::selectPartner() {
    cout<<"Please choose your partner by typing its corresponding number.\n";

    int indexPartner1 = rand() % partnerPool.size();
    int indexPartner2=rand() % partnerPool.size();
    int indexPartner3=rand() % partnerPool.size();

    while (indexPartner1==indexPartner2)indexPartner2=rand() % partnerPool.size();
    while (indexPartner3==indexPartner1 || indexPartner3==indexPartner2)indexPartner3=rand() % partnerPool.size();


    cout<<"1. "<<partnerPool[indexPartner1]->getName()<<": ";
    partnerPool[indexPartner1]->showTraits();
    cout<<".\n";

    cout<<"2. "<<partnerPool[indexPartner2]->getName()<<": ";
    partnerPool[indexPartner2]->showTraits();
    cout<<".\n";

    cout<<"3. "<<partnerPool[indexPartner3]->getName()<<": ";
    partnerPool[indexPartner3]->showTraits();
    cout<<".\n";

    int choice;
    cin>>choice;

    switch(choice){
        case 1: *this->partner= *(partnerPool[indexPartner1]); break;
        case 2: *this->partner=*(partnerPool[indexPartner2]); break;
        case 3: *this->partner=*(partnerPool[indexPartner3]); break;
    }
}

void Game::drawEvents() {
    events.clear();

    vector<bool> drawnChoiceEvents(eventPool.size(), false);
    vector<bool> drawnRandomEvents(randomPool.size(),false);



    for (int i=0;i<3;i++) {
        int randomIdx;
        do {
            randomIdx=rand()%eventPool.size();
        }while (drawnChoiceEvents[randomIdx] || eventPool[randomIdx]->getPhase()==true);

        drawnChoiceEvents[randomIdx]=true;
        events.push_back(eventPool[randomIdx]);//trb new?
    }



    for (int i=3;i<10;i++) {
        int randomIdx;
        do {
            randomIdx=rand()%eventPool.size();
        }while (drawnChoiceEvents[randomIdx] || eventPool[randomIdx]->getPhase()==false);

        drawnChoiceEvents[randomIdx]=true;
        events.push_back(eventPool[randomIdx]);
    }



    for (int i=0;i<3;i++) {
        int randomIdx;
        int attempts=0;
        do {
            randomIdx=rand()%randomPool.size();
            attempts++;
            if (attempts > 100) break;
        }while (drawnRandomEvents[randomIdx] || randomPool[randomIdx]->getPhase()==true);
        if (attempts > 100) continue;
        if (randomPool[randomIdx]->getChance() > rand()%100) {
            drawnRandomEvents[randomIdx]=true;
            events.insert(events.begin()+rand()%4,randomPool[randomIdx]);
        }
    }



    for (int i=3;i<10;i++) {
        int randomIdx;
        int attempts=0;
        do {
            randomIdx=rand()%randomPool.size();
            attempts++;
            if (attempts > 100) break;
        }while (drawnRandomEvents[randomIdx] || randomPool[randomIdx]->getPhase()==false);
        if (attempts > 100) continue;
        if (randomPool[randomIdx]->getChance() > rand()%100) {
            drawnRandomEvents[randomIdx]=true;
            events.insert(events.begin()+rand()%7+4,randomPool[randomIdx]);
        }
    }


}

void Game::playEvents() {


    RPS rps("Rock Paper Scissors", 40);

    for (Event* e: events) {
        ChoiceEvent* ce = dynamic_cast<ChoiceEvent*>(e);
        if (ce != nullptr) {
            int cantAfford = 0;
            for (Choice& c : ce->getChoices())
                if (player->getMoney() < c.getPrice()) cantAfford++;

            if (cantAfford >= 2) {
                cout << "You can't afford most options. Play a minigame?\n";
                cout << "1. Ad\n2. RPS\n0. Skip\n";
                int mg; cin >> mg;
                if (mg == 1) player->modifyMoney(selectAd()->play());
                else if (mg == 2) player->modifyMoney(rps.play());
            }
        }

        e->trigger(*this->player);
        if (player->getCharm()<-500 || player->getVibe()<-500 ||
            player->getDignity()<-500 || player->getMoney()<-500) break;
    }
}

void Game::playEnding() {

    if (player->getCharm()<-500 || player->getDignity()<-500 ||player->getVibe()<-500) {
        cout<<"Game over. You literally died.";
        return;
    }

    float endingScore=this->calculateEndingScore();


    cout << "\n=== DATE RESULTS ===\n";
    cout << *player;
    cout << "Final score: " << endingScore << "\n\n";


    if (endingScore<0) {
        cout<<"They called an Uber before dessert...\nTerrible ending.\n";
        player->applyEffects(0,0,0,-50);
    }
    else if (endingScore>0 && endingScore<200) {
        cout<<"You thought the date was decent but after that they ghosted you.\nBad ending.\n";
        player->applyEffects(0,0,0,-20);
    }
    else if (endingScore>200 && endingScore<900) {
        cout<<"The date went great! You really hit it off!\nGood ending.\n";
        player->applyEffects(0,0,0,30);
    }
    else if (endingScore>900){
        cout<<"You decided to take a walk after dinner and stayed for 3 more hours. You have a special connection.\nBest ending.\n";
        player->applyEffects(0,0,0,90);
    }
}

float Game::calculateEndingScore() {
    int totalWeightCharm = 0;
    int totalWeightDignity = 0;
    int totalWeightVibe = 0;

    for (Trait* t : partner->getTraits()) {
        totalWeightCharm += t->getWeightCharm();
        totalWeightDignity += t->getWeightDignity();
        totalWeightVibe += t->getWeightVibe();
    }

    float score = player->getCharm() * totalWeightCharm
                + player->getDignity() * totalWeightDignity
                + player->getVibe() * totalWeightVibe;

    return score;
}

Ad* Game::selectAd() {

    return adPool[rand()%adPool.size()];

}
