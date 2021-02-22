#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <string>

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
        std::string lvl1_path;
        std::string lvl2_path;
        std::string lvl3_path;

    public slots:
        void slotStartLevel(std::string mapFilePath);


};
#endif // MAINMENU_H
