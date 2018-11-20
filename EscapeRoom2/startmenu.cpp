#include "startmenu.h"
#include "ui_startmenu.h"
#include "mainwindow.h"

StartMenu::StartMenu(QWidget *parent) :
    QStartMenu(parent),
    ui(new Ui::StartMenu)
{
    ui->setupUi(this);
}

StartMenu::~StartMenu()
{
    delete ui;
}

void StartMenu::on_start_clicked()
{
    MainWindow main;
    main.setModal(true);
    main.exec();
}

void StartMenu::on_quit_clicked()
{
     StartMenu:: close();
}
