#ifndef COLLECTIONDATAMANAGER_H
#define COLLECTIONDATAMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QWidget>

#include "collectionmodel.h"

class CollectionDataManager : public QObject
{
    Q_OBJECT
public:
    explicit CollectionDataManager(QObject *parent = nullptr, QWidget *parentWidget = nullptr);
    ~CollectionDataManager();

    void insert(CollectionModel *collection);

private:
    QSqlDatabase database;

signals:
};

#endif // COLLECTIONDATAMANAGER_H
