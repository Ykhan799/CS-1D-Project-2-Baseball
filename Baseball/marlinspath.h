#ifndef MARLINSPATH_H
#define MARLINSPATH_H
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
#include <souvenirshop.h>
namespace Ui {
class marlinsPath;
}

class marlinsPath : public QMainWindow
{
    Q_OBJECT

public:
    explicit marlinsPath(QWidget *parent = nullptr);
    ~marlinsPath();

private slots:
    void on_startTrip_button_clicked();

    void on_backButton_clicked();

private:
    Ui::marlinsPath *ui;
    manageDB *database;

    QString startingStadium;
    QVector <QString> otherStadiumNames;
    void initalizeMarlinsPath();

    QVector <QString> orderedStadiumNames;//store sorted stadiums in here

};

#endif // MARLINSPATH_H
