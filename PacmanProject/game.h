#ifndef __GAMEHEADER__
#define __GAMEHEADER__

#include <vector>
#include <string>
#include "player.h"
#include "alien.h"
#include "map.h"

class Game {
    public:
        Player *player;
        Map *map;
        std::vector <Alien*> aliens;
        int roundCount;
        int score;
        int total_pill_count;
    public:
        Game(std::string filepathMap);
        ~Game();
        bool alive();
        void update();
        bool level_complete();
        void moveAliens();
        // kodierung user input: 1=links; 2=rechts, 3=oben, 4=unten
        void movePlayer(int userInput);

};

#endif
