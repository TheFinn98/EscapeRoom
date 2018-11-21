#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Room.h"
#include <QMainWindow>
#include <string>
#include "item.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class Room;
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();


private slots:

    void on_right_clicked();

    void on_left_clicked();

    void on_back_clicked();

    void on_forward_clicked();

    void on_pickUp_clicked();

private:


    Ui::MainWindow *ui;
    std::string go(std::string direction);
    void DisableButtons();
    void createRooms();
    void printWelcome();
    void printHelp();
    void goRoom(std::string command);

    Room *currentRoom;
    Item *pItem;

};

#endif // MAINWINDOW_H
