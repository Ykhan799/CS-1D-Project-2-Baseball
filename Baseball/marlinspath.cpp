#include "marlinspath.h"
#include "ui_marlinspath.h"




marlinsPath::marlinsPath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::marlinsPath)
{
    ui->setupUi(this);
    initalizeMarlinsPath();
}

marlinsPath::~marlinsPath()
{
    delete ui;
}
void marlinsPath::initalizeMarlinsPath(){
    startingStadium = "Marlins Park";
    for (auto &i: database->getStadiumNames())
    {

        if(startingStadium != i)
        {
            otherStadiumNames.push_back(i);
        }
    }
    //orderedStadiumNames = DJIKSTRA(startingStadium,otherStadiumNames);        IMPLEMENT DJIKSTRA ALG

}

void marlinsPath::on_startTrip_button_clicked()
{
    QVector<QString> stadiumVector;
    stadiumVector.append("Arizona Diamondbacks");
    auto* souvenir  = new souvenirshop(4234, stadiumVector);
    hide();
    souvenir -> show();
}

void marlinsPath::on_backButton_clicked()
{
    close();
}
