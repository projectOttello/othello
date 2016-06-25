#ifndef SINGLE_PLAYER_H
#define SINGLE_PLAYER_H
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
#define black false
#define white true
#define White 2
#define Black 1
namespace Ui {
class Single_Player;
}

class Single_Player : public QMainWindow
{
    Q_OBJECT
public:
    explicit Single_Player(QWidget *parent = 0);
    ~Single_Player();
    QPushButton button[8][8];
    QString User;
    //for black is one and for white is two
    int array[8][8];
    int black_movement[32][2];
    int white_movement[32][2];
    int size;
    void Create();
    bool turn;
    void Modify();
    void set(int x,int y,bool in);
    bool is_in(int x,int y);
    bool count_black_white();
    void Check_West(int i,int j,int state);
    void Check_East(int i,int j,int state);
    void Check_North(int i,int j,int state);
    void Check_South(int i,int j,int state);
    void Check_North_West(int i,int j,int state);
    void Check_North_East(int i,int j,int state);
    void Check_South_East(int i,int j,int state);
    void Check_South_West(int i,int j,int state);
    void Check_White(int i,int j);
    void Check_Black(int i,int j);
    void user_name(QString username);
    bool finish();
    void change_taw(int x,int y,int state);
    bool check(bool in);
    bool load;
signals:

public slots:
private slots:
    void on_Start_clicked();

    void on_pushButton_clicked();

    void on_Load_clicked();

    void on_Save_clicked();

    void on_End_clicked();

    void on_Back_clicked();

private:
    Ui::Single_Player *ui;
};

#endif // SINGLE_PLAYER_H
