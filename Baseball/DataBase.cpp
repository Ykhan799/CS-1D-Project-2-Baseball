#include "DataBase.h"
#include "ui_DataBase.h"

DataBase::DataBase(manageDB* db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataBase)
{
    ui->setupUi(this);
    database = db;

    // populates the comboBox for viewing Teams
    for (auto &i: database->getTeamNames())
    {
        ui->TeamcomboBox->addItem(i);
    }
}

DataBase::~DataBase()
{
    delete ui;
}

/*************************************************************************
 * void on_viewTeam_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team Name, Stadium Name,
 * Stadium Capacity, Location, Playing Surface, League, Date Opened,
 * Distance to Center Field, BallPark Typology, and Roof Type for any Team.
 ************************************************************************/
void DataBase::on_viewTeam_clicked()
{
    // Checks if Team is not selected
    if (ui->TeamcomboBox->currentText() == "")
    {
        QMessageBox::warning(this, "Error", "Please select a Team.");
    }

    else
    {
        // gets the Team name and individual information for each team
       QString name = ui->TeamcomboBox->currentText();
       auto model = database->getTeamModel(name);

       // Creates the columns before information is displayed
       QString columnNames[] = {"Team Name", "Stadium Name", "Stadium Capacity", "Location", "Playing Surface", "League", "Date Opened", "Distance to Center Field", "BallPark Typology", "Roof Type"};
       for(int i = 0; i < 10; i++)
       {
           model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
       }

       // Displays the Team and adjusts the columns
       ui->tableView->setModel(model);
       ui->tableView->setColumnWidth(0, 250);
       ui->tableView->setColumnWidth(1, 200);
       ui->tableView->setColumnWidth(2, 200);
       ui->tableView->setColumnWidth(3, 200);
       ui->tableView->setColumnWidth(4, 200);
       ui->tableView->setColumnWidth(5, 200);
       ui->tableView->setColumnWidth(6, 200);
       ui->tableView->setColumnWidth(7, 200);
       ui->tableView->setColumnWidth(8, 200);
       ui->tableView->setColumnWidth(9, 200);
   }
}

/*************************************************************************
 * void on_TeamStadiumByTeam_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * by Team Name.
 ************************************************************************/
void DataBase::on_TeamStadiumByTeam_clicked()
{
    // Gets the sorted team and stadium names
    auto model = database->getTeamsSortedbyTeams();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name"};
    for (int i = 0; i < 2; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team and stadium names and adjusts the column widths
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 325);
    ui->tableView->setColumnWidth(1, 325);
}

/*************************************************************************
 * void on_TeamStadiumByStadium_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * by Stadium Name.
 ************************************************************************/
void DataBase::on_TeamStadiumByStadium_clicked()
{
    // Gets the sorted team and stadium names
    auto model = database->getTeamsSortedbyStadiums();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name"};
    for (int i = 0; i < 2; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team and stadium names and adjusts the column widths
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 325);
    ui->tableView->setColumnWidth(1, 325);
}


/*************************************************************************
 * void on_TeamStadiumByDate_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * from date opened. Oldest stadiums and teams are displayed at the top while
 * the newer stadiums and teams are displayed at the bottom.
 ************************************************************************/
void DataBase::on_TeamStadiumByDate_clicked()
{
    // Gets the sorted team and stadium names by date
    auto model = database->getTeamsbyDate();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "Date Opened"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and Date Opened, and adjusts the column widths
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 216);
    ui->tableView->setColumnWidth(1, 216);
    ui->tableView->setColumnWidth(2, 216);
}

/*************************************************************************
 * void on_TeamStadiumBySmallDistCtrField_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * with the smallest distance to the center field.
 ************************************************************************/
void DataBase::on_TeamStadiumBySmallDistCtrField_clicked()
{
    // Gets the sorted team and stadium names by smallest distance to center field
    auto model = database->getTeamsbySmallDistToCenterField();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "Distance to Center Field(Smallest)"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and Date Opened, and adjusts the column widths
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 216);
    ui->tableView->setColumnWidth(1, 216);
    ui->tableView->setColumnWidth(2, 216);
}

/*************************************************************************
 * void on_TeamStadiumByLargeDistCtrField_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * with the largest distance to the center field.
 ************************************************************************/
void DataBase::on_TeamStadiumByLargeDistCtrField_clicked()
{
    // Gets the sorted team and stadium names by largest distance to center field
    auto model = database->getTeamsbyLargeDistToCenterField();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "Distance to Center Field(Largest)"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and Date Opened, and adjusts the column widths
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 216);
    ui->tableView->setColumnWidth(1, 216);
    ui->tableView->setColumnWidth(2, 216);
}

/*************************************************************************
 * void on_AmericanLeagueTeams_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * that play in the American League sorted by team names.
 ************************************************************************/
void DataBase::on_AmericanLeagueTeams_clicked()
{
    // Gets the sorted team and stadium names that play in the American League
    auto model = database->getAmericanLeagueTeams();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "League"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and Date Opened, and adjusts the column widths
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 216);
    ui->tableView->setColumnWidth(1, 216);
    ui->tableView->setColumnWidth(2, 216);
}

/*************************************************************************
 * void on_NationalLeagueTeams_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * that play in the National League sorted by stadium names.
 ************************************************************************/
void DataBase::on_NationalLeagueTeams_clicked()
{
    // Gets the sorted team and stadium names that play in the National League
    auto model = database->getNationalLeagueTeams();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "League"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and Date Opened, and adjusts the column widths
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 216);
    ui->tableView->setColumnWidth(1, 216);
    ui->tableView->setColumnWidth(2, 216);
}
