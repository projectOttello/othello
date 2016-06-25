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
#include "base_class.h"
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

class Single_Player : public QMainWindow,public Base_Class
{
    Q_OBJECT
public:
    explicit Single_Player(QWidget *parent = 0);
    ~Single_Player();
    void Create();

    void Modify();
    int size;
    bool count_black_white();
    void user_name(QString username);
    void change_taw(int x,int y,int state);
    void click();
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
