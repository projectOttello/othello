#include "base_class.h"

Base_Class::Base_Class()
{
    size=0;
    load=false;
}

void Base_Class::Check_West(int i, int j, int state)
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
void Base_Class::Check_East(int i, int j, int state)
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
void Base_Class::Check_North(int i, int j, int state)
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
void Base_Class::Check_South(int i, int j, int state)
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
void Base_Class::Check_North_West(int i, int j, int state)
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
void Base_Class::Check_North_East(int i, int j, int state)
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
void Base_Class::Check_South_East(int i, int j, int state)
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
void Base_Class::Check_South_West(int i, int j, int state)
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
void Base_Class::Check_White(int i,int j)
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
void Base_Class::Check_Black(int i,int j)
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
bool Base_Class::check(bool in)
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

void Base_Class::click()
{
    return;
}
bool Base_Class::finish()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if(array[i][j]!=Black && array[i][j]!=White)
                return false;
        }
    return true;
}
bool Base_Class::is_in(int x, int y)
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

//This function change the array value when you select a place and change its background
void Base_Class::set(int x, int y,bool in)
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

//This function counts numbers of white and black numbers

