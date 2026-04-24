#include <iostream>
using namespace std;
#include "Game.h"
int main() {
    srand(time(nullptr));
    Game myGame;
    myGame.loadAllEvents();
    myGame.connectFollowUps();
    myGame.run();
    return 0;



}