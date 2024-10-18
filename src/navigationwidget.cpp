#include "navigationwidget.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

NavigationWidget::NavigationWidget(QWidget *parent)
    : QWidget{parent}
{

    QGridLayout *navigationWidgetLayout = new QGridLayout(this);

    QLabel *label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->setText("Collections");
    navigationWidgetLayout->addWidget(label, 0, 0);

    this->createCollectionInput = new QLineEdit(this);
    this->createCollectionInput->setPlaceholderText("Collection Name");
    navigationWidgetLayout->addWidget(this->createCollectionInput, 1, 0);

    this->createCollectionButton = new QPushButton(this);
    this->createCollectionButton->setText("Add New Collection");
    navigationWidgetLayout->addWidget(this->createCollectionButton, 2, 0);

    this->setLayout(navigationWidgetLayout);
}

NavigationWidget::~NavigationWidget() {
    delete this->createCollectionButton;
    delete this->createCollectionInput;
}
