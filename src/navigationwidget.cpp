#include "navigationwidget.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QStringListModel>
#include <QMessageBox>

NavigationWidget::NavigationWidget(QWidget *parent)
    : QWidget{parent}
{

    QGridLayout *navigationWidgetLayout = new QGridLayout(this);

    QLabel *collectionsLabel = new QLabel(this);
    collectionsLabel->setAlignment(Qt::AlignCenter);
    collectionsLabel->setText(tr("Collections"));
    navigationWidgetLayout->addWidget(collectionsLabel, 0, 0);

    this->createCollectionInput = new QLineEdit(this);
    this->createCollectionInput->setPlaceholderText(tr("Collection Name"));
    navigationWidgetLayout->addWidget(this->createCollectionInput, 1, 0);

    this->createCollectionButton = new QPushButton(this);
    this->createCollectionButton->setText(tr("Add New Collection"));
    navigationWidgetLayout->addWidget(this->createCollectionButton, 2, 0);

    this->collectionsListView = new QListView(this);
    this->collectionsList = new QStringListModel(this->collectionsListView);
    this->collectionsListView->setModel(this->collectionsList);
    navigationWidgetLayout->addWidget(this->collectionsListView, 3, 0);

    QLabel *endpointsLabel = new QLabel(this);
    endpointsLabel->setAlignment(Qt::AlignCenter);
    endpointsLabel->setText(tr("Endpoints"));
    navigationWidgetLayout->addWidget(endpointsLabel, 4, 0);

    this->createEndpointInput = new QLineEdit(this);
    this->createEndpointInput->setPlaceholderText(tr("Endpoint Name"));
    navigationWidgetLayout->addWidget(this->createEndpointInput, 5, 0);

    this->createEndpointButton = new QPushButton(this);
    this->createEndpointButton->setText(tr("Add New Endpoint"));
    navigationWidgetLayout->addWidget(this->createEndpointButton, 6, 0);

    this->endpointsListView = new QListView(this);
    this->endpointsList = new QStringListModel(this->endpointsListView);
    this->endpointsListView->setModel(this->endpointsList);
    navigationWidgetLayout->addWidget(this->endpointsListView, 7, 0);

    this->setLayout(navigationWidgetLayout);    

    connect(this->createCollectionButton, &QPushButton::clicked, this, &NavigationWidget::handleCreateCollectionButtonClicked);
    connect(this->createEndpointButton, &QPushButton::clicked, this, &NavigationWidget::handleCreateEndpointButtonClicked);
}

NavigationWidget::~NavigationWidget() {
    delete this->createCollectionButton;
    delete this->createCollectionInput;
    delete this->collectionsList;
    delete this->collectionsListView;
}

void NavigationWidget::handleCreateCollectionButtonClicked() {
    QString newCollectionName = this->createCollectionInput->text();

    if (newCollectionName.isEmpty()) {
        return;
    }

    QStringList currentCollections = this->collectionsList->stringList();
    currentCollections.append(newCollectionName);
    this->collectionsList->setStringList(currentCollections);
}

void NavigationWidget::handleCreateEndpointButtonClicked() {
    QString newEndpointName = this->createEndpointInput->text();

    if (newEndpointName.isEmpty()) {
        return;
    }

    if (!this->collectionsListView->selectionModel()->hasSelection()) {
        QMessageBox::information(this, tr("Collection not selected"), tr("You must select a collection in order to create an endpoint"));
        return;
    }

    QStringList currentEndpoints = this->endpointsList->stringList();
    currentEndpoints.append(newEndpointName);
    this->endpointsList->setStringList(currentEndpoints);
}
