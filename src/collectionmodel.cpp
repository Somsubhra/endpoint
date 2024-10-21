#include "collectionmodel.h"
#include <QDateTime>

CollectionModel::CollectionModel(QObject *parent, QString name)
    : QObject{parent}
{
    this->name = name;
    this->createdAt = QDateTime::currentDateTime();
    this->updatedAt = QDateTime::currentDateTime();
}

QString CollectionModel::getName() {
    return this->name;
}

QDateTime CollectionModel::getCreatedAt() {
    return this->createdAt;
}

QDateTime CollectionModel::getUpdatedAt() {
    return this->updatedAt;
}
