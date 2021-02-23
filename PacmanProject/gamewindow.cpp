#include "gamewindow.h"
#include <QString>
#include <QMessageBox>


gameWindow::gameWindow(std::string lvl_ptr) {
    current_game = new Game(lvl_ptr);
    running = true;
}

gameWindow::~gameWindow() {
    delete current_game;
}

void gameWindow::drawCurrentState() {
    // draw score to console
    int buffer = 4;
    QString score_string = (
    "Score: " +  QString::number(current_game->score)
    + "/" + QString::number(current_game->total_pill_count));
    writeString(12,1,score_string.toStdString());
    QString time_string = "Timer:" + (QString::number(current_game->roundCount/5));
    writeString(42,1,time_string.toStdString());

    // draw map to console
    for (unsigned int iy = 0; iy < current_game->map->vec.size(); iy++) {
        for (unsigned int ix = 0; ix < current_game->map->vec[iy].size(); ix++) {
            setCharacter(ix,iy+buffer,  current_game->map->vec[iy][ix]);
        }
    }
    // draw player to console
    int x_player = current_game->player->getXPosition();
    int y_player = current_game->player->getYPosition();
    char repr_player = current_game->player->getRepresentation();
    setCharacter(x_player, y_player+buffer, repr_player);

    // draw aliens to console
    for (unsigned int i = 0; i < current_game->aliens.size(); i++) {
        int x_alien = current_game->aliens[i]->getXPosition();
        int y_alien = current_game->aliens[i]->getYPosition();
        char repr_alien =  current_game->aliens[i]->getRepresentation();
        setCharacter(x_alien, y_alien+buffer, repr_alien);
    }

}

void gameWindow::onRefresh() {
    clear();
    drawCurrentState();

    current_game->moveAliens();
    // check if player died
    if ((current_game->isAlive()==false) && running) {
        QString str = "You are Dead!";
        endGame(str);
    }


    if (getPressedKey() == CURSOR_LEFT)     { current_game->movePlayer(1); }
    if (getPressedKey() == CURSOR_RIGHT)    { current_game->movePlayer(2); }
    if (getPressedKey() == CURSOR_UP)       { current_game->movePlayer(3); }
    if (getPressedKey() == CURSOR_DOWN)     { current_game->movePlayer(4);}



    // check if level completed
    if (current_game->level_complete() && running) {
        int timeToFinish = current_game->roundCount/5;
        QString str = "You completed the Level!\n";
        str += "Total Time = " + (QString::number(timeToFinish)) + "Seconds";
        endGame((str));
    }

    // update current state of the game
    current_game->update();

}

void gameWindow::endGame(QString &str) {
    running = false;
    QMessageBox qMB(this);
    qMB.setText(str);
    qMB.exec();
    this->close();
}
