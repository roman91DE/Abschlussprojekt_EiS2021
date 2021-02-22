#ifndef __GAMEHEADER__
#define __GAMEHEADER__

#include <vector>
#include <string>

class Player;
class Alien;
class Map;

class Game {
    public:
        Player *player;
        Map *map;
        std::vector <Alien*> aliens;
        int roundCount;
    public:
        Game(std::string filepathMap);
        ~Game();
        bool alive();
        void update();
        void moveAliens();
        // kodierung user input: 1=links; 2=rechts, 3=oben, 4=unten
        void movePlayer(int userInput);

};

#endif