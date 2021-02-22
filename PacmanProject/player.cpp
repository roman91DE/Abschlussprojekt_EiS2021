#include "player.h"

Player::Player(int _xPos, int _yPos)
    : xPosition(_xPos), yPosition(_yPos), isAlive(true), representation('*')  {}

Player::~Player() {}

int Player::getXPosition() const { return xPosition; }

int Player::getYPosition() const { return yPosition; }

char Player::getRepresentation() const { return representation; }

void Player::moveUp()       { yPosition--; }
void Player::moveDown()     { yPosition++; }
void Player::moveLeft()     { xPosition--; }
void Player::moveRight()    { xPosition++; }



