#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    //!
    //! \brief loggedIn
    //! \return True is returned if correct username and password entered. False is returned otherwise.
    //!
    bool loggedIn();

private slots:

    //!
    //! \brief on_logInButton_clicked
    //! Logs User in if they enter the correct username and password
    //!
    void on_logInButton_clicked();

private:
    Ui::login *ui;

    //!
    //! \brief isLoggedIn
    //! Holds whether the user is logged in as an Administrator
    //!
    bool isLoggedIn;
};

#endif // LOGIN_H
