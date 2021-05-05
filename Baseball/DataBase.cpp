#include "DataBase.h"
#include "ui_DataBase.h"

DataBase::DataBase(manageDB* db, bool adminUser, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataBase)
{
    ui->setupUi(this);
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
    database = db;
    isAdmin = adminUser;

    if (!isAdmin)
    {
        ui->modifySouvenirs->setVisible(false);
        ui->modifyteams->setVisible(false);
    }
    else
    {
        ui->modifySouvenirs->setVisible(true);
        ui->modifyteams->setVisible(true);
    }

    // populates the comboBox for viewing Teams
    for (auto &i: database->getTeamNames())
    {
        ui->TeamcomboBox->addItem(i);
        ui->Souvenircombobox->addItem(i);
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
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
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
       ui->TeamtableView->setModel(model);
       ui->TeamtableView->setColumnWidth(0, 250);
       ui->TeamtableView->setColumnWidth(1, 200);
       ui->TeamtableView->setColumnWidth(2, 200);
       ui->TeamtableView->setColumnWidth(3, 200);
       ui->TeamtableView->setColumnWidth(4, 200);
       ui->TeamtableView->setColumnWidth(5, 200);
       ui->TeamtableView->setColumnWidth(6, 200);
       ui->TeamtableView->setColumnWidth(7, 200);
       ui->TeamtableView->setColumnWidth(8, 200);
       ui->TeamtableView->setColumnWidth(9, 200);
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
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
    // Gets the sorted team and stadium names
    auto model = database->getTeamsSortedbyTeams();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name"};
    for (int i = 0; i < 2; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team and stadium names and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 325);
    ui->TeamtableView->setColumnWidth(1, 325);
}

/*************************************************************************
 * void on_TeamStadiumByStadium_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * by Stadium Name.
 ************************************************************************/
void DataBase::on_TeamStadiumByStadium_clicked()
{
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
    // Gets the sorted team and stadium names
    auto model = database->getTeamsSortedbyStadiums();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Stadium Name", "Team Name"};
    for (int i = 0; i < 2; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team and stadium names and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 325);
    ui->TeamtableView->setColumnWidth(1, 325);
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
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
    // Gets the sorted team and stadium names by date
    auto model = database->getTeamsbyDate();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "Date Opened"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and Date Opened, and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 216);
    ui->TeamtableView->setColumnWidth(1, 216);
    ui->TeamtableView->setColumnWidth(2, 216);
}

/*************************************************************************
 * void on_TeamStadiumBySmallDistCtrField_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * with the smallest distance to the center field.
 ************************************************************************/
void DataBase::on_TeamStadiumBySmallDistCtrField_clicked()
{
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
    // Gets the sorted team and stadium names by smallest distance to center field
    auto model = database->getTeamsbySmallDistToCenterField();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "Distance to Center Field(Smallest)"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and distance to denter field, and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 216);
    ui->TeamtableView->setColumnWidth(1, 216);
    ui->TeamtableView->setColumnWidth(2, 216);
}

/*************************************************************************
 * void on_TeamStadiumByLargeDistCtrField_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * with the largest distance to the center field.
 ************************************************************************/
void DataBase::on_TeamStadiumByLargeDistCtrField_clicked()
{
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
    // Gets the sorted team and stadium names by largest distance to center field
    auto model = database->getTeamsbyLargeDistToCenterField();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "Distance to Center Field(Largest)"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and distance to center field and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 216);
    ui->TeamtableView->setColumnWidth(1, 216);
    ui->TeamtableView->setColumnWidth(2, 216);
}

/*************************************************************************
 * void on_AmericanLeagueTeams_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * that play in the American League sorted by team names.
 ************************************************************************/
void DataBase::on_AmericanLeagueTeams_clicked()
{
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
    // Gets the sorted team and stadium names that play in the American League
    auto model = database->getAmericanLeagueTeams();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "League"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and League, and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 216);
    ui->TeamtableView->setColumnWidth(1, 232);
    ui->TeamtableView->setColumnWidth(2, 200);
}

/*************************************************************************
 * void on_NationalLeagueTeams_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * that play in the National League sorted by stadium names.
 ************************************************************************/
void DataBase::on_NationalLeagueTeams_clicked()
{
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
    // Gets the sorted team and stadium names that play in the National League
    auto model = database->getNationalLeagueTeams();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Stadium Name", "Team Name", "League"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and League, and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 216);
    ui->TeamtableView->setColumnWidth(1, 216);
    ui->TeamtableView->setColumnWidth(2, 216);
}

/*************************************************************************
 * void on_TeamStadiumByCapacity_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * sorted by seating capacity. The total seating capacity is also displayed.
 ************************************************************************/
void DataBase::on_TeamStadiumByCapacity_clicked()
{
    ui->seatingCapacity->setVisible(true);
    ui->totalSeats->setVisible(true);
    // Gets the sorted team and stadium names that play in the National League
    auto model = database->getTeamsBySeatingCapacity();

    auto models = database->getSeatingCapacity();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "Seating Capacity"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and seating capacity, and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 162);
    ui->TeamtableView->setColumnWidth(1, 224);
    ui->TeamtableView->setColumnWidth(2, 100);

    // Sets new header and dislays the total seating capacity
    model->setHeaderData(3, Qt::Horizontal, "Total Seating Capacity");
    ui->seatingCapacity->setText("Total Seating Capacity");
    ui->totalSeats->setText(QString::number(models, 10) + " Seats");
}

/*************************************************************************
 * void on_TeamStadiumByTypology_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * sorted by Ballpark Typology
 ************************************************************************/
void DataBase::on_TeamStadiumByTypology_clicked()
{
    ui->seatingCapacity->setVisible(false);
    ui->totalSeats->setVisible(false);
    // Gets the sorted team and stadium names sorted by Typology
    auto model = database->getTeamsByBallParkTypology();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "BallPark Typology"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and BallPark Typology, and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 216);
    ui->TeamtableView->setColumnWidth(1, 232);
    ui->TeamtableView->setColumnWidth(2, 200);
}

/*************************************************************************
 * void on_OpenRoofTeams_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the Team names and Stadium names
 * that have an open roof. Also displays the total number of teams with an open roof
 ************************************************************************/
void DataBase::on_OpenRoofTeams_clicked()
{
    ui->seatingCapacity->setVisible(true);
    ui->totalSeats->setVisible(true);
    // Gets the sorted team and stadium names with an Open Roof
    auto model = database->getTeamsWithOpenRoof();

    auto models = database->getNumOpenRoofs();

    // Creates the Headers before information is displayed
    QString columnNames[] = {"Team Name", "Stadium Name", "Roof Type"};
    for (int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the team, stadium names, and Roof Type, and adjusts the column widths
    ui->TeamtableView->setModel(model);
    ui->TeamtableView->setColumnWidth(0, 162);
    ui->TeamtableView->setColumnWidth(1, 224);
    ui->TeamtableView->setColumnWidth(2, 100);

    // Sets new header and Displaus the Numver of Teams with an Open Roof
    model->setHeaderData(3, Qt::Horizontal, "Total Number of Open Roofs");
    ui->seatingCapacity->setText("Teams with Open Roofs");
    ui->totalSeats->setText(QString::number(models, 10) + " Teams");
}

/*************************************************************************
 * void on_viewSouvenirs_clicked()
 * -----------------------------------------------------------------------
 * Lets a Baseball Fan or Administrator view the souvenir names and prices for
 * any team selected
 ************************************************************************/
void DataBase::on_viewSouvenirs_clicked()
{
    // Checks if Team is not selected
    if (ui->Souvenircombobox->currentText() == "")
    {
        QMessageBox::warning(this, "Error", "Please select a Team.");
    }

    else
    {
        // gets the Team name and souvenir information for each team
       QString name = ui->Souvenircombobox->currentText();
       auto model = database->getSouvenirsByTeam(name);

       // Creates the columns before information is displayed
       QString columnNames[] = {"Team Name", "Souvenir Name", "Price"};
       for(int i = 0; i < 3; i++)
       {
           model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
       }

       // Displays the Team and adjusts the columns
       ui->SouvenirTableView->setModel(model);
       ui->SouvenirTableView->setColumnWidth(0, 266);
       ui->SouvenirTableView->setColumnWidth(1, 266);
       ui->SouvenirTableView->setColumnWidth(2, 266);
   }
}

/*************************************************************************
 * void on_viewSouvenirs_clicked()
 * -----------------------------------------------------------------------
 * Lets an Administrator Add, Delete or modify a souvenir. Each of these changes
 * are saved into the database and is displayed to the baseball fan.
 ************************************************************************/
void DataBase::on_modifySouvenirs_clicked()
{
    // creates a new modifySouvenirs object
    modify = new modifySouvenirs(nullptr, database);
    modify->exec();
    delete modify;

    // Sets the model after each change.
    QString name = ui->Souvenircombobox->currentText();
    auto model = database->getSouvenirsByTeam(name);

    // Sets the header names
    QString columnNames[] = {"Team Name", "Souvenir Name", "Price"};
    for(int i = 0; i < 3; i++)
    {
        model->setHeaderData(i, Qt::Horizontal, columnNames[i]);
    }

    // Displays the Team and Souvenirs and adjusts the columns
    ui->SouvenirTableView->setModel(model);
    ui->SouvenirTableView->setColumnWidth(0, 266);
    ui->SouvenirTableView->setColumnWidth(1, 266);
    ui->SouvenirTableView->setColumnWidth(2, 266);
}

void DataBase::on_modifyteams_clicked()
{
    teamModify = new modifyTeams(nullptr, database);
    teamModify->exec();
    delete teamModify;
}

/*************************************************************************
 * void on_cancelView_clicked()
 * -----------------------------------------------------------------------
 * Lets an Administrator or Baseball fan exit viewing teams and souvenirs.
 ************************************************************************/
void DataBase::on_cancelView_clicked()
{
    this->close();
}
