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

    qry->prepare("SELECT souvenirs, cost FROM Souvenirs WHERE mlbTeams= (:mlbTeams)");
    qry->bindValue(":mlbTeams", selectedStadiums[collegeCount]);

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

    collegeCount++;
}

souvenirshop::~souvenirshop()
{
    delete ui;
}
