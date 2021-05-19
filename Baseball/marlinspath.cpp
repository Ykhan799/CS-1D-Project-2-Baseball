#include "marlinspath.h"
#include "ui_marlinspath.h"


marlinsPath::marlinsPath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::marlinsPath)
{
    ui->setupUi(this);
    QSqlQueryModel* model=new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT TeamName FROM Teams");

    if(qry->exec())
    {
        qDebug() << "start team combo box loaded";
    }
    else
        qDebug() << "start team combo box failed";

    while(qry->next())//loads the combo box on the CTO page
    {
        allTeamsList.push_back(qry->value(0).toString());
    }

    model->setQuery(*qry);

    ui->comboBox->setModel(model);

    initalizeMarlinsPath();
}

marlinsPath::~marlinsPath()
{
    delete ui;
}
void marlinsPath::initalizeMarlinsPath()
{

}


void marlinsPath::on_startTrip_button_clicked()
{

  /*  auto* souvenir  = new souvenirshop(4234, orderedStadiumNames);
    hide();
    souvenir -> show();
    */
}

void marlinsPath::on_backButton_clicked()
{

    close();
}

void marlinsPath::on_planTrip_button_clicked()
{
    startTeamName = ui->comboBox->currentText();

    teamNamesVector.clear();
    ui->textBrowser_MiamiMarlins->clear();

    teamNamesVector.push_back(startTeamName);

    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT DISTINCT TeamName FROM Teams");
    query->exec();
    while(query->next())
    {
        if(query->value(0).toString() != startTeamName)
        {
            teamNamesVector.push_back(query->value(0).toString());
        }
    }

    dijkstrasChooseTeams = new graphAM();

    pQueue<QVector<QString>> *incidentTeams;
    QMap<QString, bool> isVisited;
    QList<QString> finalTrip;
    QString lastTeam;
    // fill isVisited map
    for (int i = 0; i < teamNamesVector.size(); i++)
    {
        isVisited[teamNamesVector[i]] = false;
    }

    int tripDistance = 0;
    QString currentTeam = teamNamesVector[0];

    for (int i = 0; i < teamNamesVector.size() - 1; i++)
    {
        incidentTeams = new pQueue<QVector<QString>>;
        isVisited[currentTeam] = true;

        for (int j = 0; j < teamNamesVector.size(); j++)
        {
            QString compareTeam = teamNamesVector[j];
            if (isVisited[compareTeam] != true)
            {
                QVector<QString> tempRoute = dijkstrasChooseTeams->dijkstra1to1(currentTeam, compareTeam);
                int tempPriority = dijkstrasChooseTeams->getDistance();
                incidentTeams->enqueue(tempPriority, tempRoute);
            }
        }
        qDebug() << incidentTeams->getShortestTrip() << "    " << incidentTeams->getLowestPriority();
        QVector<QString> tempVec = incidentTeams->getShortestTrip();
        tripDistance += incidentTeams->getLowestPriority();

     /*   for (int k = 0; k < tempVec.size() - 1; k++)
        {
            finalTrip.push_back(tempVec[k]);
        }
        currentTeam = tempVec[tempVec.size() - 1];
        lastTeam = tempVec[tempVec.size() - 1];*/
    }

   // finalTrip.push_back(lastTeam);


    ui->textBrowser_MiamiMarlins->append("Distance: " + QString::number(tripDistance) + "\n");
    ui->textBrowser_MiamiMarlins->setAlignment(Qt::AlignLeft);
   /* for(int i = 0; i < finalTrip.size(); i++)
    {
        QString stadiumName = dijkstrasChooseTeams->teamToStadium(finalTrip[i]);
        ui->textBrowser_MiamiMarlins->append(QString::number(i+1) + ". " + finalTrip[i] + "\n    (" + stadiumName + ")\n");
    }*/


    dijkstrasChooseTeams->printGraph();
    totalDist = tripDistance;
}
