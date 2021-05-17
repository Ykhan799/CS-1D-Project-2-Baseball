#include "displaygraphs.h"
#include "ui_displaygraphs.h"

displayGraphs::displayGraphs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::displayGraphs)
{
    ui->setupUi(this);
}

displayGraphs::~displayGraphs()
{
    delete ui;
}
