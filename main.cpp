#include "convertisseurtemp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConvertisseurTemp w;
    w.show();
    return a.exec();
}
