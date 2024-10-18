#include "endpointmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EndpointMainWindow w;
    w.show();
    return a.exec();
}
