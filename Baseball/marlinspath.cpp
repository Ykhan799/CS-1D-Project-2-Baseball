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
void marlinsPath::initalizeMarlinsPath()
{
    //rebuildGraph();
    startingStadium = "Marlins Park";

    /*
    otherStadiumNames.push_back(startingStadium);
    for (auto &i: database->getStadiumNames())
    {

        if(startingStadium != i)
        {
            otherStadiumNames.push_back(i);
        }
    }
    */


     int distance = graph->startMultiDijkstra(nameList, startingStadium);

    vector<QString> route = graph->dijkstraOrder;

    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);
    QLabel* label = new QLabel;

    ui->scrollArea_chosenSchools->setWidget(container);
    for (int i = 0; i < route.size(); i++)
    {
        label->setText(route[i]);
        vBoxLayout->addWidget(label);
    }
    //you have to make the QString into a label and then add it

    //ui->scrollArea_chosenSchools->set
    //orderedStadiumNames = DJIKSTRA(startingStadium,otherStadiumNames);        IMPLEMENT DJIKSTRA ALG

}

/*
void marlinsPath::rebuildGraph()
{


    // populate vectors and comboBox
    nameList = database->startingStadiums();
    tempList = nameList;

    // populate graph
    if(graph != nullptr) {
        delete graph;
    }
    graph = new Graph<QString>();
    vector<distanceEdge> edges;
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
*/

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
