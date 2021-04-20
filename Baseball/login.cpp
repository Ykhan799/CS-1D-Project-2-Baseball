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

bool login::loggedIn()
{
    return isLoggedIn;
}
