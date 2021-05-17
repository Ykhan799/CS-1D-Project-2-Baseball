#ifndef CUSTOMPATH_H
#define CUSTOMPATH_H
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
#include <queue>
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

private:
    void fillComboBox();
    void fillScrollArea();
    void CheckboxChanged();
    void recursiveStadiumSort(QString current, vector<QString> &selected);
    void createGraph();
    int nextStadium(vector<int> Dist, vector<QString> &selected);
    void createRoute(QString campus);


    Ui::customPath *ui;
    manageDB *database;

    QString startingStadium;
    QVector <QString> selectedCampusNames;
    QVector<QCheckBox*> checkBoxVector;
    QVector <QString> otherStadiumNames;

    //graphHelper<QString> *graphs;
    QString* stad;
    int totalDist;
    queue<QString> route;
    QString finalCampus;
    Graph<QString>* graph;
    vector<QString> nameList;
    vector<QString> tempList;
    vector<QString> selectedList;

};

#endif // CUSTOMPATH_H
