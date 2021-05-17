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



private:
    Ui::orderedPath *ui;

    void fillComboBox();
    manageDB *database;

    QString startingStadium;
    QVector <QString> selectedCampusNames;
    QVector<QCheckBox*> checkBoxVector;
    QVector <QString> otherStadiumNames;

};

#endif // ORDEREDPATH_H
