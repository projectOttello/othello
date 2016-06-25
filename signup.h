#ifndef SIGNUP_H
#define SIGNUP_H
#include "dbmanager.h"
#include "othello_game.h"
#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QMessageBox>
#include <QFileInfo>
#include <QPixmap>

namespace Ui {
class SignUp;
}

class SignUp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();
    
private slots:
    void on_Submit_btn_clicked();
    void on_username_line_textChanged(const QString &arg1);

private:
    Ui::SignUp *ui;
    DBManager db;
};
#endif // SIGNUP_H
