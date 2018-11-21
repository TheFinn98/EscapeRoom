#include "startgamewindow.h"
#include "ui_startgamewindow.h"

startGameWindow::startGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startGameWindow)
{
    ui->setupUi(this);
}

startGameWindow::~startGameWindow()
{
    delete ui;
}

void startGameWindow::on_startGameButton_clicked()
{

}
