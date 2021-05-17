#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // sets isAdmin to false and the Admin function to false
    isAdmin = false;
    ui->LogOut->setVisible(false);

    // Gets the name of the database
    const QString FILE_NAME = "mlbTeams.db";
    QString dbPath = qApp->applicationDirPath();
    dbPath.append('/' + FILE_NAME);

     // open database with file path
     data = new manageDB(dbPath);
     qDebug() << "Database should be located at: " << dbPath;
     graphs = nullptr;
     rebuildGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete data;
}

/*************************************************************************
 * void on_LogIn_clicked()
 * -----------------------------------------------------------------------
 * Opens a window prompting for the user to enter a username and password.
 * If entered correctly, the user becomes an admin and is given special
 * privileges for the remainder of the program unless the user logs out.
 * -----------------------------------------------------------------------
 * Username: Admin or admin
 *
 * Valid passwords:
 * Teqnify1894
 * password
 ************************************************************************/
void MainWindow::on_LogIn_clicked()
{
    // Shows the Login screen.
    admin = new login();
    admin->exec();

    // Checks if user is logged in
    isAdmin = admin->loggedIn();
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
    auto* marlins = new marlinsPath(nameList, this, graphs);
    marlins -> show();

}

/*************************************************************************
 * void on_viewTeamsSouvenirs_clicked()
 * -----------------------------------------------------------------------
 * Allows the baseball fan or administrator to view the information for
 * all baseball teams and souvenirs for each team.
 ************************************************************************/
void MainWindow::on_viewTeamsSouvenirs_clicked()
{
    // displays the database of teams and souvenirs
    database = new DataBase(nullptr, isAdmin);
    database->show();
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



void MainWindow::on_BFS_clicked()
{
    int start = graphs->startBFS("Target Field");
    QString pathStr;
        for (const auto &dest : graphs->bfsOrder) {
            pathStr += dest + "\n";
        }

        QMessageBox msgBox;
        msgBox.setText("BFS starting from Target Field (Minnesota Twins)");
        msgBox.setInformativeText("Total distance: " + QString::number(start));
        msgBox.setDetailedText(pathStr);
        msgBox.exec();
 }

void MainWindow::rebuildGraph()
{


    // populate vectors and comboBox
    nameList = data->startingStadiums();
    tempList = nameList;

    // populate graph
    if(graphs != nullptr) {
        delete graphs;
    }
    graphs = new Graph<QString>();
    vector<distanceEdge> edges;
    for (const QString &stadium : nameList) {
        qDebug() << "adding node:" << stadium;
        graphs->addNode(stadium);
    }
    for (const QString &stadium : nameList) {
        edges = data->getDistances(stadium);
        for (const auto &edge : edges) {
            qDebug() << "adding edge:" << edge.team_name_origin << edge.team_name_destination << edge.distance;
            graphs->addEdge(edge.team_name_origin, edge.team_name_destination,
                           edge.distance);
        }
    }

}

void MainWindow::on_DFS_clicked()
{
    int distance = graphs->startDFS("Oracle Park");
    QString pathStr;
    for (const auto &dest : graphs->dfsOrder) {
        pathStr += dest + "\n";
    }

    QMessageBox msgBox;
    msgBox.setText("DFS starting from Oracle Park (San Francisco Giants)");
    msgBox.setInformativeText("Total distance: " + QString::number(distance));
    msgBox.setDetailedText(pathStr);
    msgBox.exec();
}

void MainWindow::on_MST_clicked()
{
    int distance = graphs->startMST();
    QString pathStr = "MST Edges:\n";
    pathStr += graphs->mstString;

    QMessageBox msgBox;
    msgBox.setStyleSheet("QLabel{min-width: 400px;}");
    msgBox.setText("MST");
    msgBox.setInformativeText("Total distance: " + QString::number(distance));
    msgBox.setDetailedText(pathStr);
    msgBox.exec();
}
