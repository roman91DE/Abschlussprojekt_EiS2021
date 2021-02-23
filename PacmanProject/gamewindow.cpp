#include "gamewindow.h"


gameWindow::gameWindow(std::string lvl_ptr) {
    current_game = new Game(lvl_ptr);
}

gameWindow::~gameWindow() {
    delete current_game;
}

void gameWindow::drawCurrentState() {

}

void gameWindow::onRefresh() {

}
