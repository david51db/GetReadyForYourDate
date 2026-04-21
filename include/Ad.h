//
// Created by David on 4/21/2026.
//

#ifndef GETREADYFORYOURDATE_AD_H
#define GETREADYFORYOURDATE_AD_H


#include "MiniGame.h"
#include <iostream>
#include <string>

class Ad: virtual public MiniGame {
    int duration;

public:
    Ad();
    Ad(int duration, int reward, std::string text);
    Ad(const Ad& obj);
    Ad& operator=(const Ad& obj);
    ~Ad() override;

    friend std::ostream& operator<<(std::ostream& os, const Ad& obj);
    friend std::istream& operator>>(std::istream& is, Ad& obj);
};



#endif //GETREADYFORYOURDATE_AD_H