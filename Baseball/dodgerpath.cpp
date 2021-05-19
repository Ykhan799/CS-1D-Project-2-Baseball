
#include "dodgerpath.h"
#include "ui_dodgerpath.h"

dodgerpath::dodgerpath(QVector<QString> stadiums, QWidget *parent, Graph<QString>* getGraph) :
    QMainWindow(parent),
    ui(new Ui::dodgerpath)
{


    ui->setupUi(this);
    nameList = stadiums;

    fillComboBox();
    graph = getGraph;
}

dodgerpath::~dodgerpath()
{
    delete ui;
}



void dodgerpath::fillComboBox()
{
    for (auto &i: database->getTeamNames())
    {
        ui->selectStadium->addItem(i);
        ui->selectStadium_2->addItem(i);
        qDebug() << i << "\n";
    }
}
void dodgerpath::on_backButton_clicked()
{
    close();
}

void dodgerpath::on_planTrip_button_clicked()
{
    stadiums.clear();

    orderedStadiums.clear();
    SSRstartClicked = true;

    if (ui->selectStadium->currentText() == "")
    {
        return;
    }

    qDebug() << "First: " << ui->selectStadium->currentText() << Qt::endl;
    qDebug() << "Second: " << ui->selectStadium_2->currentText() << Qt::endl;
    stadiums.push_back(ui->selectStadium->currentText());
    stadiums.push_back(ui->selectStadium_2->currentText());

    dijkstras = new graphAM();
    orderedStadiums.clear();
    orderedStadiums = dijkstras->dijkstra1to1(stadiums[0], stadiums[1]);

    totalDist = dijkstras->getDistance();
    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea->setWidget(container);


    QLabel* temp;


    for(int i = 0; i < orderedStadiums.size(); i++)
    {
        QString stadiumName = dijkstras->teamToStadium(orderedStadiums[i]);

            temp = new QLabel(QString::number(i+1) + ". " +orderedStadiums[i]);
            vBoxLayout->addWidget(temp);

        }


        temp = new QLabel("Distance: " + QString::number( totalDist ) + " miles");
        vBoxLayout->addWidget(temp);



    dijkstras->printGraph();

}


void dodgerpath::on_startTrip_button_clicked()
{
    QVector <QString> convertedStadNames;
    for(int i = 0; i<orderedStadiums.size(); i++)
        convertedStadNames.push_back(database->getStadiumName(orderedStadiums[i]));
    auto* souvenir  = new souvenirshop(totalDist, convertedStadNames);
    hide();
    souvenir -> show();
}
