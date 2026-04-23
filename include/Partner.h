//
// Created by David on 4/19/2026.
//

#ifndef GETREADYFORYOURDATE_PARTNER_H
#define GETREADYFORYOURDATE_PARTNER_H

#include <iostream>
#include <string>
#include <vector>

class Partner {
    std::string name;
    std::vector<std::string> traits;
    std::string secretTrait;

public:
    Partner();
    Partner(std::string name, std::vector<std::string>& traits, std::string secretTrait);
    Partner(const Partner& obj);
    Partner& operator=(const Partner& obj);
    ~Partner();

    friend std::ostream& operator<<(std::ostream& os, const Partner& obj);
    friend std::istream& operator>>(std::istream& is, Partner& obj);

    void loadFromFile(std::ifstream &fin);
};



#endif //GETREADYFORYOURDATE_PARTNER_H