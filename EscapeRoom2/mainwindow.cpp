#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createRooms();
    printWelcome();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createRooms()  {
    Room *lr, *b, *k, *o, *l ;
    lr = new Room("Living Room","A couch sits in front of you with a televison in the corner.\nThere is a coffee table with a book on top of it.");
    lr->addItem(new Item("Books"));
    lr->addItem(new Item("Note"));
    b = new Room("Child's Bedroom","There is a small bed pushed up against the wall,toys lay scattered on the floor.\nThere is a large toy castle in the corner");


    k = new Room("Kitchen","");
    k->addItem(new Item("Pan"));
    k->addItem(new Item("Toaster"));
    k->addItem(new Item("Kettle"));
    k->addItem(new Item("Key2"));


    o = new Room("Office","");
    o->addItem(new Item("Key"));

    l = new Room("Library","");
    //          (F, B, R, L)
    lr->setExits(b, k, o, l);
    b->setExits(NULL, lr,NULL,NULL );
    k->setExits(lr, NULL, NULL, NULL);
    o->setExits(NULL,NULL, NULL, lr);
    l->setExits(NULL, NULL, lr, NULL);
    currentRoom = lr;

}

/**
 *  Main play routine.  Loops until end of play.
 */
void MainWindow::printWelcome() {

    ui->textEdit->setText(QString::fromStdString("You are trapped inside an abandoned house\n,you must find a way to escape!\n"  +
                                                currentRoom->getRoomSetting() + "\n" + "You Are In The " + currentRoom->longDescription() + "\n"));
   // cout << currentRoom->longDescription() << endl;
}

void MainWindow::goRoom(string command) {


    string direction = command;
    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
    {
             ui->textEdit->setText(QString::fromStdString("You cant go that way!" + currentRoom->exitString() ));

    }else{
       currentRoom = nextRoom;
          ui->textEdit->setText(QString::fromStdString( currentRoom->getRoomSetting() + "\n" + "You Are In The " + currentRoom->longDescription() + "\n"));
        }

    }


string MainWindow::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }

}

void MainWindow::on_for_2_clicked()
{
    goRoom("forward");
}

void MainWindow::on_right_clicked()
{
    goRoom("right");
}

void MainWindow::on_back_clicked()
{
    goRoom("backward");
}

void MainWindow::on_left_clicked()
{
    goRoom("left");
}

void MainWindow::on_pickUp_clicked()
{
    int bar = ui->progressBar->value();
    int key = bar + 25;
    int key2 = bar + 25;
    int key3 = bar + 25;
    int key4 = bar + 25;
    QString item = ui->pickItem->toPlainText();
    if(item == "")
    {
        ui->label->setText("Please type the item you \nwould like to pick up.");
    }

    else if(item == ui->comboBox->currentText())
    {
        ui->label->setText("You already picked this up!");
    }
    else{
        //int location = currentRoom->isItemInRoom(item)));
    ui->comboBox->addItem(item);
    ui->label->setText("Item Added!");
    ui->comboBox->setCurrentText(item);

    }
    if(item == "Key" || item == "key")
    {
         ui->progressBar->setValue(key);
    }
    if(item == "Key2" || item == "key2")
    {
        ui->progressBar->setValue(key2);
    }
}




