#include "two_player.h"
#include "ui_two_player.h"
#include <QMessageBox>
two_player::two_player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::two_player)
{
    ui->setupUi(this);
    QPixmap pixmap("icon");
    this->setWindowIcon(pixmap);
    this->setWindowTitle("Two Player");
    size=0;
    Create();
}
two_player::~two_player()
{
    delete ui;
}

//This fucntion clears each cells and then set their relative icons
void two_player::Modify()
{
    QPixmap pixmap("None");
    QIcon icon(pixmap);
    for(int i=0;i<8;i++)
     for(int j=0;j<8;j++)
     {
         if(array[i][j]!=White && array[i][j]!=Black)
         {
         button[i][j].setIcon(icon);
         button[i][j].setIconSize(QSize(20,20));
     }
 }
    if(turn==white)
        ui->label->setText("White");
    if(turn==black)
        ui->label->setText("Black");
      QPixmap pixmap1("Black_Circle");
      QPixmap pixmap2("white-circle");
      QIcon Icon1(pixmap1);
      QIcon Icon2(pixmap2);
      for(int i=0;i<=7;i++)
          for(int j=0;j<=7;j++)
          {
              if(array[i][j]==Black)
           {
                  button[i][j].setIcon(Icon1);
                  button[i][j].setIconSize(QSize(20,20));
              }
              if(array[i][j]==White)
              {
                  button[i][j].setIcon(Icon2);
                  button[i][j].setIconSize(QSize(20,20));
              }
          }
      }

void two_player::user_name(QString username)
{
        User=username;
        this->setWindowTitle(User);
}
//This function checks that what cells should be change
void two_player::change_taw(int x, int y,int state)
{
 //This piece of code check the right values
    for(int j=y+1;j<=7;j++)
    {
            if(array[x][j]==state)
               {
                for(int i=y;i<=j;i++)
                    array[x][i]=state;
                break;
            }
    }
//This piece of code check the left value
    for(int j=y-1;j>=0;j--)
    {
            if(array[x][j]==state)
               {
                for(int i=y;i>=j;i--)
                    array[x][i]=state;
                break;
            }
        }
//This piece of code check the up value
    for(int j=x-1;j>=0;j--)
    {
            if(array[j][y]==state)
               {
                for(int i=x;i>=j;i--)
                    array[i][y]=state;
                break;
            }
        }
 //This piece of code check the down value
    for(int j=x+1;j<=7;j++)
    {
            if(array[j][y]==state)
               {
                for(int i=x;i<=j;i++)
                    array[i][y]=state;
                break;
            }
        }
//This piece of code check the north-west value
    int i=x-1;
   for(int j=y-1;j>=0 && i>=0;j--)
    {
            if(array[i][j]==state)
               {
                int a=x;
                for(int b=y;b>=j && a>=i;b--)
                {
                    array[a][b]=state;
                    a--;
               }
                 break;
            }
            i--;
        }
 //This piece of code ceck north-east
   i=x-1;
  for(int j=y+1;j<=7 && i>=0;j++)
   {
           if(array[i][j]==state)
              {
               int a=x;
               for(int b=y;b<=j && a>=i;b++)
               {
                   array[a][b]=state;
                   a--;
              }
                break;
           }
           i--;
       }
  //This piece of code check south-west
  i=x+1;
 for(int j=y-1;j>=0 && i<=7;j--)
  {
          if(array[i][j]==state)
             {
              int a=x;
              for(int b=y;b>=j && a<=i;b--)
              {
                  array[a][b]=state;
                  a++;
             }
               break;
          }
          i++;
      }
 //This piece of code check south-east
 i=x+1;
for(int j=y+1;j<=7 && i<=7;j++)
 {
         if(array[i][j]==state)
            {
             int a=x;
             for(int b=y;b<=j && a<=i;b++)
             {
                 array[a][b]=state;
                 a++;
            }
              break;
         }
         i++;
}
}

void two_player::click()
{
    if(is_in(ui->x_3->text().toInt(),ui->y_3->text().toInt())==true)
    {
    if(turn==black)
    {
     set(ui->x_3->text().toInt(),ui->y_3->text().toInt(),turn);
     change_taw(ui->x_3->text().toInt(),ui->y_3->text().toInt(),Black);
     turn=white;
     Modify();
     check(white);
     ui->label->setText("White");
    }
    else if(turn==white)
    {
     set(ui->x_3->text().toInt(),ui->y_3->text().toInt(),turn);
     change_taw(ui->x_3->text().toInt(),ui->y_3->text().toInt(),White);
     turn=black;
     Modify();
     check(black);
     ui->label->setText("Black");
    }
    else
    {
        QMessageBox *msg=new QMessageBox();
        msg->setText("Wrong move");
        msg->show();
    }
    count_black_white();
    if (finish()==true)
    {
        QMessageBox *msg=new QMessageBox();
        if(count_black_white()==true)
            msg->setText("White Win");
        else
            msg->setText("Black win");
        msg->show();
        ui->pushButton_3->setEnabled(false);
    }
}

}
bool two_player::count_black_white()
{
    int white_number=0;
    int black_number=0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if(array[i][j]==White)
                white_number++;
            if(array[i][j]==Black)
                black_number++;
        }
    ui->white_number->setText(QString::number(white_number));
    ui->black_number->setText(QString::number(black_number));
    if(white_number>black_number)
        return true;
    return false;
}
//This function create the map for initializing the game
void two_player::Create()
{
    QPixmap pixmap1("Black_Circle");
    QPixmap pixmap2("white-circle");
    QIcon Icon1(pixmap1);
    QIcon Icon2(pixmap2);
    for(int i=0;i<8;i++)
     for(int j=0;j<8;j++)
     {
         array[i][j]=0;
         button[i][j].setParent(this);
         button[i][j].resize(30,30);
         button[i][j].setStyleSheet("background-color:grey");
         button[i][j].move(30*j+10+30,30*i+10);
         button[i][j].show();
     }
    array[3][3]=White;
    array[3][4]=Black;
    array[4][4]=White;
    array[4][3]=Black;
    for(int i=0;i<8;i++)
     for(int j=0;j<8;j++)
     {
         if(array[i][j]==Black)
         {
             button[i][j].setIcon(Icon1);
             button[i][j].setIconSize(QSize(20,20));
         }
         if(array[i][j]==White)
        {
             button[i][j].setIcon(Icon2);
             button[i][j].setIconSize(QSize(20,20));
        }
     }
}
void two_player::on_Start_3_clicked()
{
    if(load==false)
    {
    if(ui->radioButton_5->isChecked())
           turn=black;
    else if(ui->radioButton_6->isChecked())
        turn=white;
    }
    ui->Save_3->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->Load_3->setEnabled(false);
    Modify();
    check(turn);
    count_black_white();
    if(turn==black)
        ui->label->setText("Black");
    else
        ui->label->setText("White");
    load=false;
}
void two_player::on_Save_3_clicked()
{
    QString filename=QFileDialog::getSaveFileName(0,"","",tr(".txt"));
    QFile file(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream out(&file);
    QString string;
    if(turn==black)
        out<<"Black"<<endl;
    else
        out<<"White"<<endl;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            string=QString::number(array[i][j]);
            out<<string<<"\t";
          }
        out<<"\n";
}
}

void two_player::on_Load_3_clicked()
{
    load=true;
    QString filename=QFileDialog::getOpenFileName(0,"","",tr(".txt"));
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString string;
    in>>string;
    if(string=="Black")
    {
        turn=black;
    }
    if(string=="White")
        turn=white;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
    {
            in>>array[i][j];
    }
 }
}
void two_player::on_End_3_clicked()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            array[i][j]=0;
    array[3][3]=White;
    array[3][4]=Black;
    array[4][4]=White;
    array[4][3]=Black;
    Modify();
    ui->Load_3->setEnabled(true);
    ui->Save_3->setEnabled(false);
}

void two_player::on_Back_3_clicked()
{
    Othello_game * game=new Othello_game();
    game->user_name(User);;
    game->show();
    this->hide();

}

void two_player::on_pushButton_3_clicked()
{
    click();
}
