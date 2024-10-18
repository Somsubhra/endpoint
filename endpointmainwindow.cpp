#include "endpointmainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "endpointmainwidget.h"

EndpointMainWindow::EndpointMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    EndpointMainWidget *endpointWidget = new EndpointMainWidget(this);
    this->setCentralWidget(endpointWidget);
    this->showMaximized();
    this->setWindowTitle("Endpoint");
}

EndpointMainWindow::~EndpointMainWindow() {}
