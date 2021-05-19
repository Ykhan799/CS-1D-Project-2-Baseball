#ifndef STARTTOENDPATH_H
#define STARTTOENDPATH_H
#include "souvenirshop.h"
#include "DataBase.h"
#include "manageDB.h"
#include "dijkstra.h"
#include "grapher.h"
#include "mainwindow.h"
#include "grapher.h"
#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QSqlQueryModel>
#include <QCheckBox>
#include <QLabel>
#include <QSqlQuery>
#include <QMainWindow>
#include <QFileInfo>
#include <QDir>
namespace Ui {
class dodgerpath;
}

class dodgerpath : public QMainWindow
{
    Q_OBJECT

public:
    explicit dodgerpath(QVector<QString> stadiums, QWidget *parent = nullptr, Graph<QString>* getGraph = nullptr);
    ~dodgerpath();

private slots:
    void on_backButton_clicked();

    void on_planTrip_button_clicked();

private:
    Ui::dodgerpath *ui;
    void fillScrollArea();
    void CheckboxChanged();
    manageDB *database;

    QVector<QCheckBox*> checkBoxVector;

    QVector <QString> orderedStadiums;

    QString *stadium;
    QVector<QString> stadiums;


    bool SSRstartClicked;
    void initalizeDodgerPath();
    void rebuildGraph();
    void fillComboBox();
    Graph<QString>* graph;
    QVector<QString> nameList;
    QVector<QString> tempList;
    QVector<QString> selectedList;


    int totalDist;

    graphAM* graphAdjMatr;


    graphAM* dijkstras;



    graphAM* chooseOrder;


};

#endif // STARTTOENDPATH_H
