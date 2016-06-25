#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    QPixmap pixmap("icon");
    this->setWindowIcon(pixmap);
    this->setWindowTitle("Sing Up");
}

SignUp::~SignUp()
{
    delete ui;
}
void SignUp::on_Submit_btn_clicked()
{
    QString Username,Firstname,Lastname,Password;
    Username=ui->username_line->text();
    Firstname=ui->firstname_line->text();
    Lastname=ui->lastname_line->text();
    Password=ui->password_line->text();
    if(!db.openDB())
    {
        qDebug()<<"No Connection to DB :(";
        return;
    }
    //mige age nabashe meslesh vared db kon
    if(db.insertDB(Username,Firstname,Lastname,Password))
    {
        Othello_game *b=new Othello_game();
        b->user_name(Username);
        b->show();
        this->hide();
        return;
    }
    if(db.exist_before==true)
    {
        QMessageBox *msg=new QMessageBox();
        msg->setText("This user has already exists");
        msg->show();
        db.exist_before=false;
    }
}
void SignUp::on_username_line_textChanged(const QString &arg1)
{
}
