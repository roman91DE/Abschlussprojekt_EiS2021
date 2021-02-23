#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "ConsoleWindow.h"
#include "map.h"

class gameWindow : public ConsoleWindow
{
private:
        Map* current_map;

    public:
        gameWindow(std::string lvl_ptr);
        ~gameWindow();
        void onRefresh();


};

#endif // GAMEWINDOW_H
