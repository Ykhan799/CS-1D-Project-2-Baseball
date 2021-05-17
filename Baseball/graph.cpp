/*
#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);

    // clears the widget
    ui->graphTableWidget->clear();

     // sets the labels to false
     ui->dist->setVisible(false);
     ui->setDistance->setVisible(false);
}

graph::~graph()
{
    delete ui;
}




void graph::displayGraph(vector<Edge<QString>> Edge)
{
    // Sets the dimensions for the table widget
    ui->graphTableWidget->setColumnCount(3);
    ui->graphTableWidget->setColumnWidth(0, 275);
    ui->graphTableWidget->setColumnWidth(1, 275);
    ui->graphTableWidget->setColumnWidth(2, 200);
    ui->graphTableWidget->setRowCount(Edge.size());

    // names the columns
    ui->graphTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Starting Stadium"));
    ui->graphTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Ending Stadium"));
    ui->graphTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Distance(mileage)"));
    double totalDist = 0;
    int rows = 0;

    // Traverses through each element of the Edge vector
    for (auto &i: Edge)
    {
        // gets the starting stadium, ending stadium, distance, and total distance
        ui->graphTableWidget->setItem(rows, 0, new QTableWidgetItem(i.start));
        ui->graphTableWidget->setItem(rows, 1, new QTableWidgetItem(i.end));
        ui->graphTableWidget->setItem(rows, 2, new QTableWidgetItem(QString::number(i.weight)));
        totalDist += i.weight;

        // increments row
        rows++;
    }

    // sets labels to true and displays the total Distance
    ui->dist->setVisible(true);
    ui->setDistance->setVisible(true);
    ui->setDistance->setText(QString::number(totalDist) + " miles");

}




void graph::on_back_clicked()
{
    this->close();
}



void graph::getGraph()
{
    // gets the vertices(stadiums) and creates an array of stadiums
    vector<QString> stadiums = database->startingStadiums();
    stadium = new QString[stadiums.size()];

    // assigns elements to the stadium array
    int index = 0;
    for(auto i = stadiums.begin(); i!= stadiums.end(); i++)
    {
        stadium[index] = *i;
        index++;
    }

    // creates a graph with the size being the number of stadiums.
    createGraph = new graphHelper<QString>(stadium, stadiums.size());
    for(auto i = stadiums.begin(); i!= stadiums.end(); i++)
    {
        // Gets the edges from undirected graph and adds them into the graph
        vector<Edge<QString>> edges = database->getEdges(*i);
        for(auto e: edges)
        {
            createGraph->addEdge(e.start, e.end, e.weight);
        }
    }
}




void graph::on_bfs_clicked()
{
    // creates a graph
    getGraph();

    // gets the BFS of the baseball stadiums from Target Field and displays the edges
    vector<Edge<QString>> edges = createGraph->BFS("Target Field");
    displayGraph(edges);
}




void graph::on_dfs_clicked()
{
    // creates a graph
    getGraph();

    // gets the DFS of the baseball stadiums from Oracle Park and displays the edges


    vector<Edge<QString>> edges = createGraph->DFS("Oracle Park");
    displayGraph(edges);

}




void graph::on_mst_clicked()
{
    // creates a graph
    getGraph();

    // gets the MST of the baseball stadiums using Kruskal's algorithm and displays the MST
    vector<Edge<QString>> edges = createGraph->kruskalMST();
    displayGraph(edges);
}
*/

