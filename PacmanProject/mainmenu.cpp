#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QErrorMessage>
mainMenu::mainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainMenu){
    ui->setupUi(this);
    // relative paths!
    lvl1_path = "/home/roman/EIS_Projektarbeit/rohoehn/PacmanProject/txt_maps/level1.txt";// /txt_maps/level1.txt";
    lvl2_path = "/home/roman/EIS_Projektarbeit/rohoehn/PacmanProject/txt_maps/level2.txt";
    lvl3_path = "/home/roman/EIS_Projektarbeit/rohoehn/PacmanProject/txt_maps/level3.txt";
    connect(ui->playLevel1, SIGNAL(clicked()), this, SLOT(slotStartLevel1()));
    connect(ui->playLevel2, SIGNAL(clicked()), this, SLOT(slotStartLevel2()));
    connect(ui->playLevel3, SIGNAL(clicked()), this, SLOT(slotStartLevel3()));

}

mainMenu::~mainMenu(){
    delete ui;
    //delete gameWindowPtr;
}


void mainMenu::slotStartLevel1() {
    gameWindowPtr = new gameWindow(lvl1_path);
    gameWindowPtr->show();
}

void mainMenu::slotStartLevel2() {
    gameWindowPtr = new gameWindow(lvl2_path);
    gameWindowPtr->show();
}

void mainMenu::slotStartLevel3() {
    gameWindowPtr = new gameWindow(lvl3_path);
    gameWindowPtr->show();
}
