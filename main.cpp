#include <iostream>
using namespace std;
#include "Game.h"
int main() {
    Game myGame;
    myGame.loadAllEvents();
    myGame.connectFollowUps();
    myGame.run();
    return 0;

}