#include "marlinspath.h"
#include "ui_marlinspath.h"


marlinsPath::marlinsPath(QVector<QString> stadiums, QWidget *parent, Graph<QString>* getGraph) :
    QMainWindow(parent),
    ui(new Ui::marlinsPath)
{
    ui->setupUi(this);
    graph = getGraph;
    nameList = stadiums;

    if (graph == nullptr || nameList.empty())
    {
        rebuildGraph();
    }
    initalizeMarlinsPath();
}

marlinsPath::~marlinsPath()
{
    delete ui;
}
void marlinsPath::initalizeMarlinsPath()
{
    startingStadium = "Marlins Park";

    otherStadiumNames = nameList;


      //QVector<int> dists = graph->getMultiDijkstra(otherStadiumNames, startingStadium);
     int distance = graph->startMultiDijkstra(otherStadiumNames, startingStadium);


    QVector<QString> route = graph->dijkstraOrder;


    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);
   // QVector<QLabel> texts;

    ui->scrollArea_chosenSchools->setWidget(container);
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

}


void marlinsPath::rebuildGraph()
{


    // populate QVectors and comboBox
    nameList = database->startingStadiums();
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
