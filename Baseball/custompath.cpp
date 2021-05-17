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
    efficiencyAlgo(&selectedCampusNames,&orderedStadiumNames,&orderedStadiumDistances,startingStadium);
}
void customPath::efficiencyAlgo(QVector<QString> *stadiums,
                 QVector<QString> *routeNames,
                 QVector<double> *routeDistances,
                 QString currentStadium)
{
    // BASE CASE: no more schools to visit
    if(stadiums->empty()) { return; }

    QString nextSchool;         // next school in route
    double temp = 0;            // temperary var to compare to min distance
    double distance = 0;        // stores distance
    double minDist = 1000000;   // starting point for min distance
    int minIndex;               // index of min distance in college QVector

    // find min distance
    for(int i=0; i < stadiums->size(); i++) {

        qDebug() << "i: " << i << Qt::endl;
        QSqlQuery *query = new QSqlQuery();

        query->prepare("SELECT DIST FROM DISTANCES WHERE "
                      "Starting == '" + currentStadium + "' AND "
                      "Ending == '" + stadiums->at(i) + "'");

        if(query->exec()) {
            qDebug() << "Efficiency algo executed" << Qt::endl;
            query->next();
            qDebug() << "Distance: " << query->value(2).toDouble() << Qt::endl;
            distance = query->value(2).toDouble();

        temp = distance;

        if ( temp < minDist ) {
            minDist = temp;
            nextSchool = stadiums->at(i);
            minIndex = i;
        }
    }
}
    // remove  from college QVector
    stadiums->erase(stadiums->begin()+minIndex);
    // add next stadium to route
     qDebug() << "Stadium: " << nextSchool << Qt::endl;
    QLabel* tempSchool = new QLabel(nextSchool);

    stadiumLabelVector.push_back(tempSchool);
    routeNames->push_back(nextSchool);
    // add distance to next school in route
    routeDistances->push_back(minDist);
    totalDist = totalDist + minDist;

    // RECURSIVE CALL
    efficiencyAlgo(stadiums, routeNames, routeDistances, nextSchool);
}


