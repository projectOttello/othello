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
    load=false;
    Create();
}
Single_Player::~Single_Player()
{
    delete ui;
}
void Single_Player::set(int x, int y,bool in)
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
void Single_Player::Check_West(int i, int j, int state)
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
             //2khone vase meghdar
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
void Single_Player::Check_East(int i, int j, int state)
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
void Single_Player::Check_North(int i, int j, int state)
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
void Single_Player::Check_South(int i, int j, int state)
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
void Single_Player::Check_North_West(int i, int j, int state)
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
void Single_Player::Check_North_East(int i, int j, int state)
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
void Single_Player::Check_South_East(int i, int j, int state)
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
void Single_Player::Check_South_West(int i, int j, int state)
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
