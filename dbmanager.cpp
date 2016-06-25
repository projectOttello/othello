#include "dbmanager.h"
#include <QMessageBox>
#include <QVariant>
DBManager::DBManager(QObject *parent) :
    QObject(parent)
{
        flag=false;
        signup_flag=false;
        exist_before=false;
}

bool DBManager::openDB()
{
    QString path = "register";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();
    QSqlQuery query;
    query.exec("create table info"
               "(username varchar(35) primary key, "
              "firstname varchar(35), "
              "lastname varchar(35), "
               "password varchar(35))");
    if(db.open())
        return true;
    else
        return false;
}
bool DBManager::insertDB(QString username, QString firstname, QString lastname, QString password)
{
    QSqlQuery search;
    search.exec("select username from info");
    while(search.next())
    {
        if(search.value(0).toString()==username)
        {
            exist_before=true;
            return false;
         }
    }
    QSqlQuery qry;
    qry.prepare("INSERT INTO info (username,firstname,lastname,password)VALUES(:username,:firstname,:lastname,:password)");
    qry.bindValue(":username",username);
    qry.bindValue(":firstname",firstname);
    qry.bindValue(":lastname",lastname);
    qry.bindValue(":password",password);
    if(qry.exec())
    {
        signup_flag=true;
        return true;
    }
        return false;
}
QSqlQuery DBManager::login(QString Username,QString Password)
{
    QSqlQuery qry;
    qry.exec("select username,password from info");
    while(qry.next())
    {
        if(qry.value(0).toString()==Username && qry.value(1).toString()==Password)
        {
            flag=true;
            return qry;
        }
           else
           return qry;
    }
}
DBManager::~DBManager()
{
    db.close();
}
