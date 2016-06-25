#include "start_window.h"
#include "ui_start_window.h"

Start_Window::Start_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start_Window)
{
    ui->setupUi(this);
    QPixmap pix("othello");
    QIcon icon("icon");
    this->setWindowIcon(icon);
    ui->label->setPixmap(pix);
    this->setWindowTitle("Othello");

}

Start_Window::~Start_Window()
{
    delete ui;
}

void Start_Window::on_signin_btn_clicked()
{
    Dialog *w=new Dialog();
    w->show();
    this->hide();
}
void Start_Window::on_exit_btn_clicked()
{
    this->close();
}

void Start_Window::on_signup_btn_clicked()
{
    SignUp *x=new SignUp();
    x->show();
    this->hide();
}
