#include "modifyTeams.h"
#include "ui_modifyTeams.h"

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

    //ui->locationLineEdit->setText(database->getLocation(ui->teamsComboBox->currentText()));
}

modifyTeams::~modifyTeams()
{
    delete ui;
}

void modifyTeams::on_modify_clicked()
{
    QString teams;
    QString stadName;
    QString location;
    QString roofs;
    QString surface;
    QString typology;
    int seatingCapacity;
    int dateOpened;
    int centerDistance;

    teams = ui->teamsComboBox->currentText();
    stadName = ui->stadiumLineEdit->text();
    location = ui->locationLineEdit->text();
    roofs = ui->roofComboBox->currentText();
    surface = ui->surfaceComboBox->currentText();
    typology = ui->typologyComboBox->currentText();
    seatingCapacity = ui->seatingspinBox->value();
    dateOpened = ui->datespinBox->value();
    centerDistance = ui->distancespinBox->value();
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
            database->addTeamSouvenirs(teamName, teamSouvenir1, price1);
            database->addTeamSouvenirs(teamName, teamSouvenir2, price2);
            database->addTeamSouvenirs(teamName, teamSouvenir3, price3);
            database->addTeamSouvenirs(teamName, teamSouvenir4, price4);
            database->addTeamSouvenirs(teamName, teamSouvenir5, price5);

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

void modifyTeams::on_teamsComboBox_currentIndexChanged(const QString& arg1)
{
    ui->locationLineEdit->setText(database->getLocation(arg1));
}

void modifyTeams::on_surfaceComboBox_currentIndexChanged(const QString& arg1)
{
    ui->surfaceComboBox->clear();
}

void modifyTeams::on_typologyComboBox_currentIndexChanged(const QString& arg1)
{
    ui->typologyComboBox->clear();
}

void modifyTeams::on_roofComboBox_currentIndexChanged(const QString& arg1)
{
    ui->roofComboBox->clear();
}
