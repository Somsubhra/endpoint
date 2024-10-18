#include "viewportwidget.h"
#include <QLabel>
#include <QGridLayout>

ViewportWidget::ViewportWidget(QWidget *parent)
    : QWidget{parent}
{
    QGridLayout *navigationWidgetLayout = new QGridLayout(this);

    QLabel *label = new QLabel(this);
    label->setText("Viewport");
    navigationWidgetLayout->addWidget(label, 0, 0);

    this->setLayout(navigationWidgetLayout);
}
