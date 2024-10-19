#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QStringListModel>

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
    QStringListModel *collectionList;

private slots:
    void handleCreateCollectionButtonClicked();

signals:
};

#endif // NAVIGATIONWIDGET_H
