#ifndef DODGERPATH_H
#define DODGERPATH_H
#include "souvenirshop.h"
#include "DataBase.h"
#include "manageDB.h"
#include "dijkstra.h"
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

private slots:
    void on_backButton_clicked();

    void on_planTrip_button_clicked();

private:
    Ui::dodgerpath *ui;
    void fillScrollArea();
    void CheckboxChanged();
    manageDB *database;

    QString startingStadium;
    QVector <QString> selectedCampusNames;
    QVector<QCheckBox*> checkBoxVector;
    QVector <QString> otherStadiumNames;

    QVector <QString> orderedStadiumNames;//store sorted stadiums in here
};

#endif // DODGERPATH_H
