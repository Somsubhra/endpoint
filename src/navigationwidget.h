#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QStringListModel>
#include "collectiondatamanager.h"

class NavigationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationWidget(QWidget *parent = nullptr);
    ~NavigationWidget();

private:
    QPushButton *createCollectionButton;
    QLineEdit *createCollectionInput;
    QListView *collectionsListView;
    QStringListModel *collectionsList;

    QLineEdit *createEndpointInput;
    QPushButton *createEndpointButton;
    QListView *endpointsListView;
    QStringListModel *endpointsList;

    CollectionDataManager *collectionDataManager;

    void setupUI();

private slots:
    void handleCreateCollectionButtonClicked();
    void handleCreateEndpointButtonClicked();

signals:
};

#endif // NAVIGATIONWIDGET_H
