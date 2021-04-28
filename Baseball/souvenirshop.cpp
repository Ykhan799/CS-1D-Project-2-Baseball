#include "souvenirshop.h"
#include "ui_souvenirshop.h"

souvenirshop::souvenirshop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::souvenirshop)
{
    ui->setupUi(this);
}

souvenirshop::~souvenirshop()
{
    delete ui;
}
