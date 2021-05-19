#include "modifyTeams.h"
#include "ui_modifyTeams.h"

// sets the maximum value for the spin boxes
const int MAXIMUM = 1000000000;

/*************************************************************************
 * modifyTeams(QWidget *parent, manageDB* getDataBase)
 * -----------------------------------------------------------------------
 * Sets the database if the conncection is null. Populates the combo boxes
 * with the team information and sets the rest of the team information by team
 * name
 ************************************************************************/
modifyTeams::modifyTeams(QWidget *parent, manageDB* getDataBase) :
    QDialog(parent),
    ui(new Ui::modifyTeams)
{
    ui->setupUi(this);
    database = getDataBase;

    // Checks if database is null
    if (database == nullptr)
    {
         // Sets new connection to database.
         const QString FILE_NAME = "mlbTeams.db";
         QString dbPath = qApp->applicationDirPath();
         dbPath.append('/' + FILE_NAME);
         database = new manageDB(dbPath);
         qDebug() << "Database should be located at: " << dbPath;
    }

    // populates the team combo box with the team name
    ui->teamsComboBox->clear();
    for (auto &i: database->getTeamNames())
    {
        ui->teamsComboBox->addItem(i);
    }

    ui->leagueComboBox->clear();

    for (auto &i: database->getLeague())
    {
        ui->leagueComboBox->addItem(i);
    }

    // populates the roof combo box with the different roof types
    ui->roofComboBox->clear();
    for (auto &i: database->getRoofTypes())
    {
        ui->roofComboBox->addItem(i);
    }

    // populates the surface combo box with the different playing surfaces
    ui->surfaceComboBox->clear();
    for (auto &i: database->getSurfaces())
    {
        ui->surfaceComboBox->addItem(i);
    }

    // populates the typology combo box with the different typologies
    ui->typologyComboBox->clear();
    for (auto &i: database->getTypology())
    {
        ui->typologyComboBox->addItem(i);
    }

    // sets the capacity for the spin boxes and sets the value for each combo and spin boxes
    ui->seatingspinBox->setMaximum(MAXIMUM);
    ui->datespinBox->setMaximum(MAXIMUM);
    ui->distancespinBox->setMaximum(MAXIMUM);

    // changes the team information based on team name
    on_teamsComboBox_currentIndexChanged(ui->teamsComboBox->currentText());

}

modifyTeams::~modifyTeams()
{
    delete ui;
    database = nullptr;
}

/*************************************************************************
 * void on_modify_clicked()
 * -----------------------------------------------------------------------
 * Allows the Administrator to modify team information including stadium name,
 * seating capacity, location, playing surface, roof types, ballpark typology,
 * Date opened, and Distance to Center Field
 ************************************************************************/
void modifyTeams::on_modify_clicked()
{
    // initializes variables
    QString teams;
    QString stadName;
    QString location;
    QString roofs;
    QString surface;
    QString league;
    QString typology;
    int seatingCapacity;
    int dateOpened;
    int centerDistance;

    // assigns variables
    teams = ui->teamsComboBox->currentText();
    stadName = ui->stadiumLineEdit->text();
    location = ui->locationLineEdit->text();
    roofs = ui->roofComboBox->currentText();
    league = ui->leagueComboBox->currentText();
    surface = ui->surfaceComboBox->currentText();
    typology = ui->typologyComboBox->currentText();
    seatingCapacity = ui->seatingspinBox->value();
    dateOpened = ui->datespinBox->value();
    centerDistance = ui->distancespinBox->value();

    // Different Test Cases: Case 1: Date opened is 0 or less
    if (dateOpened <= 0)
    {
        QMessageBox::information(this, "Error", "Invalid Date Opened. Must be greater than 0");
    }
    // Case 2: SeatingCapacity for a stadium is 0 or less
    else if (seatingCapacity <= 0)
    {
        QMessageBox::information(this, "Error", "Invalid Seating Capacity. Must be greater than 0");
    }
    // Case 3: Nothing is entered for a stadium name
    else if (stadName == "")
    {
        QMessageBox::information(this, "Error", "Must Enter a Stadium Name");
    }
    // Case 4: Nothing is entered for a location
    else if (location == "")
    {
        QMessageBox::information(this, "Error", "Must enter a location");
    }
    // Case 5: Distance to Center Field is 0 or less
    else if (centerDistance <= 0)
    {
        QMessageBox::information(this, "Error", "Invalid center to distance. Must be greater than 0");
    }

    // gets the meters of the distance to center field
    int meters = qRound(double(centerDistance) / 3.281);

    // converts the int value to string
    QString center = QString::number(centerDistance);
    center.append(" feet (" + QString::number(meters) + "m)");

    // updates team information
    database->updateTeams(teams, stadName, seatingCapacity, location, league, surface, dateOpened, center, typology, roofs);

}

/*************************************************************************
 * void on_addTeam_clicked()
 * -----------------------------------------------------------------------
 * Allows the Administrator to add team information, souvenirs, and its distances
 * by a text file.
 ************************************************************************/
void modifyTeams::on_addTeam_clicked()
{
    // Team information
    string team;
    string stadium;
    int seatingCapacity;
    string location;
    string surface;
    string league;
    int dateOpened;
    string distToCentField;
    string typology;
    string roof;

    // Souvenir Information
    string souvenir1;
    double price1;
    string souvenir2;
    double price2;
    string souvenir3;
    double price3;
    string souvenir4;
    double price4;
    string souvenir5;
    double price5;

    // Distance Information
    string destination1;
    double mileage1;
    string destination2;
    double mileage2;
    string destination3;
    double mileage3;

    // opens up file on computer
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/Downloads", tr("Txt Files (*.txt)"));
    QFile file(fileName);

    ifstream inFile;
    inFile.open(fileName.toStdString());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, QObject::tr("System Message"), tr("File cannot be found. Add a different file"));
    }
    else
    {
        /*

        QSqlQuery query;
        bool success;

        query.prepare("DELETE FROM TEAMS WHERE TeamName=:TEAM");
        query.bindValue(":TEAM", "Las Vegas Gamblers");

        // qDebug() << "bound: " << query.boundValues();

        success = query.exec();

        if(!success) {
            qDebug() << "removeSouvenir error: " << query.lastError();
        }

        QSqlQuery query2;
        bool success2;

        query.prepare("DELETE FROM SOUVENIRS WHERE Team=:TEAM");
        query.bindValue(":TEAM", "Las Vegas Gamblers");

        // qDebug() << "bound: " << query.boundValues();

        success2 = query.exec();

        if(!success2) {
            qDebug() << "removeSouvenir error: " << query.lastError();
        }

        QSqlQuery query3;
        bool success3;

        query.prepare("DELETE FROM DISTANCES WHERE Starting=:Stadium");
        query.bindValue(":Stadium", "Las Vegas Stadium");

        // qDebug() << "bound: " << query.boundValues();

        success3 = query.exec();

        if(!success3) {
            qDebug() << "removeSouvenir error: " << query.lastError();
        }

        QSqlQuery query4;
        bool success4;

        query.prepare("DELETE FROM DISTANCES WHERE Ending=:Stadium");
        query.bindValue(":Stadium", "Las Vegas Stadium");

        // qDebug() << "bound: " << query.boundValues();

        success4 = query.exec();

        if(!success4) {
            qDebug() << "removeSouvenir error: " << query.lastError();
        }
        */

        // reads in the file information
        while (!inFile.eof() && inFile.peek() != '\n')
        {
            // reads the team information
            getline(inFile, team);
            getline(inFile, stadium);
            inFile >> seatingCapacity;
            inFile.ignore();
            getline(inFile, location);
            getline(inFile, surface);
            getline(inFile, league);
            inFile >> dateOpened;
            inFile.ignore();
            getline(inFile, distToCentField);
            getline(inFile, typology);
            getline(inFile, roof);

            // Reads in souvenir information
            getline(inFile, souvenir1);
            inFile >> price1;
            inFile.ignore();
            getline(inFile, souvenir2);
            inFile >> price2;
            inFile.ignore();
            getline(inFile, souvenir3);
            inFile >> price3;
            inFile.ignore();
            getline(inFile, souvenir4);
            inFile >> price4;
            inFile.ignore();
            getline(inFile, souvenir5);
            inFile >> price5;
            inFile.ignore();

            // Reads in the distance information
            getline(inFile, destination1);
            inFile >> mileage1;
            inFile.ignore();
            getline(inFile, destination2);
            inFile >> mileage2;
            inFile.ignore();
            getline(inFile, destination3);
            inFile >> mileage3;

            QString teamName = QString::fromStdString(team);
            QString stadiumName = QString::fromStdString(stadium);


            // Checks if team exists. Breaks out of function
            if (database->teamExists(teamName))
            {
                break;
            }

            // Converts the team information strings into QStrings
             QString locationName = QString::fromStdString(location);
             QString surfaceType = QString::fromStdString(surface);
             QString leagueType = QString::fromStdString(league);
             QString centField = QString::fromStdString(distToCentField);
             QString ballTypology = QString::fromStdString(typology);
             QString roofType = QString::fromStdString(roof);

            // Adds the team information to the database
            database->addTeam(teamName, stadiumName, seatingCapacity, locationName, surfaceType, leagueType, dateOpened, centField, ballTypology, roofType);

            // Converts the team souvenir names into QStrings
            QString teamSouvenir1 = QString::fromStdString(souvenir1);
            QString teamSouvenir2 = QString::fromStdString(souvenir2);
            QString teamSouvenir3 = QString::fromStdString(souvenir3);
            QString teamSouvenir4 = QString::fromStdString(souvenir4);
            QString teamSouvenir5 = QString::fromStdString(souvenir5);

            // Adds each souvenir into the database
            database->addTeamSouvenirs(teamName, stadiumName, teamSouvenir1, price1);
            database->addTeamSouvenirs(teamName, stadiumName,teamSouvenir2, price2);
            database->addTeamSouvenirs(teamName, stadiumName,teamSouvenir3, price3);
            database->addTeamSouvenirs(teamName, stadiumName,teamSouvenir4, price4);
            database->addTeamSouvenirs(teamName, stadiumName,teamSouvenir5, price5);

            // Converts the ending stadiums to QStrings
            QString endingStadium1 = QString::fromStdString(destination1);
            QString endingStadium2 = QString::fromStdString(destination2);
            QString endingStadium3 = QString::fromStdString(destination3);

            // Adds the new team distances into the database
            database->addTeamDistances(stadiumName, endingStadium1, mileage1);
            database->addTeamDistances(stadiumName, endingStadium2, mileage2);
            database->addTeamDistances(stadiumName, endingStadium3, mileage3);
            database->addTeamDistances(endingStadium1, stadiumName, mileage1);
            database->addTeamDistances(endingStadium2, stadiumName, mileage2);
            database->addTeamDistances(endingStadium3, stadiumName, mileage3);  

        }
        // Closes the file
        inFile.close();
    }

}

/*************************************************************************
 * void on_teamsComboBox_currentIndexChanged(const QString& arg1)
 * -----------------------------------------------------------------------
 * Sets the current team information based on the value of arg1
 ************************************************************************/
void modifyTeams::on_teamsComboBox_currentIndexChanged(const QString& arg1)
{
   // sets all the information for each team
   ui->stadiumLineEdit->setText(database->getStadiumName(arg1));
   ui->locationLineEdit->setText(database->getLocation(arg1));
   ui->seatingspinBox->setValue(database->seatingCapacity(arg1));
   ui->datespinBox->setValue(database->dateOpened(arg1));
   ui->roofComboBox->setCurrentText(database->setRoofType(arg1));
   ui->leagueComboBox->setCurrentText(database->setLeague(arg1));
   ui->surfaceComboBox->setCurrentText(database->setSurfaceType(arg1));
   ui->typologyComboBox->setCurrentText(database->setTypology(arg1));
   ui->distancespinBox->setValue(database->getDistToCentField(arg1));
}

/*************************************************************************
 * void on_surfaceComboBox_currentIndexChanged(const QString& arg1)
 * -----------------------------------------------------------------------
 * Allows the Administrator to select a different playing surface
 ************************************************************************/
void modifyTeams::on_surfaceComboBox_currentIndexChanged(const QString& arg1)
{

}

/*************************************************************************
 * void on_typologyComboBox_currentIndexChanged(const QString& arg1)
 * -----------------------------------------------------------------------
 * Allows the Administrator to select a different typology for a team
 ************************************************************************/
void modifyTeams::on_typologyComboBox_currentIndexChanged(const QString& arg1)
{

}

/*************************************************************************
 * void on_roofComboBox_currentIndexChanged(const QString& arg1)
 * -----------------------------------------------------------------------
 * Allows the Administrator to select a different roof type for a team
 ************************************************************************/
void modifyTeams::on_roofComboBox_currentIndexChanged(const QString& arg1)
{

}

