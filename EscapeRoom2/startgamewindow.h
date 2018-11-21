#ifndef STARTGAMEWINDOW_H
#define STARTGAMEWINDOW_H

#include <QDialog>

namespace Ui {
class startGameWindow;
}

class startGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit startGameWindow(QWidget *parent = nullptr);
    ~startGameWindow();

private:
    Ui::startGameWindow *ui;
};

#endif // STARTGAMEWINDOW_H
