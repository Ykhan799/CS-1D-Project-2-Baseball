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
#include "grapher.h"
#include "mainwindow.h"
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

    void on_planTrip_button_clicked();

private:
    Ui::marlinsPath *ui;
    manageDB *database;
    QString *Team;
    QVector<QString> Teams;


    void initalizeMarlinsPath();




    int totalDist;
    QVector<QString> teamNamesVector;

    /**
    */
    QVector<QString> tempTeamNamesVector;

    /**
    */
    QString startTeamName;

    graphAM* dijkstrasChooseTeams;

    QVector<QString> allTeamsList;
};

#endif // MARLINSPATH_H
