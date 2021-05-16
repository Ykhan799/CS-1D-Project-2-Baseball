#include "dodgerpath.h"
#include "ui_dodgerpath.h"

dodgerpath::dodgerpath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dodgerpath)
{
    ui->setupUi(this);
}

dodgerpath::~dodgerpath()
{
    delete ui;
}
void dodgerpath::fillScrollArea()
{
    QString selectedStartingStadium = "Angel Stadium";
    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea_selectStadiums->setWidget(container);

    for (auto &i: database->getStadiumNames())
    {

        if(selectedStartingStadium != i)
        {
            QCheckBox* checkBox = new QCheckBox(i);
            QString collegeName = (i);
            checkBox->setCheckState(Qt::CheckState::Unchecked);
            checkBoxVector.push_back(checkBox);
            //connect(checkBox, &QCheckBox::stateChanged, this, &pathCustom::CheckboxChanged);
        }
    }

    for(int i = 0; i < checkBoxVector.size(); i++)
    {
        vBoxLayout->addWidget(checkBoxVector[i]);

    }
}
