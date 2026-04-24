//
// Created by David on 4/19/2026.
//

#ifndef GETREADYFORYOURDATE_CHOICE_H
#define GETREADYFORYOURDATE_CHOICE_H

#include <iostream>
#include <string>
#include <vector>

class ChoiceEvent;

class Choice {
    std::string text;
    int price;
    int deltaCharm;
    int deltaDignity;
    int deltaVibe;
    int deltaMoney;
    ChoiceEvent* followUp;
    int followUpId;

public:
    Choice();
    Choice(int price, std::string text, int deltaCharm, int deltaDignity, int deltaVibe, int deltaMoney,
           ChoiceEvent *followUp, int followUpId);
    Choice(const Choice& obj);
    Choice& operator=(const Choice& obj);
    ~Choice();

    friend std::ostream& operator<<(std::ostream& os, const Choice& obj);
    friend std::istream& operator>>(std::istream& is, Choice& obj);

    int getFollowUpId() const { return followUpId; }
    void setFollowUpPointer(ChoiceEvent* ptr) { this->followUp = ptr; }

    void parseFromString(const std::string& line);

    std::string& getText(){return this->text;}
    int getPrice(){return this->price;}
    int getCharm(){return this->deltaCharm;}
    int getVibe(){return this->deltaVibe;}
    int getDignity(){return this->deltaDignity;}
    int getMoney(){return this->deltaMoney;}
    ChoiceEvent* getFollowUp() { return followUp; }







};



#endif //GETREADYFORYOURDATE_CHOICE_H

