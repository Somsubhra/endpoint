#include "collectiondatamanager.h"
#include <QSqlDatabase>
#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

#include "collectionmodel.h"

CollectionDataManager::CollectionDataManager(QObject *parent, QWidget *parentWidget)
    : QObject{parent}
{
    this->database = QSqlDatabase::addDatabase("QSQLITE");
    QString homeDir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    QDir homeDirectory(homeDir);

    QString endpointPathString = homeDirectory.filePath(".endpoint");

    if (!homeDirectory.exists(".endpoint")) {
        if (homeDirectory.mkpath(".endpoint")) {
            qDebug() << ".endpoint directory created.";
        } else {
            qDebug() << "Failed to create .endpoint directory.";
        }
    } else {
        qDebug() << ".endpoint directory already exists.";
    }

    QDir endpointPath(endpointPathString);
    QString databasePath = endpointPath.filePath("endpoint.sqlite3");

    this->database.setDatabaseName(databasePath);

    if (!this->database.open()) {
        QMessageBox::critical(parentWidget, tr("Failed to open collections database"), this->database.lastError().text());
    } else {
        QSqlQuery query;
        query.prepare(R"(
            CREATE TABLE IF NOT EXISTS collections (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
                updated_at DATETIME DEFAULT CURRENT_TIMESTAMP
            )
        )");

        if (!query.exec()) {
            qDebug() << "Error creating table:" << query.lastError().text();
        } else {
            qDebug() << "Table created or already exists.";
        }
    }
}

CollectionDataManager::~CollectionDataManager() {
    this->database.close();
}

void CollectionDataManager::insert(CollectionModel *collection) {
    QSqlQuery query;
    query.prepare("INSERT INTO collections (name, created_at, updated_at) VALUES (:name, :createdAt, :updatedAt)");

    query.bindValue(":name", collection->getName());
    query.bindValue(":createdAt", collection->getCreatedAt());
    query.bindValue(":updatedAt", collection->getUpdatedAt());

    if (!query.exec()) {
        qDebug() << "Error inserting collection:" << query.lastError().text();
    } else {
        qDebug() << "Collection inserted successfully.";
    }
}
