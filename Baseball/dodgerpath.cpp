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
