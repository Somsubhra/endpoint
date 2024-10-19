#include "navigationwidget.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QStringListModel>

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

    this->collectionsListView = new QListView(this);
    this->collectionList = new QStringListModel(this->collectionsListView);
    this->collectionsListView->setModel(this->collectionList);
    navigationWidgetLayout->addWidget(this->collectionsListView, 3, 0);

    this->setLayout(navigationWidgetLayout);    

    connect(this->createCollectionButton, &QPushButton::clicked, this, &NavigationWidget::handleCreateCollectionButtonClicked);
}

NavigationWidget::~NavigationWidget() {
    delete this->createCollectionButton;
    delete this->createCollectionInput;
    delete this->collectionList;
    delete this->collectionsListView;
}

void NavigationWidget::handleCreateCollectionButtonClicked() {
    QString newCollectionName = this->createCollectionInput->text();

    if (newCollectionName.isEmpty()) {
        return;
    }

    QStringList currentCollections = this->collectionList->stringList();
    currentCollections.append(newCollectionName);
    this->collectionList->setStringList(currentCollections);
}
