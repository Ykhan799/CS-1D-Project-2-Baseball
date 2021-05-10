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

namespace Ui {
class souvenirshop;
}

class souvenirshop : public QMainWindow
{
    Q_OBJECT

public:
    explicit souvenirshop(QWidget *parent = nullptr);
    ~souvenirshop();

    explicit souvenirshop(double distance, QVector<QString> stadiumVector, QWidget *parent = nullptr);
    ~souvenirshop();

private:
    Ui::souvenirshop *ui;
    double distanceTraveled = 0;

    /**
    * @brief total cost for trip
    */
    double grandTotal = 0;

    /**
    * @brief count to keep track of colleges
    */
    int collegeCount = 0;

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
    * @brief vector of selected college names
    */
    QVector<QString> selectedColleges;

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
