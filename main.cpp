#include "cutemon.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CuteMon w;
    w.show();
    return a.exec();
}
