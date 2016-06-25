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
    load=false;
    Create();
}
two_player::~two_player()
{
    delete ui;
}
void two_player::set(int x, int y,bool in)
{
  if(in==white)
   {
    array[x][y]=White;
    QPixmap pixmap2("white-circle");
    QIcon Icon2(pixmap2);
    button[x][y].setIcon(Icon2);
    button[x][y].setIconSize(QSize(20,20));
    }
    else if (in==black)
    {
        array[x][y]=Black;
        QPixmap pixmap1("Black_Circle");
        QIcon Icon1(pixmap1);
        button[x][y].setIcon(Icon1);
        button[x][y].setIconSize(QSize(20,20));
    }
}
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
void two_player::Check_West(int i, int j, int state)
{
    QPixmap pixmap("blue-circle");
    QIcon Icon (pixmap);
     for(int j2=j-2;j2>=0;j2--)
      {
         if(array[i][j2+1]==state)
         {
             for(int j3=j-1;j3>j2;j3--)
                 if(array[i][j3]!=state)
                     return;
             if (array[i][j2]!=Black && array[i][j2]!=White)
             {
             button[i][j2].setIcon(Icon);
             button[i][j2].setIconSize(QSize(20,20));
             if(turn==white)
               {
                 white_movement[size][0]=i;
                 white_movement[size][1]=j2;
             }
             if(turn==black)
             {
                 black_movement[size][0]=i;
                 black_movement[size][1]=j2;
             }
             size++;
             return;
            }
          }
     }
}
void two_player::Check_East(int i, int j, int state)
{
    QPixmap pixmap("blue-circle");
    QIcon Icon (pixmap);
     for(int j2=j+2;j2<=7;j2++)
      {
         if(array[i][j2-1]==state)
         {
             for(int j3=j+1;j3<j2;j3++)
                 if(array[i][j3]!=state)
                     return;
             if (array[i][j2]!=Black && array[i][j2]!=White)
             {
             button[i][j2].setIcon(Icon);
             button[i][j2].setIconSize(QSize(20,20));
             if(turn==white)
               {
                 white_movement[size][0]=i;
                 white_movement[size][1]=j2;
             }
             if(turn==black)
             {
                 black_movement[size][0]=i;
                 black_movement[size][1]=j2;
             }
             size++;
             return;
         }
         }
     }
}
void two_player::Check_North(int i, int j, int state)
{
    QPixmap pixmap("blue-circle");
    QIcon Icon (pixmap);
   for(int i2=i-2;i2>=0;i2--)
      {
        if(array[i2+1][j]==state)
                {
            for(int i3=i-1;i3>i2;i3--)
                if(array[i3][j]!=state)
                    return;
                 if (array[i2][j]!=Black && array[i2][j]!=White)
                   {
                    button[i2][j].setIcon(Icon);
                    button[i2][j].setIconSize(QSize(20,20));
                    if(turn==white)
                      {
                        white_movement[size][0]=i2;
                        white_movement[size][1]=j;
                    }
                    if(turn==black)
                    {
                        black_movement[size][0]=i2;
                        black_movement[size][1]=j;
                    }
                    size++;
                    return;
                 }
                }
   }
}
void two_player::Check_South(int i, int j, int state)
{
   QPixmap pixmap("blue-circle");
   QIcon Icon (pixmap);
   for(int i2=i+2;i2<=07;i2++)
      {
        if(array[i2-1][j]==state)
                {
            for(int i3=i+1;i3<i2;i3++)
                if(array[i3][j]!=state)
                    return;
            if (array[i2][j]!=Black && array[i2][j]!=White)
            {
                    button[i2][j].setIcon(Icon);
                    button[i2][j].setIconSize(QSize(20,20));
                    if(turn==white)
                      {
                        white_movement[size][0]=i2;
                        white_movement[size][1]=j;
                    }
                    if(turn==black)
                    {
                        black_movement[size][0]=i2;
                        black_movement[size][1]=j;
                    }
                    size++;
                    return;
             }
        }
   }
}
void two_player::Check_North_West(int i, int j, int state)
{
    QPixmap pixmap("blue-circle");
    QIcon Icon (pixmap);
    int j2=j-2;
    for(int i2=i-2;i2>=0 && j2>=0;i2--)
       {

         if(array[i2+1][j2+1]==state)
                 {
             int i3=i-1;
             for(int j3=j-1;j3>j2 && i3>i2;j3--)
            {
                 i3--;
                if(array[i3][j3]!=state)
                     return;
             }
                     if (array[i2][j2]!=Black && array[i2][j2]!=White)
                     {
                     button[i2][j2].setIcon(Icon);
                     button[i2][j2].setIconSize(QSize(20,20));
                     if(turn==white)
                       {
                         white_movement[size][0]=i;
                         white_movement[size][1]=j2;
                     }
                     if(turn==black)
                     {
                         black_movement[size][0]=i;
                         black_movement[size][1]=j2;
                     }
                     size++;
                     return;
                     }
                 }
         j2--;
    }
}
void two_player::Check_North_East(int i, int j, int state)
{
    QPixmap pixmap("blue-circle");
    QIcon Icon (pixmap);
    int j2=j+2;
   for(int i2=i-2;i2>=0 && j2<=7;i2--)
      {
        if(array[i2+1][j2-1]==state)
                {
            int i3=i-1;
            for(int j3=j+1;j3<j2 && i3>i2;j3++)
           {
                i3--;
               if(array[i3][j3]!=state)
                    return;
            }
            if (array[i2][j2]!=Black && array[i2][j2]!=White)
            {
                    button[i2][j2].setIcon(Icon);
                    button[i2][j2].setIconSize(QSize(20,20));
                    if(turn==white)
                      {
                        white_movement[size][0]=i;
                        white_movement[size][1]=j2;
                    }
                    if(turn==black)
                    {
                        black_movement[size][0]=i;
                        black_movement[size][1]=j2;
                    }
                    size++;
                    return;
            }
            }
        j2++;
   }

}
void two_player::Check_South_East(int i, int j, int state)
{
    QPixmap pixmap("blue-circle");
     QIcon Icon (pixmap);
     int j2=j+2;
    for(int i2=i+2;i2<=7 && j2<=7;i2++)
       {
         if(array[i2-1][j2-1]==state)
                 {
             int i3=i+1;
             for(int j3=j+1;j3<j2 && i3<i2;j3++)
            {
                 i3++;
                if(array[i3][j3]!=state)
                     return;
             }
             if (array[i2][j2]!=Black && array[i2][j2]!=White)
             {
                     button[i2][j2].setIcon(Icon);
                     button[i2][j2].setIconSize(QSize(20,20));
                     if(turn==white)
                       {
                         white_movement[size][0]=i;
                         white_movement[size][1]=j2;
                     }
                     if(turn==black)
                     {
                         black_movement[size][0]=i;
                         black_movement[size][1]=j2;
                     }
                     size++;
                     return;
             }
             }
         j2++;
    }
}
void two_player::Check_South_West(int i, int j, int state)
{
    QPixmap pixmap("blue-circle");
    QIcon Icon (pixmap);
    int j2=j-2;
   for(int i2=i+2;i2<=7 && j2>=0;i2++)
      {
        if(array[i2-1][j2+1]==state)
                {
            int i3=i+1;
            for(int j3=j-1;j3>j2 && i3<i2;j3--)
           {
                i3++;
               if(array[i3][j3]!=state)
                    return;
            }
            if (array[i2][j2]!=Black && array[i2][j2]!=White)
            {
                    button[i2][j2].setIcon(Icon);
                    button[i2][j2].setIconSize(QSize(20,20));
                    if(turn==white)
                      {
                        white_movement[size][0]=i;
                        white_movement[size][1]=j2;
                    }
                    if(turn==black)
                    {
                        black_movement[size][0]=i;
                        black_movement[size][1]=j2;
                    }
                    size++;
                    return;
            }
            }
        j2--;
   }
}
void two_player::Check_White(int i,int j)
{
    Check_West(i,j,White);
    Check_North_West(i,j,White);
    Check_North(i,j,White);
    Check_North_East(i,j,White);
    Check_East(i,j,White);
    Check_South_East(i,j,White);
    Check_South(i,j,White);
    Check_South_West(i,j,White);
}
void two_player::Check_Black(int i,int j)
{
      Check_West(i,j,Black);
      Check_North_West(i,j,Black);
      Check_North(i,j,Black);
      Check_North_East(i,j,Black);
      Check_East(i,j,Black);
      Check_South_East(i,j,Black);
      Check_South(i,j,Black);
      Check_South_West(i,j,Black);
}
void two_player::user_name(QString username)
{
        User=username;
        this->setWindowTitle(User);
}
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
bool two_player::check(bool in)
{
    if(in==black)
    {
        size=0;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            {
                if(array[i][j]==Black)
                    Check_White(i,j);
             }
    }
    else if (in==white)
    {
        size=0;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            {
                if(array[i][j]==White)
                    Check_Black(i,j);
             }
    }
}
bool two_player::is_in(int x, int y)
{
    for(int i=0;i<size;i++)
    {
        if(turn==white)
        {
            if(white_movement[i][0]==x && white_movement[i][1]==y)
                return true;
        }
        if(turn==black)
        {
            if(black_movement[i][0]==x && black_movement[i][1]==y)
                return true;
        }
    }
    return false;
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
bool two_player::finish()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if(array[i][j]!=Black && array[i][j]!=White)
                return false;
        }
    return true;
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
