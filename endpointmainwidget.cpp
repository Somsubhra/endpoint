#include "endpointmainwidget.h"
#include <QGridLayout>
#include <QPushButton>
#include "navigationwidget.h"
#include "viewportwidget.h"

EndpointMainWidget::EndpointMainWidget(QWidget *parent)
    : QWidget{parent}
{
    QGridLayout *mainLayout = new QGridLayout(this);


    NavigationWidget *navigationWidget = new NavigationWidget(this);
    mainLayout->addWidget(navigationWidget, 0, 0);
    mainLayout->setColumnStretch(0, 1);

    ViewportWidget *viewportWidget = new ViewportWidget(this);
    mainLayout->addWidget(viewportWidget, 0, 1);
    mainLayout->setColumnStretch(1, 2);
}
