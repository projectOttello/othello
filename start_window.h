#ifndef START_WINDOW_H
#define START_WINDOW_H
#include "dialog.h"
#include "signup.h"
#include <QPixmap>
#include <QIcon>
#include <QMainWindow>

namespace Ui {
class Start_Window;
}

class Start_Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Start_Window(QWidget *parent = 0);
    ~Start_Window();
    
private slots:
    void on_signin_btn_clicked();

    void on_exit_btn_clicked();

    void on_signup_btn_clicked();

private:
    Ui::Start_Window *ui;
};

#endif // START_WINDOW_H
