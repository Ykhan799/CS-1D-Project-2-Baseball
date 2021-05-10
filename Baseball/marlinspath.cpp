#include "marlinspath.h"
#include "ui_marlinspath.h"




marlinsPath::marlinsPath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::marlinsPath)
{
    ui->setupUi(this);
}

marlinsPath::~marlinsPath()
{
    delete ui;
}

void marlinsPath::on_startTrip_button_clicked()
{
    QVector<QString> stadiumVector;
    stadiumVector.append("Arizona Diamondbacks");
    auto* souvenir  = new souvenirshop(4234, stadiumVector);
    hide();
    souvenir -> show();
}
