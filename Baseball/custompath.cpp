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
}
