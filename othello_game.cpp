#include "othello_game.h"
#include "ui_othello_game.h"

Othello_game::Othello_game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Othello_game)
{
    ui->setupUi(this);
    QPixmap pix("othello");
    QIcon icon("icon");
    this->setWindowIcon(icon);
    ui->label->setPixmap(pix);
}
void Othello_game::user_name(QString username)
{
    User=username;
    this->setWindowTitle(User);
}
Othello_game::~Othello_game()
{
    delete ui;
}
void Othello_game::on_pushButton_4_clicked()
{
    exit(0);
}
void Othello_game::on_Single_Player_clicked()
{
    Single_Player * single=new Single_Player();
    single->user_name(User);
    single->show();
    this->hide();
}
void Othello_game::on_Two_Player_clicked()
{
    two_player *two=new two_player();
    two->user_name(User);
    two->show();
    this->hide();
}
