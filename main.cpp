#include "dialog.h"
#include "start_window.h"
#include "single_player.h"
#include "two_player.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     Start_Window start;
     start.show();

    return a.exec();
}
