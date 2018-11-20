#ifndef STARTMENU_H
#define STARTMENU_H

#include <QDialog>

namespace Ui {
class StartMenu;
}

class StartMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu();

private slots:
    void on_start_clicked();

    void on_quit_clicked();

private:
    Ui::StartMenu *ui;
};

#endif // STARTMENU_H
