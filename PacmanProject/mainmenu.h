#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <string>
#include "gamewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainMenu; }
QT_END_NAMESPACE

class mainMenu : public QMainWindow {
Q_OBJECT

    public:
        mainMenu(QWidget *parent = nullptr);
        ~mainMenu();

    private:
        Ui::mainMenu *ui;
        std::string lvl1_path, lvl2_path, lvl3_path;
        gameWindow* gameWindowPtr;



    public slots:
        void slotStartLevel1();
        void slotStartLevel2();
        void slotStartLevel3();
        // void slotStartCustomLevel(std::string mapFilePath);


};
#endif // MAINMENU_H
