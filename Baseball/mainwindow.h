#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "custompath.h"
#include "marlinspath.h"
#include "dodgerpath.h"
#include "login.h"
#include "DataBase.h"
#include "manageDB.h"
#include "graph.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //!
    //! \brief on_LogIn_clicked
    //! Launches the Log In window
    //!
    void on_LogIn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    //!
    //! \brief on_viewTeamsSouvenirs_clicked
    //! Launches the window to view teams and souvenirs.
    //!
    void on_viewTeamsSouvenirs_clicked();

    //!
    //! \brief on_LogOut_clicked
    //! Launches the Log Out window once administrator logs in.
    //!
    void on_LogOut_clicked();

    //!
    //! \brief on_BFSDFSMST_clicked
    //! Launches a window for a baseball fan to view the BFS, DFS,
    //! and/or MST of the baseball teams
    //!
    void on_BFSDFSMST_clicked();

private:
    Ui::MainWindow *ui;

    login* admin;

    DataBase* database;

    manageDB *data;

    graph* info;

    bool isAdmin;
};
#endif // MAINWINDOW_H
