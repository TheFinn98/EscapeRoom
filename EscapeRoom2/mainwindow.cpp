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

/*void MainWindow::progressbarTimer(QString TimeSet)
{
    ui->progressBar->setMaximum(TimeSet.toInt()*1000);
    QTimer *timer = new QTimer(this);
    currenttime = TimeSet.toInt();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateProgresbar()));
    timer->start(1);
}

void MainWindow::updateProgresbar()
{
    int counter = 0;
    int currenttime;
    if(counter <= currenttime*1000)
    {
        counter++;
        ui->progressBar->setValue(counter);
    }
    else
    {
        timer->stop();
        delete timer;
    }
} */


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createRooms()  {
    Room *lr, *b, *k, *o, *l ;
    lr = new Room("Living Room","A couch sits in front of you with a televison in the corner."
                                "\nThere is a coffee table with a book on top of it.");
    lr->addItem(new Item("Book"));

    b = new Room("Child's Bedroom","There is a small bed pushed up against the wall,toys lay scattered on the floor."
                                   "\nThere is a large toy castle in the corner");
    b->addItem(new Item("Key4"));

    k = new Room("Kitchen","Pots and pans are thrown all over the shop, the fridge is lying on the ground. \n"
                           "A kettle and toaster sit on the counter top."
                           "\nThere also appears to be an ice cube running along the counter top.");

    k->addItem(new Item("Key2"));
    k->addItem(new Item("Toaster"));
    k->addItem(new Item("Kettle"));

    o = new Room("Office","");
    o->addItem(new Item("Key"));

    l = new Room("Library","");
    l->addItem(new Item("Key3"));

    //          (F, B, R, L)
    lr->setExits(b, k, o, l);
    b->setExits(nullptr, lr,nullptr,nullptr );
    k->setExits(lr, nullptr, nullptr, nullptr);
    o->setExits(nullptr,nullptr, nullptr, lr);
    l->setExits(nullptr, nullptr, lr, nullptr);
    currentRoom = lr;

}

/**
 *  Main play routine.  Loops until end of play.
 */
void MainWindow::printWelcome() {

    ui->textEdit->setText(QString::fromStdString("You are trapped inside an abandoned house\n,"
                                                 "you must find a way to escape!\n"  +
                                                currentRoom->getRoomSetting() + "\n" + "You Are In The " +
                                                 currentRoom->longDescription() + "\n"));
}

void MainWindow::goRoom(string command) {


    string direction = command;
    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == nullptr)
    {
             ui->textEdit->setText(QString::fromStdString("You cant go that way!" + currentRoom->exitString() ));

    }else{
       currentRoom = nextRoom;
          ui->textEdit->setText(QString::fromStdString( currentRoom->getRoomSetting() + "\n" + "You Are In The " +
                                                        currentRoom->longDescription()));
        }

    }


string MainWindow::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == nullptr)
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
    QString item = ui->pickItem->toPlainText();
    if(item == "")
    {
        ui->label->setText("Please type the item you \nwould like to pick up.");
    }
    else if(item == ui->comboBox->currentText())
    {
        ui->label->setText("You already picked this up!");
    }
    else if(item != QString::fromStdString(currentRoom->showItemInInventory()))
    {

        ui->label->setText("Item is not in room");
    }

    else{

    string temp = item.toStdString();
    //ui->comboBox->addItem(item);
    ui->label->setText("Item Added!");
    ui->comboBox->clear();
    character.addItem(*new Item(temp));
    vector <Item> items = character.getItems();
    for(int i = 0; i < items.size();i++)
        ui->comboBox->addItem(QString::fromStdString(items[i].getShortDescription()));
   // ui->comboBox->

    if(item == "Key" || item == "key")
    {
         ui->progressBar->setValue(key);
    }
    if(item == "Key2" || item == "key2")
    {
        ui->progressBar->setValue(key);
    }
    if(item == "Key3" || item == "key3")
    {
        ui->progressBar->setValue(key);
    }
    if(item == "Key4" || item == "key4")
    {
        ui->progressBar->setValue(key);
    }
    }
}

void MainWindow::on_pushButton_clicked()
{
    int bar = ui->progressBar->value();
    if(bar == 100)
    {
        ui->label->setText("Congratulations! You Escaped!");
    }
    else
    {
        ui->label->setText("Not enough keys!");
    }
}


void MainWindow::on_quit_clicked()
{
    MainWindow:: close();
}
