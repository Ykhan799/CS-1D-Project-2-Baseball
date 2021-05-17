
#include "dodgerpath.h"
#include "ui_dodgerpath.h"

dodgerpath::dodgerpath(QVector<QString> stadiums, QWidget *parent, Graph<QString>* getGraph) :
    QMainWindow(parent),
    ui(new Ui::dodgerpath)
{
    nameList = stadiums;
    ui->setupUi(this);
    graph = getGraph;
    fillScrollArea();
}

dodgerpath::~dodgerpath()
{
    delete ui;
}
void dodgerpath::fillScrollArea()
{
    QString selectedStartingStadium = "Dodger Stadium";
    startingStadium = selectedStartingStadium;
    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea_selectStadiums->setWidget(container);

    for (auto &i: database->getStadiumNames())
    {

        if(selectedStartingStadium != i)
        {
            QCheckBox* checkBox = new QCheckBox(i);
            checkBox->setCheckState(Qt::CheckState::Unchecked);
            checkBoxVector.push_back(checkBox);
            otherStadiumNames.push_back(i);
        }
    }

    for(int i = 0; i < checkBoxVector.size(); i++)
    {
        vBoxLayout->addWidget(checkBoxVector[i]);

    }
}
void dodgerpath::rebuildGraph()
{


    // populate QVectors and comboBox
    nameList = otherStadiumNames;
    nameList.push_back(startingStadium);
    tempList = nameList;

    // populate graph
    if(graph != nullptr) {
        delete graph;
    }
    graph = new Graph<QString>();
    QVector<distanceEdge> edges;
    for (const QString &stadium : nameList) {
        qDebug() << "adding node:" << stadium;
        graph->addNode(stadium);
    }
    for (const QString &stadium : nameList) {
        edges = database->getDistances(stadium);
        for (const auto &edge : edges) {
            qDebug() << "adding edge:" << edge.team_name_origin << edge.team_name_destination << edge.distance;
            graph->addEdge(edge.team_name_origin, edge.team_name_destination,
                           edge.distance);
        }
    }

}


void dodgerpath::CheckboxChanged()
{
    selectedCampusNames.clear();
    qDebug() << "Signal caught";


    for(int i = 0; i < checkBoxVector.size(); i++)
    {
        if(checkBoxVector[i]->checkState() == Qt::CheckState::Checked)
        {
           // qDebug() << otherStadiumNames[i] << Qt::endl;
            selectedCampusNames.push_back(otherStadiumNames[i]);
        }
    }

    qDebug() << "Starting Stadium: " << startingStadium << Qt:: endl;
    qDebug() << "Other Stadiums: ";
    for(int i = 0; i < selectedCampusNames.size(); i++)
        qDebug() << selectedCampusNames[i] << Qt::endl;

}
void dodgerpath::on_backButton_clicked()
{
    close();
}

void dodgerpath::on_planTrip_button_clicked()
{
    CheckboxChanged();


    if (graph == nullptr || nameList.empty())
    {
        rebuildGraph();
    }
    startingStadium = "Dodger Stadium";



      //QVector<int> dists = graph->getMultiDijkstra(otherStadiumNames, startingStadium);
     int distance = graph->startMultiDijkstra(otherStadiumNames, startingStadium);


    QVector<QString> route = graph->dijkstraOrder;


    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);
   // QVector<QLabel> texts;

    ui->scrollArea_displayTrip->setWidget(container);
    for (int i = 0; i < route.size(); i++)
    {
        qDebug() << route[i];
        QLabel* label = new QLabel;
        label->setText(route[i]);
        vBoxLayout->addWidget(label);
    }

    QLabel* label = new QLabel;
    label->setText("Total Distance Traveled: " + QString::number(distance) + " miles");

    vBoxLayout->addWidget(label);

    //orderedStadiumNames = DJIKSTRA(startingStadium,otherStadiumNames);        IMPLEMENT DJIKSTRA ALG
}

