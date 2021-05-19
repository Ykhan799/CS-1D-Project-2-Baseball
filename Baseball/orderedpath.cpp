#include "orderedpath.h"
#include "ui_orderedpath.h"

orderedPath::orderedPath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::orderedPath)
{
    ui->setupUi(this);
    fillComboBox();
}


orderedPath::~orderedPath()
{
    delete ui;
}
void orderedPath::fillComboBox()
{
    for (auto &i: database->getTeamNames())
    {
        ui->selectOrderedStadiums->addItem(i);

    }
}
void orderedPath::on_planTrip_button_2_clicked()
{

    totalDist = 0;
    bool alrdyAdded = false;
    for(int i = 0; i < customTeamNameList.size(); i++)
        if (customTeamNameList[i] == ui->selectOrderedStadiums->currentText())
            alrdyAdded = true;

    if (alrdyAdded)
        QMessageBox::warning(this,"ERROR", "Stadium already added");
    else{
        customTeamNameList.push_back(ui->selectOrderedStadiums->currentText());
    }

    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea_displayTrip->setWidget(container);

    QLabel* temp;

    counter = 0;
    fastestRoute.clear();
    if(customTeamNameList.size() > 2)
    {
        chooseOrder = new graphAM();
        fastestRoute = chooseOrder->dijkstraRecursive(customTeamNameList);
    }
    else if(customTeamNameList.size() == 2)
    {
        chooseOrder = new graphAM();

        fastestRoute = chooseOrder->dijkstra1to1(customTeamNameList[0], customTeamNameList[1]);
    }
    else
    {
        fastestRoute = customTeamNameList;

    }

    if(customTeamNameList.size() > 1)
    {

        totalDist = chooseOrder->getDistance();
    }


    for(int i = 0; i < fastestRoute.size(); i++){
        qDebug() <<  fastestRoute[i];
        temp = new QLabel(QString::number(i+1) + ". " +fastestRoute[i]);
        vBoxLayout->addWidget(temp);

    }
    //customTeamNameList.clear(); //clears the custom name list after the start button is clicked
    //ui->CTO_comboBox->clear();  //clears the combo box and reloads it
    //fillStartTeam();
    CTOstartButtonClicked  = true;
    temp = new QLabel("Distance: " + QString::number( totalDist ) + " miles");
    vBoxLayout->addWidget(temp);


}


void orderedPath::on_startTrip_button_clicked()
{

}


