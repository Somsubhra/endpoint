#ifndef COLLECTIONMODEL_H
#define COLLECTIONMODEL_H

#include <QObject>
#include <QString>
#include <QDateTime>

class CollectionModel : public QObject
{
    Q_OBJECT
public:
    explicit CollectionModel(QObject *parent = nullptr, QString name = "");

    QString getName();
    QDateTime getCreatedAt();
    QDateTime getUpdatedAt();

private:
    QString name;
    QDateTime createdAt;
    QDateTime updatedAt;

signals:
};

#endif // COLLECTIONMODEL_H
