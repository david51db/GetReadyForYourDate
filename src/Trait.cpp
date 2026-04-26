//
// Created by David on 4/24/2026.
//
#include "Trait.h"

#include <map>
using namespace std;
#include<fstream>
#include<sstream>

Trait::Trait() {
    name="N/A";
    weightCharm=0;
    weightDignity=0;
    weightVibe=0;
}

Trait::Trait(std::string& name, int weightCharm, int weightVibe, int weightDignity) {
    this->name=name;
    this->weightCharm=weightCharm;
    this->weightDignity=weightDignity;
    this->weightVibe=weightVibe;
}

Trait::Trait(const Trait &obj) {
    this->name=obj.name;
    this->weightCharm=obj.weightCharm;
    this->weightDignity=obj.weightDignity;
    this->weightVibe=obj.weightVibe;
}

std::ostream &operator<<(std::ostream &os, const Trait &obj) {
    cout<<"Name: "<<obj.name<<"\n";
    cout<<"Weight Charm: "<<obj.weightCharm<<"\n";
    cout<<"Weight Vibe: "<<obj.weightVibe<<"\n";
    cout<<"Weight Dignity: "<<obj.weightDignity<<"\n";

    return os;
}

istream& operator>>(istream& is, Trait& obj) {
    cout << "Name: "; is >> obj.name;
    cout << "Weight Charm: "; is >> obj.weightCharm;
    cout << "Weight Vibe: "; is >> obj.weightVibe;
    cout << "Weight Dignity: "; is >> obj.weightDignity;
    return is;
}

Trait::~Trait()=default;

void Trait::loadFromFile(std::ifstream& fin) {
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        string name, charm, vibe, dignity;
        stringstream ss(line);

        getline(ss, name, '|');
        getline(ss, charm, '|');
        getline(ss, vibe, '|');
        getline(ss, dignity, '|');

        this->name = name;
        this->weightCharm = stoi(charm);
        this->weightVibe = stoi(vibe);
        this->weightDignity = stoi(dignity);

        break;
    }
}


