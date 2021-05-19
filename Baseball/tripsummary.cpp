#include "tripsummary.h"
#include "ui_tripsummary.h"

tripSummary::tripSummary(QString totalDistance, QString totalCost, QVector<QString> stadiumNames,
                 QStringList costAtEachStadium,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tripSummary)
{
    ui->setupUi(this);




    ui->label_totalDistance->setText(totalDistance);

    ui->label_totalCost->setText(totalCost);


    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea_stadiums->setWidget(container);

    //filling scroll area with chosen schools
    for(int i = 0; i < stadiumNames.size(); i++)
    {
        //stadiumLabel = new QLabel(stadiumNames[i] + "\t\t" + costAtEachStadium[i]);
        stadiumLabel = new QLabel(convert->stadiumToTeam(stadiumNames[i]) + " [" +stadiumNames[i]+"]"  + " (Spent $" + costAtEachStadium.at(i) + ")");
        vBoxLayout->addWidget(stadiumLabel);
    }
}

tripSummary::~tripSummary()
{
    delete ui;
}

void tripSummary::on_done_button_clicked()
{
    hide();
}
