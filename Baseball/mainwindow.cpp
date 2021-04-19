#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    auto* custom = new customPath();
    custom -> show();
}

void MainWindow::on_pushButton_3_clicked()
{
    auto* dodger = new dodgerpath();
    dodger -> show();
}

void MainWindow::on_pushButton_4_clicked()
{
    auto* marlins = new marlinsPath();
    marlins -> show();

}
