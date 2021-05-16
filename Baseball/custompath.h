#ifndef CUSTOMPATH_H
#define CUSTOMPATH_H
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
namespace Ui {
class customPath;
}

class customPath : public QMainWindow
{
    Q_OBJECT

public:
    explicit customPath(QWidget *parent = nullptr);
    ~customPath();

private:
    void fillComboBox();
    void fillScrollArea();
    Ui::customPath *ui;
    manageDB *database;
    QVector<QCheckBox*> checkBoxVector;
};

#endif // CUSTOMPATH_H
