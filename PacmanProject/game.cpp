#include "game.h"
#include "player.h"
#include "alien.h"
#include "map.h"


Game::Game(std::string filepathMap) : roundCount(0) {
    map = new Map(filepathMap);
    char temp;
    for(unsigned int iy = 0; iy < map->vec.size(); iy++) {
        for (unsigned int ix = 0; ix < map->vec[iy].size(); ix++) {
            temp = map->vec[iy][ix];
            if      (temp == '*')   {
                 player = new Player(ix, iy); 
            }
            else if (temp == 'g')   {
                aliens.push_back(new stupidAlien(ix, iy, map));
            }
            // noch nicht implementiert
            // else if (temp == 'G') {
            //     aliens.push_back(new smartAlien(ix, iy, map));
            // }
        }
    }
}


Game::~Game() {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        delete aliens[i];
    }
    delete player;
    delete map;
}

bool Game::alive() {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        if ( aliens[i]->getXPosition() == player->getXPosition()
                                &&
             aliens[i]->getYPosition() == player->getXPosition() ) {
                 return false;
             }
    }
    return true;
}

void Game::update() {
    roundCount++;
    if (map->vec[player->getYPosition()][player->getXPosition()] == '.') {
        map->vec[player->getYPosition()][player->getXPosition()] = ' ';
    }
}