#ifndef TRIPSUMMARY_H
#define TRIPSUMMARY_H


#include <QWidget>
#include "QVBoxLayout"
#include <QLabel>
#include "grapher.h"
namespace Ui {
class tripSummary;
}

class tripSummary : public QWidget
{
    Q_OBJECT

public:
    /**
    * @brief explicit Constructor
    *
    * Constructor intializes UI for tripSummary
    *
    * @param *parent - for QDialog
    * @param totalDistance - total distance traveled
    * @param totalCost - total amount spent
    * @param stadiumNames - names of all Stadiumes visited
    * @param costAtEachStadium - total spent at each Stadium
    */
    explicit tripSummary(QString totalDistance, QString totalCost, QVector<QString> stadiumNames,
                     QStringList costAtEachStadium,QWidget *parent = nullptr);

    /**
    * @brief Destructor
    *
    * Close the tripSummary UI
    */
    ~tripSummary();

private slots:
    /**
    * @brief Button Method to close tripSummary window
    *
    * closes tripSummary window
    */
    void on_done_button_clicked();

private:
    graphAM* convert;
    /**
    * @brief points to tripSummary UI
    */
    Ui::tripSummary *ui;

    /**
    * @brief temp label for stadium name
    */
    QLabel *stadiumLabel;

    /**
    * @brief vector to hold labels of all stadium names
    */
    QVector<QLabel*> labelVector;
};

#endif // TRIPSUMMARY_H
