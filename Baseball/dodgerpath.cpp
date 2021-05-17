#include "dodgerpath.h"
#include "ui_dodgerpath.h"

dodgerpath::dodgerpath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dodgerpath)
{
    ui->setupUi(this);
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
    //orderedStadiumNames = DJIKSTRA(startingStadium,otherStadiumNames);        IMPLEMENT DJIKSTRA ALG
}
