#include "gamewindow.h"

gameWindow::gameWindow(std::string lvl_ptr) {
    current_map = new Map(lvl_ptr);

}

gameWindow::~gameWindow() {
    delete current_map;
}

void gameWindow::onRefresh() {

}
