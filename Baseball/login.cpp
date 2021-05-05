#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    isLoggedIn = false;
}

login::~login()
{
    delete ui;
}

/*************************************************************************
 * void on_logInButton_clicked()
 * -----------------------------------------------------------------------
 * Checks if the admin has the correct username and password. Valid usernames are
 * admin and Admin. Valid passwords are password and Teqnify1894
 ************************************************************************/
void login::on_logInButton_clicked()
{
   QString usernameInput = ui->usernameField->text();
   QString passwordInput = ui->passwordField->text();

   if ((usernameInput == "Admin" || usernameInput == "admin") && (passwordInput == "Teqnify1894" || passwordInput == "password"))
   {
       QMessageBox::information(this, "Success", "Logged in as Administrator");
       isLoggedIn = true;
       this->close();
   }

   else
   {
       QMessageBox::information(this, "Error", "Incorrect Login Information");
       isLoggedIn = false;
   }
}

/*************************************************************************
 * bool loggedIn()
 * -----------------------------------------------------------------------
 * Returns true if admin is logged in. Returns false otherwise.
 ************************************************************************/
bool login::loggedIn()
{
    return isLoggedIn;
}

/*************************************************************************
 * void on_cancelLogin_clicked()
 * -----------------------------------------------------------------------
 * Lets an Baseball fan or admin to close the login screen button.
 ************************************************************************/
void login::on_cancelLogin_clicked()
{
    this->close();
}
