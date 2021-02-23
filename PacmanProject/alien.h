#ifndef ALIEN_H
#define ALIEN_H

class Map;

// Abstrakte Klasse als Interface
class Alien {
    protected:
        int xPosition;
        int yPosition;
        Map *map;
        bool paused;
        char cur_direction;
    public:
        Alien(int _xPos, int _yPos, Map *_map);
        virtual ~Alien();
        virtual char getRepresentation() = 0;
        virtual char getDirection() = 0;
        int getXPosition() const;
        int getYPosition() const;
        void move();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
   friend class Map;
};


class stupidAlien : public Alien {
    private:
        char representation;
    public:
        stupidAlien(int _xPos, int _yPos, Map *_map);
        virtual ~stupidAlien();
        virtual char getDirection() ;
        virtual char getRepresentation() ;
};


#endif // ALIEN_H
