#ifndef SOUVENIRSHOP_H
#define SOUVENIRSHOP_H

#include <QWidget>
#include <QVector>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QMessageBox>
#include "DataBase.h"
#include "manageDB.h"
#include "tripsummary.h"
namespace Ui {
class souvenirshop;
}

class souvenirshop : public QMainWindow
{
    Q_OBJECT

public:


    explicit souvenirshop(double distance, QVector<QString> stadiumVector, QWidget *parent = nullptr);
    ~souvenirshop();

private slots:
    void on_buy_button_clicked();

    void on_souvenir_tableView_clicked(const QModelIndex &index);

    void on_nextCollege_button_clicked();

    void on_endTour_button_clicked();

private:
    Ui::souvenirshop *ui;
    double distanceTraveled = 0;

    /**
    * @brief total cost for trip
    */
    double grandTotal = 0;

    /**
    * @brief count to keep track of stadiums
    */
    int stadiumCount = 0;

    /**
    * @brief number of souvenirs purchased at current Stadium
    */
    int purchasedSouvAtStadium = 0;

    /**
    * @brief cost at current Stadium
    */
    double subCostAtStadium = 0;

    /**
    * @brief List to hold costs from each Stadium
    */
    QStringList subCostList;

    /**
    * @brief QVector of selected stadium names
    */
    QVector<QString> selectedStadiums;

    /**
    * @brief temporarily holds name of a souvenir
    */
    QString tempSouvenir;

    /**
    * @brief cost of souvenir(string)
    */
    QString cost;

    /**
    * @brief cost of souvenir(double)
    */
    double souvenirCost;

    /**
    * @brief Amount of souvenirs purchased in total
    */
    int souvenirAmount;

    /**
    * @brief Used to manage widgets
    */
    QVBoxLayout *vBoxLayout;

    /**
    * @brief Container for output
    */
    QWidget *container;

    /**
    * @brief Variable to check if souvenir has been clicked
    */
    bool clicked = false;

    /**
    * @brief custom amount of souvenirs to be purchased
    */
    int customAmount = 0;
};

#endif // SOUVENIRSHOP_H
