#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "custompath.h"
#include "marlinspath.h"
#include "dodgerpath.h"
#include "login.h"
#include "DataBase.h"
#include "manageDB.h"
#include "dijkstra.h"
#include "displaygraphs.h"
#include "orderedpath.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//!
//! \class MainWindow
//! Allows the user to login, view teams, souvenirs,
//! BFS, DFS, and MST
//!
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //!
    //! \fn MainWindow Constructor
    //! Sets the database connection
    //! \param parent - sets up the ui
    //!
    MainWindow(QWidget *parent = nullptr);

    //!
    //! \fn ~MainWindow Destructor
    //!
    ~MainWindow();

private slots:
    //!
    //! \fn on_LogIn_clicked
    //! Launches the Log In window
    //!
    void on_LogIn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    //!
    //! \fn on_viewTeamsSouvenirs_clicked
    //! Launches the window to view teams and souvenirs.
    //!
    void on_viewTeamsSouvenirs_clicked();

    //!
    //! \fn on_LogOut_clicked
    //! Launches the Log Out window once administrator logs in.
    //!
    void on_LogOut_clicked();

    void on_DFSBFSMST_clicked();

    void on_pushButton_5_clicked();

private:
    //!
    //! \brief ui - accesses the ui
    //!
    Ui::MainWindow *ui;

    //!
    //! \brief admin - opens the login screen
    //!
    login* admin;

    //!
    //! \brief database - opens up the database to view teams and souvenirs
    //!
    DataBase* database;

    //!
    //! \brief data - connects to the database
    //!
    manageDB *data;

    //!
    //! \brief info - opens up window to view BFS, DFS, and MST
    //!
    //!
    Graph<QString> *graphs;


    void rebuildGraph();


    //!
    //! \brief isAdmin - keeps track of whether the user is an Admin
    //!
    bool isAdmin;

    displayGraphs *getGraphs;

    QVector<QString> nameList;
    QVector<QString> tempList;
    QVector<QString> selectedList;
};
#endif // MAINWINDOW_H
