#include <iostream>
#include "Exceptions.h"
using namespace std;
#include "Game.h"
int main() {
    srand(time(nullptr));
    Game myGame;
    try {
        myGame.loadAllEvents();
        myGame.connectFollowUps();
        myGame.run();
    } catch (const FileNotFoundException& e) {
        cout << "Error: " << e.what() << "\n";
    } catch (const GameException& e) {
        cout << "Game error: " << e.what() << "\n";
    }
    return 0;



}