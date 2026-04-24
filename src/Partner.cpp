//
// Created by David on 4/19/2026.
//

#include "Partner.h"

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#include <sstream>
#include <fstream>
#include "Trait.h"
Partner::Partner() {
    name="N/A";
    traitsName.push_back("N/A");
    secretTrait="N/A";
}

Partner::Partner(string name, vector<string>& traitsName, string secretTrait) {
    this->name=name;
    this->traitsName=traitsName;
    this->secretTrait=secretTrait;
}

Partner::Partner(const Partner &obj) {
    this->name=obj.name;
    this->traitsName=obj.traitsName;
    this->secretTrait=obj.secretTrait;
}

Partner& Partner::operator=(const Partner &obj) {
    if (this==&obj) return *this;

    this->name=obj.name;
    this->traitsName=obj.traitsName;
    this->secretTrait=obj.secretTrait;

    return *this;
}

Partner::~Partner() = default;

ostream& operator<<(ostream &os, const Partner &obj) {
    os<<"Name: " << obj.name<< "\n";

    os<<"Traits: " ;
    for (const string& trait: obj.traitsName) os<<trait<<" ";
    os<<"\n";

    os<<"Secret Trait: "<<obj.secretTrait<<"\n";

    return os;
}

istream& operator>>(istream &is, Partner& obj) {

    cout<<"Name: ";
    is>>obj.name;

    int traitsNumber;
    string trait;
    cout<<"Number of traits: ";
    is>>traitsNumber;
    for (int i=0; i<traitsNumber;i++) {
        cout<<"Trait "<<i+1<<": ";
        is>>trait;
        obj.traitsName.push_back(trait);
    }

    cout<<"Secret Trait: ";
    is>>obj.secretTrait;

    return is;
}

void Partner::loadFromFile(ifstream &fin) {
    string line;
    string token;

    getline(fin, line);

    while (line.empty()&&!fin.eof())getline(fin, line);

    stringstream ss(line);
    getline(ss, token, '|');
    this->name=token;

    int nrTraits;
    getline(ss, token, '|');
    nrTraits=stoi(token);

    traitsName.clear();
    for (int i=0;i<nrTraits;i++) {
        getline(ss, token, '|');
        string& trait=token;//trb de tip Trait?
        this->traitsName.push_back(token);
    }

    getline(ss, token);
    this->secretTrait=token;



}

void Partner::loadTraits(std::vector<Trait *> &traitPool) {

    for (auto t: traitPool) {
        for (string tN: traitsName) {
            if (tN==t->getName()) {
                this->traits.push_back(t);
            }
        }

    }
}

void Partner::showTraits() {
    cout<<"They are ";
    for (int i=0;i<(traits.size()-1);i++) {
        cout<<traits[i]->getName()<<", ";
    }
    cout<<"and "<<traits.back()->getName()<<".";

    string secretTrait="";
    for (auto c: this->secretTrait)if (c=='_')secretTrait+=' ';
    else secretTrait+=c;

    cout<<" They also "<<secretTrait;
}

