#ifndef DODGERPATH_H
#define DODGERPATH_H
#include "souvenirshop.h"
#include "DataBase.h"
#include "manageDB.h"
#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QSqlQueryModel>
#include <QCheckBox>
#include <QLabel>
#include <QSqlQuery>
#include <QMainWindow>

namespace Ui {
class dodgerpath;
}

class dodgerpath : public QMainWindow
{
    Q_OBJECT

public:
    explicit dodgerpath(QWidget *parent = nullptr);
    ~dodgerpath();

private:
    Ui::dodgerpath *ui;
    void fillScrollArea();
    manageDB *database;
    QVector<QCheckBox*> checkBoxVector;
};

#endif // DODGERPATH_H
