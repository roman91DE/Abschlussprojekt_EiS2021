#include "game.h"
#include "player.h"
#include "alien.h"
#include "map.h"


Game::Game(std::string filepathMap) : roundCount(0), score(0), total_pill_count(0) {
    map = new Map(filepathMap);
    char temp;
    for(unsigned int iy = 0; iy < map->vec.size(); iy++) {
        for (unsigned int ix = 0; ix < map->vec[iy].size(); ix++) {
            temp = map->vec[iy][ix];
            // spieler erstellen
            if      (temp == '*')   {
                 player = new Player(ix, iy); 
                 map->vec[iy][ix] = ' ';
            }
            // pillen zählen
            else if (temp=='.') { total_pill_count++; }
            // stupid Aliens erstellen
            else if (temp == 'g')   {
                aliens.push_back(new stupidAlien(ix, iy, map));
                map->vec[iy][ix] = '.';
                total_pill_count++;
            }
            // smarte Aliens erstellen
             else if (temp == 'G') {
                 aliens.push_back(new smartAlien(ix, iy, map));
                 map->vec[iy][ix] = '.';
                 total_pill_count++;
             }
        }
    }
    // sound Generator der beim Aufnehmen von Pillen abspielt
    pillSound = new QMediaPlayer();
    pillSound->setMedia(QUrl("qrc:/new/sounds/wav_sounds/cembalo-3.wav"));
    pillSound->setVolume(10000);
}

bool Game::level_complete() {
    if (score == total_pill_count) { return true; }
    else                           { return false; }
}


Game::~Game() {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        delete aliens[i];
    }
    delete player;
    delete map;
    delete pillSound;
}

bool Game::isAlive() {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        if ( (aliens[i]->getXPosition() == player->getXPosition()) &&
             (aliens[i]->getYPosition() == player->getYPosition()) )
                { return false; }
    }
    return true;
}


void Game::update() {
    roundCount++;
    if (map->vec[player->getYPosition()][player->getXPosition()] == '.') {
        map->vec[player->getYPosition()][player->getXPosition()] = ' ';
        pillSound->play();
        score++;
    }
}

void Game::movePlayer(int userInput) {
    int x = player->getXPosition();
    int y = player->getYPosition();
    if      (userInput == 1) { 
        if (map->isFree(x-1, y)) { player->moveLeft(); }
    }
    else if (userInput == 2) { 
        if (map->isFree(x+1, y)) { player->moveRight(); }
    }
    else if (userInput == 3) { 
        if (map->isFree(x, y-1)) { player->moveUp(); }
    }
    else if (userInput == 4) { 
        if (map->isFree(x, y+1)) { player->moveDown(); }
    }
}


void Game::moveAliens(int xPlayer, int yPlayer) {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        aliens[i]->move(xPlayer, yPlayer);
    }
}

