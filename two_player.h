#ifndef TWO_PLAYER_H
#define TWO_PLAYER_H
#include "othello_game.h"
#include <QMainWindow>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QLineEdit>
#include <QPixmap>
#include "base_class.h"
#include <QMainWindow>

namespace Ui {
class two_player;
}

class two_player : public QMainWindow,public Base_Class
{
    Q_OBJECT
    
public:
    explicit two_player(QWidget *parent = 0);
    ~two_player();
    void Create();
    void Modify();
    int size;
    bool count_black_white();
    void user_name(QString username);
    void change_taw(int x,int y,int state);
    void click();

public slots:
private slots:
    void on_Start_3_clicked();

    void on_Save_3_clicked();

    void on_Load_3_clicked();

    void on_End_3_clicked();

    void on_Back_3_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::two_player *ui;
};

#endif // TWO_PLAYER_H
