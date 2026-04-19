//
// Created by David on 4/19/2026.
//

#include "Partner.h"
#include <iostream>
#include <vector>
using namespace std;

Partner::Partner() {
    name="N/A";
    traits.push_back("N/A");
    secretTrait="N/A";
}

Partner::Partner(string name, vector<string>& traits, string secretTrait) {
    this->name=name;
    this->traits=traits;
    this->secretTrait=secretTrait;
}

Partner::Partner(const Partner &obj) {
    this->name=obj.name;
    this->traits=obj.traits;
    this->secretTrait=obj.secretTrait;
}

Partner& Partner::operator=(const Partner &obj) {
    if (this==&obj) return *this;

    this->name=obj.name;
    this->traits=obj.traits;
    this->secretTrait=obj.secretTrait;

    return *this;
}

Partner::~Partner() = default;

ostream& operator<<(ostream &os, const Partner &obj) {
    os<<"Name: " << obj.name<< "\n";

    os<<"Traits: " ;
    for (const string& trait: obj.traits) os<<trait<<" ";
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
        obj.traits.push_back(trait);
    }

    cout<<"Secret Trait: ";
    is>>obj.secretTrait;

    return is;
}
