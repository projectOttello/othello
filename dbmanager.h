#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QObject>
#include <QVariant>
class DBManager : public QObject
{
    Q_OBJECT
public:
    bool flag;
    bool exist_before;
    bool signup_flag;
    explicit DBManager(QObject *parent = 0);
    ~DBManager();
    bool openDB();
    bool insertDB(QString username,QString firstname,QString lastname,QString password);
    QSqlQuery login(QString username,QString password);
signals:
    
public slots:

private:
    QSqlDatabase db;
    
};

#endif // DBMANAGER_H
