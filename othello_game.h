#ifndef OTHELLO_GAME_H
#define OTHELLO_GAME_H
#include <QPixmap>
#include <QMainWindow>
#include <QString>
#include "two_player.h"
#include "single_player.h"
namespace Ui {
class Othello_game;
}

class Othello_game : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Othello_game(QWidget *parent = 0);
    QString User;
    void user_name(QString username);
    ~Othello_game();
    
private slots:
    void on_pushButton_4_clicked();

    void on_Single_Player_clicked();


    void on_Two_Player_clicked();

private:
    Ui::Othello_game *ui;
};

#endif // OTHELLO_GAME_H



