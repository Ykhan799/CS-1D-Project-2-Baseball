#ifndef CUSTOMPATH_H
#define CUSTOMPATH_H
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


    Ui::customPath *ui;
    manageDB *database;

    QString startingStadium;
    QVector <QString> selectedCampusNames;
    QVector<QCheckBox*> checkBoxVector;
    QVector <QString> otherStadiumNames;

};

#endif // CUSTOMPATH_H
