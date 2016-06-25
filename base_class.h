#ifndef BASE_CLASS_H
#define BASE_CLASS_H
#include <iostream>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QLineEdit>
#include <QPixmap>
#define black false
#define white true
#define White 2
#define Black 1

class Base_Class
{
public:
    Base_Class();

    QPushButton button[8][8];
    QString User;
    int array[8][8];
    int black_movement[32][2];
    int white_movement[32][2];
    int size;
    bool turn;
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
    bool finish();
    bool check(bool in);
    virtual void click();

    bool load;
};

#endif // BASE_CLASS_H
