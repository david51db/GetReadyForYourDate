//
// Created by David on 4/24/2026.
//

#ifndef GETREADYFORYOURDATE_TRAITS_H
#define GETREADYFORYOURDATE_TRAITS_H

#include<iostream>

class Trait {
    std::string name;
    int weightCharm;
    int weightVibe;
    int weightDignity;

public:
    Trait();
    Trait(std::string& name, int weightCharm, int weightVibe, int weightDignity);
    Trait(const Trait& obj);
    ~Trait();

    friend std::ostream& operator<<(std::ostream& os, const Trait& obj);

    std::string const getName(){return this->name;}
    int const getWeightCharm(){return this->weightCharm;}
    int const getWeightVibe(){return this->weightVibe;}
    int const getWeightDignity(){return this->weightDignity;}

    void loadFromFile(std::ifstream& fin);


};

#endif //GETREADYFORYOURDATE_TRAITS_H