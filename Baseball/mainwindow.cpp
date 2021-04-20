#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isAdmin = false;
    ui->LogOut->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*************************************************************************
 * void on_LogIn_clicked()
 * -----------------------------------------------------------------------
 * Opens a window prompting for the user to enter a username and password.
 * If entered correctly, the user becomes an admin and is given special
 * privileges for the remainder of the program unless the user logs out.
 ************************************************************************/
void MainWindow::on_LogIn_clicked()
{
    admin = new login();
    admin->exec();
    isAdmin = admin->loggedIn();

    // Checks if user is logged in
    if (isAdmin)
    {
        // Sets the Login button invisible but sets the Log Out button visible.
        ui->LogIn->setVisible(false);
        ui->LogOut->setVisible(true);
    }
    delete admin;
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

/*************************************************************************
 * void on_LogOut_clicked()
 * -----------------------------------------------------------------------
 * Notifies the Administrator that they have logged out. Once the administrator
 * clicks this button, they are no longer administrator or the remainder of
 * this program unless the user successfully signs in again.
 ************************************************************************/
void MainWindow::on_LogOut_clicked()
{
    QMessageBox::information(this, "Success", "You are logged off");

    // Sets the Login Button Visible and sets the Log Out button invisible
    ui->LogIn->setVisible(true);
    ui->LogOut->setVisible(false);

    // sets isAdmin to false
    isAdmin = false;
}

