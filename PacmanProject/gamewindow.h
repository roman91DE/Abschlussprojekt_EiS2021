#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "ConsoleWindow.h"

class gameWindow : public ConsoleWindow
{
    public:
        gameWindow();
        void onRefresh();

};

#endif // GAMEWINDOW_H
