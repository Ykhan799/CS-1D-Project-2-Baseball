#include "custompath.h"
#include "ui_custompath.h"

customPath::customPath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::customPath)
{
    ui->setupUi(this);
    fillComboBox();
    fillScrollArea();
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
