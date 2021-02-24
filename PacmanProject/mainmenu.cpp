#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QErrorMessage>
#include <QValidator>

mainMenu::mainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainMenu){
    ui->setupUi(this);
    // setting relative paths for standard levels
    lvl1_path = "../PacmanProject/txt_maps/level1.txt";
    lvl2_path = "../PacmanProject/txt_maps/level2.txt";
    lvl3_path = "../PacmanProject/txt_maps/level3.txt";
    // connections for main menu buttons
    connect(ui->playLevel1,         SIGNAL(clicked()), this, SLOT(slotStartLevel1()));
    connect(ui->playLevel2,         SIGNAL(clicked()), this, SLOT(slotStartLevel2()));
    connect(ui->playLevel3,         SIGNAL(clicked()), this, SLOT(slotStartLevel3()));
    connect(ui->playCustomLevel,    SIGNAL(clicked()), this, SLOT(slotStartCustomLevel()));
    connect(ui->quitButton,         SIGNAL(clicked()), this, SLOT(close()));
    // setting up tool tips
    ui->playLevel1->setToolTip("Start Level 1!");
    ui->playLevel2->setToolTip("Start Level 2!");
    ui->playLevel3->setToolTip("Start Level 3!");
    ui->playCustomLevel->setToolTip("Play a custom Level at the specified Path!");
    ui->customLevelPathInput->setToolTip(("Enter the path to a matching txt File to play custom Levels!"));
    ui->quitButton->setToolTip("Quit Pacman");
}

mainMenu::~mainMenu(){
    delete ui;
    delete gameWindowPtr;
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

void mainMenu::slotStartCustomLevel() {
    QString strPath = ui->customLevelPathInput->toPlainText();
    // validate string
    if (strPath == "") {
        QErrorMessage *qEM = new QErrorMessage(this);
        qEM->showMessage("The File Path must not not be empty!");
        return;
    }
    gameWindowPtr = new gameWindow(strPath.toStdString());
    gameWindowPtr->show();

}
