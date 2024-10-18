#include "navigationwidget.h"
#include <QLabel>
#include <QGridLayout>

NavigationWidget::NavigationWidget(QWidget *parent)
    : QWidget{parent}
{

    QGridLayout *navigationWidgetLayout = new QGridLayout(this);

    QLabel *label = new QLabel(this);
    label->setText("Navigator");
    navigationWidgetLayout->addWidget(label, 0, 0);

    this->setLayout(navigationWidgetLayout);
}
