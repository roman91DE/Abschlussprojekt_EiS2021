#include "mainmenu.h"

#include <QApplication>

// with main menu
// --------------
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainMenu w;
    w.show();
    return a.exec();
}



// skip main menu
//// ---------------
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    gameWindow w("/txt_maps/level1.txt");
//    w.show();
//    return a.exec();
//}

