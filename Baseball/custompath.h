#ifndef CUSTOMPATH_H
#define CUSTOMPATH_H
#include "souvenirshop.h"
#include "DataBase.h"
#include "manageDB.h"
#include "mainwindow.h"
#include "grapher.h"
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

private slots:
    void on_selectStartingStadiums_activated();

    void on_backButton_clicked();

    void on_planTrip_button_clicked();

    void on_startTrip_button_clicked();

private:


    Ui::customPath *ui;
    manageDB *database;

    void fillComboBox();
    void fillScrollArea();
    void CheckboxChanged();

    QVector<QCheckBox*> checkBoxVector;

    QString startingStadium;

    QVector<QString> teamNamesVector;

    /**
    */
    QVector<QString> tempTeamNamesVector;

    /**
    */
    QString startTeamName;

    graphAM* dijkstrasChooseTeams;

    QVector<QString> allTeamsList;

    double totalDist;

};

#endif // CUSTOMPATH_H
