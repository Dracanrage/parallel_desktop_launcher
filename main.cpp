#include "pdlauncher.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PDLauncher w;
    w.show();
    return a.exec();
}
