#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class login;
}

//!
//! \class login
//! Sets up the login screen
//! for the user to login as an administrator
//!
class login : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \fn login Constructor
    //! \param parent
    //!
    explicit login(QWidget *parent = nullptr);

    //!
    //! \fn ~login Destructor
    //!
    ~login();

    //!
    //! \brief loggedIn
    //! \return True is returned if correct username and password entered. False is returned otherwise.
    //!
    bool loggedIn();

private slots:

    //!
    //! \fn on_logInButton_clicked
    //! Logs User in if they enter the correct username and password
    //!
    void on_logInButton_clicked();

    //!
    //! \fn on_cancelLogin_clicked
    //! Allows the baseball fan to exit login
    //! screen.
    //!
    void on_cancelLogin_clicked();

private:
    //!
    //! \brief ui - sets up the ui
    //!
    Ui::login *ui;

    //!
    //! \brief isLoggedIn
    //! Holds whether the user is logged in as an Administrator
    //!
    bool isLoggedIn;
};

#endif // LOGIN_H
