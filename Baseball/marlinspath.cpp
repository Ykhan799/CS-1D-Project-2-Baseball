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
