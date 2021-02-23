#include "gamewindow.h"
#include <QString>


gameWindow::gameWindow(std::string lvl_ptr) {
    current_game = new Game(lvl_ptr);
}

gameWindow::~gameWindow() {
    delete current_game;
}

void gameWindow::drawCurrentState() {
    // draw score to console
    int buffer = 4;
    QString score_string = (
    "current Score: " +  QString::number(current_game->score)
    + "/" + QString::number(current_game->total_pill_count));
    writeString(0,1,score_string.toStdString());

    // draw map to console
    for (unsigned int iy = 0+buffer; iy < current_game->map->vec.size()+buffer; iy++) {
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
    current_game->moveAliens();
    if (getPressedKey() == CURSOR_LEFT)     { current_game->movePlayer(1); }
    if (getPressedKey() == CURSOR_RIGHT)    { current_game->movePlayer(2); }
    if (getPressedKey() == CURSOR_UP)       { current_game->movePlayer(3); }
    if (getPressedKey() == CURSOR_DOWN)     { current_game->movePlayer(4);}
    // check if player died
    if (!current_game->alive()) {
        writeString(1,1,"---you are Dead!---");
    }
    // check if level completed
    if (current_game->level_complete()) {
        writeString(1,1,"---you completed the Level!---");
    }
    // update current state of the game
    current_game->update();


}
