#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QDir>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pixmap("icon");
    this->setWindowIcon(pixmap);
    this->setWindowTitle("Sign In");
    if(db.openDB())
    ui->lblResult->setText("[+]Connected to Database file :)");
    else
    ui->lblResult->setText("[!]Database file does not exist :(");
}
Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_btnLogin_clicked()
{
    QString Username,Password;
    Username=ui->txtUser->text();
    Password=ui->txtPass->text();
    if(!db.openDB())
    {
        qDebug()<<"No Connection to DB :(";
        return;
    }
    QSqlQuery qry=db.login(Username,Password);
    if(db.flag)
    {
        QString msg="Username= "+qry.value(0).toString()+"\n"+"Password = "+qry.value(1).toString();
        QMessageBox::warning(this,"Login was successful",msg);
        ui->lblResult->setText("[+] Valid Username and Password");
        Othello_game *b=new Othello_game();
        b->user_name(Username);
        b->show();
        this->hide();
    }
    else
        ui->lblResult->setText("[-]Wrong Username and Password. :(");
}
