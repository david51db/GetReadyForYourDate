//
// Created by David on 4/22/2026.
//

#include <iostream>
#include <limits>

#include "Exceptions.h"
using namespace std;
#include "RPS.h"
#include "MiniGame.h"

RPS::RPS():MiniGame(){};

RPS::RPS(std::string text, int reward):MiniGame(reward, text) {
}

RPS::RPS(const RPS &obj):MiniGame(obj) {
}

RPS &RPS::operator=(const RPS &obj) {

    if (this==&obj) return *this;

    MiniGame::operator=(obj);
    return *this;
}

RPS::~RPS()=default;

ostream& operator<<(ostream& os, const RPS& obj) {
    os<<static_cast<const MiniGame&>(obj);

    return os;
}

istream& operator>>(istream& is, RPS& obj) {
    is>>static_cast<MiniGame&>(obj);

    return is;
}

int RPS::play() {
    cout << "\n=== ROCK PAPER SCISSORS ===\n";
    cout << "Enter r for ROCK, p for PAPER, s for SCISSORS\n";

    int reward=getReward();
    char playerMove;
    while (true) {
        try {
            if (!(cin >> playerMove)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException("move must be r, p or s");
            }
            if (playerMove != 'r' && playerMove != 'p' && playerMove != 's')
                throw InvalidInputException("move must be r, p or s");
            break;
        } catch (const InvalidInputException& e) {
            cout << e.what() << ". Try again.\n";
        }
    }

    int move =rand()% 3;
    char computerMove;
    if (move==0) computerMove = 'p';
    else if (move == 1) computerMove = 's';
    else computerMove = 'r';

    cout << "Your move: " << playerMove << " | Computer: " << computerMove << "\n";

    if (playerMove == computerMove) {
        cout << "Draw! No reward.\n";
        return 0;
    }
    if ((playerMove=='s' && computerMove=='p') ||
        (playerMove=='p' && computerMove=='r') ||
        (playerMove=='r' && computerMove=='s')) {
        cout << "You won! +" << reward << " money.\n";
        return reward;
        }
    cout << "Computer won. No reward.\n";
    return 0;
}

