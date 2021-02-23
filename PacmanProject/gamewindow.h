#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "ConsoleWindow.h"
#include "game.h"

class gameWindow : public ConsoleWindow
{
private:
        Game *current_game;

    public:
        gameWindow(std::string lvl_ptr);
        ~gameWindow();
        void onRefresh();
        void drawCurrentState();


};

#endif // GAMEWINDOW_H
