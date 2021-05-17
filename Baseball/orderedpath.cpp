#include "orderedpath.h"
#include "ui_orderedpath.h"

orderedPath::orderedPath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::orderedPath)
{
    ui->setupUi(this);
    fillComboBox();
}


orderedPath::~orderedPath()
{
    delete ui;
}
void orderedPath::fillComboBox()
{
    for (auto &i: database->getStadiumNames())
    {
        ui->selectOrderedStadiums->addItem(i);
        qDebug() << i << " ";
    }
}
void orderedPath::on_planTrip_button_2_clicked()
{
    bool alrdyAdded = false;
    for(int i = 0; i < otherStadiumNames.size(); i++)
        if (otherStadiumNames[i] == ui->selectOrderedStadiums->currentText())
            alrdyAdded = true;

    if (alrdyAdded)
        QMessageBox::warning(this,"ERROR", "Stadium already added");
    else
        otherStadiumNames.push_back(ui->selectOrderedStadiums->currentText());

    QWidget *container = new QWidget;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    container->setLayout(vBoxLayout);

    ui->scrollArea_displayTrip->setWidget(container);

    QLabel* temp;
    for(int i = 0; i < otherStadiumNames.size(); i++){
        temp = new QLabel(QString::number(i+1) + ". " + otherStadiumNames[i]);
        vBoxLayout->addWidget(temp);

    }

}


void orderedPath::on_startTrip_button_clicked()
{

}


