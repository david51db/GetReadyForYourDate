//
// Created by David on 4/19/2026.
//

#ifndef GETREADYFORYOURDATE_PARTNER_H
#define GETREADYFORYOURDATE_PARTNER_H

#include <iostream>
#include <string>
#include <vector>
#include "Trait.h"
class Partner {
    std::string name;
    std::vector<std::string> traitsName;
    std::vector<Trait*> traits;
    std::string secretTrait;

public:
    Partner();
    Partner(std::string name, std::vector<std::string>& traitsName, std::string secretTrait);
    Partner(const Partner& obj);
    Partner& operator=(const Partner& obj);
    ~Partner();

    friend std::ostream& operator<<(std::ostream& os, const Partner& obj);
    friend std::istream& operator>>(std::istream& is, Partner& obj);

    std::string const getName(){return this->name;}
    void showTraits();

    void loadFromFile(std::ifstream &fin);
    void loadTraits(std::vector<Trait*>& traitPool);
    std::vector<Trait*>& getTraits(){return this->traits;}
};



#endif //GETREADYFORYOURDATE_PARTNER_H