#include "souvenirshop.h"
#include "ui_souvenirshop.h"


souvenirshop::souvenirshop(double distance, QVector<QString> stadiumVector, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::souvenirshop)
{
    ui->setupUi(this);
    distanceTraveled = distance;
    selectedStadiums = stadiumVector;

    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("SELECT SOUVENIRS, Price FROM Souvenirs WHERE mlbTeams= (:mlbTeams)");
    qry->bindValue(":mlbTeams", selectedStadiums[stadiumCount]);

    if(qry->exec())
    {
        qDebug() << "Souvenirs updated";
    }

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
        ui->label_souvCosts->setText("Cost of Souvenirs Purchased Here: $" + QString::number(subCostAtStadium, 'f', 2));

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
