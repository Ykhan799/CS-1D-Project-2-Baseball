#ifndef ORDEREDPATH_H
#define ORDEREDPATH_H

#include <QMainWindow>
#include "mainwindow.h"
namespace Ui {
class orderedPath;
}

class orderedPath : public QMainWindow
{
    Q_OBJECT

public:
    explicit orderedPath(QWidget *parent = nullptr);
    ~orderedPath();

private slots:
    void on_planTrip_button_2_clicked();


    void on_startTrip_button_clicked();



    void on_backButton_clicked();

private:
    Ui::orderedPath *ui;

    void fillComboBox();
    manageDB *database;

    int totalDist;
    QString startingStadium;
    QVector <QString> selectedCampusNames;
    QVector<QCheckBox*> checkBoxVector;
    QVector <QString> otherStadiumNames;
    QVector<QString> teamNamesVector;

    /**
    */
    QVector<QString> tempTeamNamesVector;

    /**
    */
    QString startTeamName;

    graphHELPER* chooseOrder;

    QVector<QString> customTeamNameList;

    QVector<QString> fastestRoute;

    QVector<QString> inputValues;

    bool CTOstartButtonClicked;

    int counter = 0;

};

#endif // ORDEREDPATH_H
