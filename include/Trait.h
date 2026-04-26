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
    friend std::istream& operator>>(std::istream& is, Trait& obj);

    const std::string& getName() const {return this->name;}
    int const getWeightCharm() const {return this->weightCharm;}
    int const getWeightVibe() const {return this->weightVibe;}
    int const getWeightDignity() const {return this->weightDignity;}

    void loadFromFile(std::ifstream& fin);


};

#endif //GETREADYFORYOURDATE_TRAITS_H