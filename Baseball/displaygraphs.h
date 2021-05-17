#ifndef DISPLAYGRAPHS_H
#define DISPLAYGRAPHS_H

#include <QMainWindow>
#include "dijkstra.h"
#include "manageDB.h"
#include <QMessageBox>
#include <QWidget>
#include <QDebug>
#include <QSqlQueryModel>
#include <QCheckBox>
#include <QLabel>
#include <QSqlQuery>
#include <QVBoxLayout>

namespace Ui {
class displayGraphs;
}

class displayGraphs : public QMainWindow
{
    Q_OBJECT

public:
    explicit displayGraphs(vector<QString> stadiums, QWidget *parent = nullptr, Graph<QString> *getGraph = nullptr);
    ~displayGraphs();

private slots:
    void on_backButton_clicked();

    void on_DFSButton_clicked();

    void on_MSTButton_clicked();

    void on_BFSButton_clicked();

private:
    Ui::displayGraphs *ui;


    void rebuildGraph();
    manageDB* data;

   Graph<QString> *graphs;
    vector<QString> nameList;
    vector<QString> tempList;
    vector<QString> selectedList;
};

#endif // DISPLAYGRAPHS_H
