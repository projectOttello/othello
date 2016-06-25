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
#define black false
#define white true
#define White 2
#define Black 1
#include <QMainWindow>

namespace Ui {
class two_player;
}

class two_player : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit two_player(QWidget *parent = 0);
    ~two_player();

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
