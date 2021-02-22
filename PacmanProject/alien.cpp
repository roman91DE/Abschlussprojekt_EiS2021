#include "alien.h"
#include "map.h"
#include <QRandomGenerator>

Alien::Alien(int _xPos, int _yPos, Map *_map)
    : xPosition(_xPos), yPosition(_yPos), map(_map), paused(true) {}


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
    : Alien(_xPos,_yPos, _map), representation('g') {}


char stupidAlien::getRepresentation()  { return representation; }


char stupidAlien::getDirection() {
    // zufallsgenerator: 1=hoch; 2=runter; 3=links; 4=rechts
    // muss ich den dokumentieren?? später checken
    QRandomGenerator qRand;
    while (true) {
        int zv = qRand.bounded(1,5);
        if (zv == 1) {
            if (map->isFree(xPosition, yPosition-1)) {
                return 'u';
            }
        }
        else if (zv == 2) {
            if (map->isFree(xPosition, yPosition+1)) {
                return 'd';
            }
        }
        else if (zv == 3) {
            if (map->isFree(xPosition-1, yPosition)) {
                return 'l';
            }
        }
        else if (zv == 4) {
            if (map->isFree(xPosition+1, yPosition)) {
                return 'r';
            }
        }

    }
}







