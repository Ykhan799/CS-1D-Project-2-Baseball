#include "displaygraphs.h"
#include "ui_displaygraphs.h"

displayGraphs::displayGraphs(QVector<QString> stadiums, QWidget *parent, Graph<QString> *getGraph) :
    QMainWindow(parent),
    ui(new Ui::displayGraphs)
{
    ui->setupUi(this);
   // ui->tableWidget->clear();
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    graphs = getGraph;
    nameList = stadiums;

    if (graphs == nullptr || stadiums.empty())
    {
        rebuildGraph();
    }
}

displayGraphs::~displayGraphs()
{
    delete ui;
}

void displayGraphs::on_backButton_clicked()
{
    close();
}

void displayGraphs::on_DFSButton_clicked()
{
    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);
   // QVector<QLabel> texts;

    ui->View->setWidget(container);


    int distance = graphs->startDFS("Oracle Park");
    QString pathStr;
    for (const auto &dest : graphs->dfsOrder) {
        pathStr = dest + "\n";
        QLabel *label = new QLabel;
        label->setText(pathStr);
        vBoxLayout->addWidget(label);

    }


    ui->label->setVisible(true);
    ui->label_2->setVisible(true);

    ui->label_2->setText(QString::number(distance) + " miles");
}

void displayGraphs::on_MSTButton_clicked()
{
    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);
   // QVector<QLabel> texts;

    ui->View->setWidget(container);

    int distance = graphs->startMST();
    QString pathStr = "MST Edges:\n";
    pathStr += graphs->mstString;

    QLabel *label = new QLabel;
    label->setText(pathStr);
    vBoxLayout->addWidget(label);

    ui->label->setVisible(true);
    ui->label_2->setVisible(true);

    ui->label_2->setText(QString::number(distance) + " miles");
}

void displayGraphs::on_BFSButton_clicked()
{

    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);
   // QVector<QLabel> texts;

    ui->View->setWidget(container);

    int start = graphs->startBFS("Target Field");
    QString pathStr;


        for (const auto &dest : graphs->bfsOrder) {
            pathStr = dest + "\n";
            QLabel *label = new QLabel;
            label->setText(pathStr);

            vBoxLayout->addWidget(label);

        }

        ui->label->setVisible(true);
        ui->label_2->setVisible(true);

        ui->label_2->setText(QString::number(start) + " miles");
 }

void displayGraphs::rebuildGraph()
{


    // populate QVectors and comboBox
    nameList = data->startingStadiums();
    tempList = nameList;

    // populate graph
    if(graphs != nullptr) {
        delete graphs;
    }
    graphs = new Graph<QString>();
    QVector<distanceEdge> edges;
    for (const QString &stadium : nameList) {
        qDebug() << "adding node:" << stadium;
        graphs->addNode(stadium);
    }
    for (const QString &stadium : nameList) {
        edges = data->getDistances(stadium);
        for (const auto &edge : edges) {
            qDebug() << "adding edge:" << edge.team_name_origin << edge.team_name_destination << edge.distance;
            graphs->addEdge(edge.team_name_origin, edge.team_name_destination,
                           edge.distance);
        }
    }

}

