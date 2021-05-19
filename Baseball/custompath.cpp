#include "custompath.h"
#include "ui_custompath.h"

customPath::customPath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::customPath)
{
    ui->setupUi(this);
    fillComboBox();
}

customPath::~customPath()
{
    delete ui;
}

void customPath::fillComboBox()
{
    for (auto &i: database->getTeamNames())
    {
        ui->selectStartingStadiums->addItem(i);
        qDebug() << i << " ";
    }
}
void customPath::fillScrollArea()
{
    checkBoxVector.clear();

    QString selectedStartingStadium = ui->selectStartingStadiums->currentText();
    startingStadium = selectedStartingStadium;
    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea_selectStadiums->setWidget(container);

    for (auto &i: database->getTeamNames())
    {

        if(selectedStartingStadium != i)
        {
            QCheckBox* checkBox = new QCheckBox(i);
            checkBox->setCheckState(Qt::CheckState::Unchecked);
            checkBoxVector.push_back(checkBox);
            //connect(checkBox, &QCheckBox::stateChanged, this, &pathCustom::CheckboxChanged);
            teamNamesVector.push_back(i);
        }
    }

    for(int i = 0; i < checkBoxVector.size(); i++)
    {
        vBoxLayout->addWidget(checkBoxVector[i]);

    }
}
void customPath::CheckboxChanged()
{
    teamNamesVector.clear();
    qDebug() << "Signal caught";


    for(int i = 0; i < checkBoxVector.size(); i++)
    {
        if(checkBoxVector[i]->checkState() == Qt::CheckState::Checked)
        {
           // qDebug() << teamNamesVector[i] << Qt::endl;
            teamNamesVector.push_back(teamNamesVector[i]);
        }
    }

    qDebug() << "Starting Stadium: " << startingStadium << Qt:: endl;
    qDebug() << "Other Stadiums: ";
    for(int i = 0; i < teamNamesVector.size(); i++)
        qDebug() << teamNamesVector[i] << Qt::endl;

}


void customPath::on_selectStartingStadiums_activated()
{
    fillScrollArea();
}

void customPath::on_backButton_clicked()
{
    close();
}

void customPath::on_planTrip_button_clicked()
{
    CheckboxChanged();

    teamNamesVector.clear();
    startTeamName = ui->selectStartingStadiums->currentText();
    teamNamesVector.push_back(startTeamName);
    CheckboxChanged();
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

        for (int k = 0; k < tempVec.size() - 1; k++)
        {
            finalTrip.push_back(tempVec[k]);
        }
        currentTeam = tempVec[tempVec.size() - 1];
        lastTeam = tempVec[tempVec.size() - 1];
    }

    finalTrip.push_back(lastTeam);


    totalDist= tripDistance;

    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea_displayTrip->setWidget(container);

    QLabel* temp;
    for(int i = 0; i < finalTrip.size(); i++){
        temp = new QLabel(QString::number(i+1) + ". " + finalTrip[i]);
        vBoxLayout->addWidget(temp);
    }
}



void customPath::on_startTrip_button_clicked()
{

    auto* souvenir  = new souvenirshop(totalDist, teamNamesVector);
    hide();
    souvenir -> show();
}
