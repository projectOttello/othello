#include "single_player.h"
#include "ui_single_player.h"
#include <QMessageBox>
Single_Player::Single_Player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Single_Player)
{
    ui->setupUi(this);
    QPixmap pixmap("icon");
    this->setWindowIcon(pixmap);
    this->setWindowTitle("Single Player");
    size=0;
    Create();
}
Single_Player::~Single_Player()
{
    delete ui;
}
//This function clears the buttons's background and set them again
void Single_Player::Modify()
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
//This function sets the windows title
void Single_Player::user_name(QString username)
{
        User=username;
        this->setWindowTitle(User);
}
//This function check what position it should change
void Single_Player::change_taw(int x, int y,int state)
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
void Single_Player::click()
{
    if(is_in(ui->x->text().toInt(),ui->y->text().toInt())==true)
    {
    if(turn==black)
    {
     set(ui->x->text().toInt(),ui->y->text().toInt(),turn);
     change_taw(ui->x->text().toInt(),ui->y->text().toInt(),Black);
     turn=white;
     Modify();
     check(white);
     if(size>0)
     {
     int x2=rand()%size;
     if(is_in(white_movement[x2][0],white_movement[x2][1]))
         set(white_movement[x2][0],white_movement[x2][1],white);
     else
     {
         QMessageBox *msg=new QMessageBox();
         msg->setText("Illegal movement");
         msg->show();
     }
     change_taw(white_movement[x2][0],white_movement[x2][1],White);
     }
     turn=black;
     Modify();
     check(black);
     ui->label->setText("Black");
    }
    else if(turn==white)
    {
     set(ui->x->text().toInt(),ui->y->text().toInt(),turn);
     change_taw(ui->x->text().toInt(),ui->y->text().toInt(),White);
     turn=black;
     Modify();
     check(black);
     if(size>0)
     {
     int x2=rand()%size;
     if(is_in(black_movement[x2][0],black_movement[x2][1]))
         set(black_movement[x2][0],black_movement[x2][1],black);
     else
     {
         QMessageBox *msg=new QMessageBox();
         msg->setText("Illegal movement");
         msg->show();
     }
     change_taw(black_movement[x2][0],black_movement[x2][1],Black);
     }
     turn=white;
     Modify();
     check(white);
     ui->label->setText("White");
    }
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
        ui->pushButton->setEnabled(false);
    }
}
void Single_Player::Create()
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

//This function start the game
void Single_Player::on_Start_clicked()
{
    //If it is not loaded from a file it ask user to set his color
    if(load==false)
    {
    if(ui->radioButton->isChecked())
           turn=black;
    else if(ui->radioButton_2->isChecked())
        turn=
                white;
    }
    ui->Save->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->Load->setEnabled(false);
    Modify();
    check(turn);
    count_black_white();
    if(turn==black)
        ui->label->setText("Black");
    else
        ui->label->setText("White");
    load=false;
}

bool Single_Player::count_black_white()
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


void Single_Player::on_pushButton_clicked()
{
       click();
}
//This function load the game   from a txt file
void Single_Player::on_Load_clicked()
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
//This function save the game and save it in a txt file
void Single_Player::on_Save_clicked()
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
//This function restart the game
void Single_Player::on_End_clicked()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            array[i][j]=0;
    array[3][3]=White;
    array[3][4]=Black;
    array[4][4]=White;
    array[4][3]=Black;
    Modify();
    ui->Load->setEnabled(true);
    ui->Save->setEnabled(false);
}
//This function return the game to the previous page
void Single_Player::on_Back_clicked()
{
    Othello_game * game=new Othello_game();
    game->user_name(User);;
    game->show();
    this->hide();
}
