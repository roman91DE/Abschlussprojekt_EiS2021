#include "alien.h"
#include "map.h"
#include <cstdlib>
#include <random>

Alien::Alien(int _xPos, int _yPos, Map *_map)
    : xPosition(_xPos), yPosition(_yPos), map(_map), paused(true), cur_direction('l') {}

Alien::~Alien(){};


int Alien::getXPosition()       const { return xPosition; }
int Alien::getYPosition()       const { return yPosition; }

void Alien::move() {
    if (paused) {
        paused = false;
        return;
    }
    paused = true;
    char direction = getDirection();
    if      (direction == 'u') { moveUp(); }
    else if (direction == 'd') { moveDown(); }
    else if (direction == 'l') { moveLeft(); }
    else if (direction == 'r') { moveRight(); }

}

void Alien::moveUp()       { yPosition--; }
void Alien::moveDown()     { yPosition++; }
void Alien::moveLeft()     { xPosition--; }
void Alien::moveRight()    { xPosition++; }



// stupid Aliens Subclass

stupidAlien::stupidAlien(int _xPos, int _yPos, Map *_map)
    : Alien(_xPos, _yPos, _map), representation('g') {}


stupidAlien::~stupidAlien() {};

char stupidAlien::getRepresentation()  { return representation; }


char stupidAlien::getDirection() {
    // if current direction is possible: keep moving in that direction
    if (cur_direction == 'u' && (map->isFree(xPosition, yPosition-1))) { return cur_direction; }
    if (cur_direction == 'd' && (map->isFree(xPosition, yPosition+1))) { return cur_direction; }
    if (cur_direction == 'l' && (map->isFree(xPosition-1, yPosition))) { return cur_direction; }
    if (cur_direction == 'r' && (map->isFree(xPosition+1, yPosition))) { return cur_direction; }
    // zufallsgenerator: 1=hoch; 2=runter; 3=links; 4=rechts
    while (true) {
        int zv = 1+ rand()%4;
        if (zv == 1) {
            if (map->isFree(xPosition, yPosition-1)) {
                cur_direction = 'u';
                return 'u';
            }
        }
        else if (zv == 2) {
            if (map->isFree(xPosition, yPosition+1)) {
                cur_direction = 'd';
                return 'd';
            }
        }
        else if (zv == 3) {
            if (map->isFree(xPosition-1, yPosition)) {
                cur_direction = 'l';
                return 'l';
            }
        }
        else if (zv == 4) {
            if (map->isFree(xPosition+1, yPosition)) {
                cur_direction = 'r';
                return 'r';
            }
        }

    }
}







