//
// Created by David on 4/22/2026.
//

#ifndef GETREADYFORYOURDATE_RPS_H
#define GETREADYFORYOURDATE_RPS_H

#include "MiniGame.h"
#include <iostream>

class RPS: public MiniGame {
public:
    RPS();
    RPS(std::string text, int reward);
    RPS(const RPS& obj);
    RPS& operator=(const RPS& obj);
    ~RPS() override;

    friend std::ostream& operator<<(std::ostream& os, const RPS& obj);
    friend std::istream& operator>>(std::istream& is, RPS& obj);


    int play() override;

};


#endif //GETREADYFORYOURDATE_RPS_H