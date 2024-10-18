#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class NavigationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationWidget(QWidget *parent = nullptr);
    ~NavigationWidget();

private:
    QPushButton *createCollectionButton;
    QLineEdit *createCollectionInput;

signals:
};

#endif // NAVIGATIONWIDGET_H
