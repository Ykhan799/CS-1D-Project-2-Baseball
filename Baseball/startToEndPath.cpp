
#include "startToEndPath.h"
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
    ui->textBrowser_SSR->clear();
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
    ui->textBrowser_SSR->setAlignment(Qt::AlignCenter);
    ui->textBrowser_SSR->append("Distance: " + QString::number(dijkstras->getDistance()) + "\n");
    ui->textBrowser_SSR->setAlignment(Qt::AlignLeft);

    for(int i = 0; i < orderedStadiums.size(); i++)
    {
        QString stadiumName = dijkstras->teamToStadium(orderedStadiums[i]);
        ui->textBrowser_SSR->append(QString::number(i+1) + ". " + orderedStadiums.at(i) + '\n' + "  (" + stadiumName + ")\n");
    }

    ui->textBrowser_SSR->selectAll();
    dijkstras->dijkstraAll(database->getTeamNames());


}

