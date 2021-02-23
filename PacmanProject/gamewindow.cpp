#include "gamewindow.h"


gameWindow::gameWindow(std::string lvl_ptr) {
    current_game = new Game(lvl_ptr);
}

gameWindow::~gameWindow() {
    delete current_game;
}

void gameWindow::drawCurrentState() {
    // draw map to console
    for (unsigned int iy = 0; iy < current_game->map->vec.size(); iy++) {
        for (unsigned int ix = 0; ix < current_game->map->vec[iy].size(); ix++) {
            setCharacter(ix,iy,  current_game->map->vec[iy][ix]);
        }
    }
    // draw player to console
    int x_player = current_game->player->getXPosition();
    int y_player = current_game->player->getYPosition();
    char repr_player = current_game->player->getRepresentation();
    setCharacter(x_player, y_player, repr_player);

    // draw aliens to console
    for (unsigned int i = 0; i < current_game->aliens.size(); i++) {
        int x_alien = current_game->aliens[i]->getXPosition();
        int y_alien = current_game->aliens[i]->getYPosition();
        char repr_alien =  current_game->aliens[i]->getRepresentation();
        setCharacter(x_alien, y_alien, repr_alien);
    }

}

void gameWindow::onRefresh() {

    clear();
    drawCurrentState();
    if (getPressedKey() == CURSOR_LEFT)     { current_game->movePlayer(1); }
    if (getPressedKey() == CURSOR_RIGHT)    { current_game->movePlayer(2); }
    if (getPressedKey() == CURSOR_UP)       { current_game->movePlayer(3); }
    if (getPressedKey() == CURSOR_DOWN)     { current_game->movePlayer(4); }
    if (!current_game->alive()) {
        writeString(1,1,"you are Dead!");
    }
    current_game->update();


}
