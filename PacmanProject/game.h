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

};





#endif