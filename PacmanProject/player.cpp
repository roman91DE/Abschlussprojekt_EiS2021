#include "player.h"

Player::Player(int _xPos, int _yPos)
    : xPosition(_xPos), yPosition(_yPos), representation('*')  {}

Player::~Player() {}

int Player::getXPosition()          { return xPosition; }

int Player::getYPosition()          { return yPosition; }

char Player::getRepresentation()    { return representation; }

void Player::moveUp()       { yPosition--; }
void Player::moveDown()     { yPosition++; }
void Player::moveLeft()     { xPosition--; }
void Player::moveRight()    { xPosition++; }



