#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "room.h"
#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <string>
#include "item.h"
#include "character.h"
#include "qtimer.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class Room;
public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *timer;
    ~MainWindow();
public slots:


private slots:

    void on_right_clicked();

    void on_left_clicked();

    void on_back_clicked();

    void on_for_2_clicked();

    void on_pickUp_clicked();

    void on_pushButton_clicked();

    void on_quit_clicked();

private:


    Ui::MainWindow *ui;
    std::string go(std::string direction);
    //void progressbarTimer();
   // void updateProgresbar();
    void DisableButtons();
    void createRooms();
    void printWelcome();
    void printHelp();
    void goRoom(std::string command);
    Character character = *new Character(100);
    Room *currentRoom;
    Item *pItem;

};

#endif // MAINWINDOW_H
