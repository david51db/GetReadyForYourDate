//
// Created by David on 4/19/2026.
//

#ifndef GETREADYFORYOURDATE_EVENT_H
#define GETREADYFORYOURDATE_EVENT_H

#include <iostream>
#include <string>

class Event{
    std::string text;
    const int id;
    static int totalEvents;
    bool phase; //0 for prep, 1 for date

public:
    Event();
    Event(std::string text, bool phase);
    Event(const Event& obj);
    Event& operator=(const Event& obj);
    virtual ~Event();

    friend std::ostream& operator<<(std::ostream& os, const Event& obj);
    friend std::istream& operator>>(std::istream& is, Event& obj);

    // virtual void trigger()=0;
};

#endif //GETREADYFORYOURDATE_EVENT_H