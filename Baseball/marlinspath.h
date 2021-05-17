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
#include "dijkstra.h"
#include <QMainWindow>
#include <souvenirshop.h>
namespace Ui {
class marlinsPath;
}

class marlinsPath : public QMainWindow
{
    Q_OBJECT

public:
    explicit marlinsPath(vector<QString> stadiums, QWidget *parent = nullptr, Graph<QString>* getGraph = nullptr);
    ~marlinsPath();

private slots:
    void on_startTrip_button_clicked();

    void on_backButton_clicked();

private:
    Ui::marlinsPath *ui;
    manageDB *database;
    QString *stadium;
    vector<QString> stadiums;

    QString startingStadium;
    vector <QString> otherStadiumNames;
    void initalizeMarlinsPath();

    void rebuildGraph();

    QVector <QString> orderedStadiumNames;//store sorted stadiums in here

    Graph<QString>* graph;
    vector<QString> nameList;
    vector<QString> tempList;
    vector<QString> selectedList;

};

#endif // MARLINSPATH_H
