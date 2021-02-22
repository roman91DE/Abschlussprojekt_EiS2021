#include "mainmenu.h"
#include "ui_mainmenu.h"

mainMenu::mainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainMenu){
    ui->setupUi(this);
    lvl1_path = "txt_maps/level1.txt";
    lvl2_path = "txt_maps/level2.txt";
    lvl3_path = "txt_maps/level3.txt";
}

mainMenu::~mainMenu(){
    delete ui;
}

