//
// Created by David on 4/21/2026.
//

#ifndef GETREADYFORYOURDATE_MINIGAME_H
#define GETREADYFORYOURDATE_MINIGAME_H


#include <iostream>

class MiniGame {
protected:
    int reward;
    std::string text;

public:
    MiniGame();
    MiniGame(int reward, std::string text);
    MiniGame(const MiniGame& obj);
    MiniGame& operator=(const MiniGame& obj);
    virtual ~MiniGame();




    friend std::ostream& operator<<(std::ostream& os, const MiniGame& obj);
    friend std::istream& operator>>(std::istream& is, MiniGame& obj);

    virtual int play()=0;
    int getReward(){return reward;}
};



#endif //GETREADYFORYOURDATE_MINIGAME_H