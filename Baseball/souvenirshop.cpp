#include "souvenirshop.h"
#include "ui_souvenirshop.h"


souvenirshop::souvenirshop(double distance, QVector<QString> stadiumVector, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::souvenirshop)
{
    ui->setupUi(this);

    ui->label_collegeName->setText(stadiumVector[stadiumCount]);
    distanceTraveled = distance;
    selectedStadiums = stadiumVector;

    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT Souvenir,Price FROM SOUVENIRS WHERE Stadium = :stadiums");
    qry->bindValue(":stadiums", selectedStadiums[stadiumCount]);

    if(qry->exec())
    {
        qDebug() << "Souvenirs updated";
    }
    else
        qDebug() << "nowork";

    model->setQuery(*qry);

    ui->souvenir_tableView->setModel(model);
    ui->souvenir_tableView->setColumnWidth(0, 195);

    //initliazing purchased souvenirs scroll Area

    container = new QWidget;
    vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea_purchased->setWidget(container);

    stadiumCount++;
}

souvenirshop::~souvenirshop()
{
    delete ui;
}

void souvenirshop::on_buy_button_clicked()
{
    if (clicked){
        customAmount =  ui->customInput->value();

        ui->customInput->setValue(1);

        for (int i = 0; i<customAmount; i++){
            grandTotal = grandTotal + souvenirCost;
            purchasedSouvAtStadium++;
            subCostAtStadium += souvenirCost;
        }

        QString customAmountStr = QString::number(customAmount);
        QString customItemPrice = QString::number(souvenirCost*customAmount);

        QString space = "";
        QString space2 = "";

        for (int i = 0; i<27-tempSouvenir.length(); i++)
            space = space + " ";

        for (int i = 0; i<8-customItemPrice.length(); i++)
            space2 = space2 + " ";

        QLabel *souvenirName = new QLabel(customAmountStr + " x\t"+ tempSouvenir  +  space + "$" + space2 + customItemPrice);

        vBoxLayout->addWidget(souvenirName);


        ui->label_souv->setText("Souvenirs Purchased Here: " + QVariant(purchasedSouvAtStadium).toString());
        ui->label_souv->setStyleSheet("QLabel { background-color : black; color : white; }");
        ui->label_souvCosts->setText("Cost of Souvenirs Purchased Here: $" + QString::number(subCostAtStadium, 'f', 2));
        ui->label_souvCosts->setStyleSheet("QLabel { background-color : black; color : white; }");

    }
    else
    {
        QMessageBox::information(this, "Warning", "No Souvenir Selected");
    }
}

void souvenirshop::on_souvenir_tableView_clicked(const QModelIndex &index)
{
    clicked = true;

    if(index.isValid())
    {
        int row = index.row();
        tempSouvenir = index.sibling(row, 0).data().toString();
        souvenirCost = index.sibling(row, 1).data().toString().replace("$", "").toDouble();
        cost = index.sibling(row, 1).data().toString();

        qDebug() << tempSouvenir << Qt::endl << souvenirCost << Qt::endl;
    }
}

void souvenirshop::on_nextCollege_button_clicked()
{
    clicked = false;
    subCostList.append(QString::number(subCostAtStadium,'f', 2)); //adding subcost to list as a string

    if(stadiumCount < selectedStadiums.size())
    {
        ui->label_collegeName->setText(selectedStadiums[stadiumCount]);

        QSqlQueryModel* model=new QSqlQueryModel();

        QSqlQuery* qry=new QSqlQuery();

        qry->prepare("SELECT Souvenir, Price FROM SOUVENIRS WHERE Stadium= (:stadiums)");
        qry->bindValue(":stadiums", selectedStadiums[stadiumCount]);

        if(qry->exec())
        {
            qDebug() << "Souvenirs updated";
        }
        else
            qDebug() << "no work";

        model->setQuery(*qry);

        ui->souvenir_tableView->setModel(model);
        ui->souvenir_tableView->setColumnWidth(0, 195);

        purchasedSouvAtStadium = 0; //reseting num of souvenirs bought at each campus
        ui->label_souv->setText("Souvenirs Purchased Here: " + QVariant(purchasedSouvAtStadium).toString());
        subCostAtStadium= 0; //reseting cost of souvenirs bought at each campus
        ui->label_souvCosts->setText("Cost of Souvenirs Purchased Here: $" + QString::number(subCostAtStadium,'f', 2));
        stadiumCount++;
    }
    else
    {
        QMessageBox::information(this, "Warning", "Your trip has ended. To continue, please click \"End Trip\"");
    }

}

void souvenirshop::on_endTour_button_clicked()
{
    if(stadiumCount >= selectedStadiums.size())
    {
        QString tempCost = "$" + QString::number(grandTotal, 'f', 2);
        QString tempDistance = QString::number(distanceTraveled, 'f', 2) + " miles";
        auto* endTrip = new tripSummary(tempDistance, tempCost, selectedStadiums, subCostList);
        hide();
        endTrip->show();
    }
    else
    {
        QMessageBox::information(this, "Warning", "Your tour is not over. Please finish your tour before clicking \"End Tour\"");
    }
}
