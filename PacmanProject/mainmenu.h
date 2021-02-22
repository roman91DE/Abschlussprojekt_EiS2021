#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mainMenu; }
QT_END_NAMESPACE

class mainMenu : public QMainWindow
{
    Q_OBJECT

public:
    mainMenu(QWidget *parent = nullptr);
    ~mainMenu();

private:
    Ui::mainMenu *ui;

public slots:
    void slotStartLevel(std::string mapFilePath);


};
#endif // MAINMENU_H
