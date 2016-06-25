#ifndef DIALOG_H
#define DIALOG_H
#include "dbmanager.h"
#include "othello_game.h"
#include <QPixmap>
namespace Ui {
class Dialog;
}
class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_btnLogin_clicked();

private:
    Ui::Dialog *ui;
    DBManager db;
};

#endif // DIALOG_H
