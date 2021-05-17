
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
    for (auto &i: database->getStadiumNames())
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

    for (auto &i: database->getStadiumNames())
    {

        if(selectedStartingStadium != i)
        {
            QCheckBox* checkBox = new QCheckBox(i);
            checkBox->setCheckState(Qt::CheckState::Unchecked);
            checkBoxVector.push_back(checkBox);
            //connect(checkBox, &QCheckBox::stateChanged, this, &pathCustom::CheckboxChanged);
            otherStadiumNames.push_back(i);
        }
    }

    for(int i = 0; i < checkBoxVector.size(); i++)
    {
        vBoxLayout->addWidget(checkBoxVector[i]);

    }
}
void customPath::CheckboxChanged()
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
    createRoute(selectedCampusNames[0]);
    QWidget* container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    container->setLayout(vBoxLayout);
    ui->scrollArea_displayTrip->setWidget(container);
    QLabel label;

    while (!route.empty())
    {
    }

}

/*
void customPath::recursiveStadiumSort(QString current, vector<QString> &selected)
{
    vector<int> getDijkstra = graphs->Dijkstra(current);
    int next = nextStadium(getDijkstra, selected);
}
*/


/*
int customPath::nextStadium(vector<int> Dist, vector<QString> &selected)
{
    int min = 100000;
    int minIndex = -1;

    for (int v = 0; v < Dist.size(); v++)
    {
        if (Dist[v] <= min)
        {
            min = Dist[v];
            minIndex = v;

        }
    }
    totalDist += min;
    return minIndex;
}
*/

/*
void customPath::createGraph()
{
    // gets the vertices(stadiums) and creates an array of stadiums
    stad = new QString[selectedCampusNames.size()];

    // assigns elements to the stadium array
    int index = 0;
    for(auto i = selectedCampusNames.begin(); i!= selectedCampusNames.end(); i++)
    {
        stad[index] = *i;
        index++;
    }

    // creates a graph with the size being the number of stadiums.
    graphs = new graphHelper<QString>(stad, selectedCampusNames.size());
    for(auto i = selectedCampusNames.begin(); i!= selectedCampusNames.end(); i++)
    {
        // Gets the edges from undirected graph and adds them into the graph
        vector<Edge<QString>> edges = database->getEdges(*i);
        for(auto e: edges)
        {
            graphs->addEdge(e.start, e.end, e.weight);
        }
    }
}
*/

void customPath::createRoute(QString campus)
{
    // add the campus to the route queue
    route.push(campus);

    // remove the campus from the list of campuses that still need to be visited
    auto it = std::find(selectedCampusNames.begin(), selectedCampusNames.end(), campus);
    if (it != selectedCampusNames.end())
    {
        selectedCampusNames.erase(it);
    }

    // base case, no more campuses to visit in this route
    if (selectedCampusNames.size() <= 0)
    {
        // assign this campus to finalCampus and exit function
        finalCampus = campus;
        return;
    }

    else
    {
        // initialize variables to hold closest campus
        QString closestCampus = selectedCampusNames.front();
        double shortestDist = database->getDistance( campus, selectedCampusNames.front() );
        auto it = selectedCampusNames.begin();

        while (it != selectedCampusNames.end())
        {
            // update the closest campus if the currently accessed campus in the vector is closer than previous closest campus
            if (database->getDistance(campus, *it) < shortestDist)
            {
                closestCampus = *it;
                shortestDist = database->getDistance( campus, *it );
            }

            // increment iterator
            it++;
        }

        // finally add to the total distance counter
        totalDist += shortestDist;

        // recursive call
        createRoute(closestCampus);
    }
}


