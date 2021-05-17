#include "manageDB.h"

/*************************************************************************
 * manageDB(const QString& path)
 * -----------------------------------------------------------------------
 * Creates a path in order to access the database and use sqlite commands
 ************************************************************************/
manageDB::manageDB(const QString& path)
{
    // creates a path for the database
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(path);

    // Checks if the database can connect
    if(!DB.open())
    {
        qDebug() << "Error: could not connect to database.";
    }
    else
    {
        qDebug() << "Database connection OK";
    }
}

/*************************************************************************
 * QVector<QString> getTeamNames()
 * -----------------------------------------------------------------------
 * Gets all the team names from the database.
 ************************************************************************/
QVector<QString> manageDB::getTeamNames()
{
    // Gets the team names from the Database
    QVector<QString> teamName;
    QSqlQuery query("SELECT DISTINCT TeamName FROM TEAMS ORDER BY TeamName");

    // While query is not empty
    while(query.next())
    {
        // Pushes the team names into the QVector
        QString out = query.value(0).toString();
        teamName.push_back(out);
    }
    // returns a QVector of team names.
    return teamName;
}

QVector<QString> manageDB::getStadiumNames()
{
    // Gets the stadium names from the Database
    QVector<QString> stadName;
    QSqlQuery query("SELECT DISTINCT StadiumName FROM TEAMS ORDER BY StadiumName");

    // While query is not empty
    while(query.next())
    {
        // Pushes the names into the QVector
        QString out = query.value(0).toString();
        stadName.push_back(out);
    }
    // returns a QVector of stadium names.
    return stadName;
}

/*************************************************************************
 * QString getStadiumName(const QString& team)
 * -----------------------------------------------------------------------
 * Gets the stadium name for any team
 ************************************************************************/
QString manageDB::getStadiumName(const QString& team)
{
    // sets up the query to get the stadium name
    QString stadium = "";
    QString sQuery = "select stadiumName from TEAMS where TeamName = '" + team + "';";

    QSqlQuery query;
    query.prepare(sQuery);
    query.exec();

    // Checks if there is a value in the query
    if(query.next())
    {
        stadium = query.value(0).toString();
    }

    // returns the value of stadium
    return stadium;
}

/*************************************************************************
 * QString getLocation(const QString& team)
 * -----------------------------------------------------------------------
 * Gets the location for a team.
 ************************************************************************/
QString manageDB::getLocation(const QString& team)
{
    // sets up the query to get the location
    QString location = "";
    QString sQuery = "select Location from TEAMS where TeamName = '" + team + "';";

    QSqlQuery query;
    query.prepare(sQuery);
    query.exec();

    // Checks if there is a value in the query
    if(query.next())
    {
        location = query.value(0).toString();
    }

    // returns the value of location
    return location;
}

/*************************************************************************
 * int getSeatingCapacity()
 * -----------------------------------------------------------------------
 * Gets the sum of the seating capacity for the whole team
 ************************************************************************/
int manageDB::getSeatingCapacity()
{
    int totalCapacity = 0;

    // Gets the seating capacity for each team
    QSqlQuery query("SELECT SeatingCapacity FROM TEAMS");

    // Sums up the seating capacity for all baseball teams
    while (query.next())
    {
        int temp = query.value(0).toInt();
        totalCapacity += temp;
    }
    // returns an int of the seating capacity for all baseball teams
    return totalCapacity;

}

/*************************************************************************
 * int seatingCapacity(const QString& team)
 * -----------------------------------------------------------------------
 * Gets the seating capacity of a stadium for any baseball team
 ************************************************************************/
int manageDB::seatingCapacity(const QString& team)
{
    // sets up the query to find seating capacity
    int capacity = 0;
    QString sQuery = "select SeatingCapacity from TEAMS where TeamName = '" + team + "';";

    QSqlQuery query;
    query.prepare(sQuery);
    query.exec();

    // Checks if there is a value in the query
    if(query.next())
    {
        capacity = query.value(0).toInt();
    }

    // returns the value of capacity
    return capacity;
}

/*************************************************************************
* int dateOpened(const QString& team)
* -----------------------------------------------------------------------
* Gets the date opened for any team
************************************************************************/
int manageDB::dateOpened(const QString& team)
{
    // sets up the query to find date opened
    int date = 0;
    QString sQuery = "select DateOpened from TEAMS where TeamName = '" + team + "';";

    QSqlQuery query;
    query.prepare(sQuery);
    query.exec();

    // Checks if there is a value in the query
    if(query.next())
    {
        date = query.value(0).toInt();
    }

    // returns the value of date
    return date;
}

/*************************************************************************
* int getDistToCentField(const QString& team)
* -----------------------------------------------------------------------
* Gets the distance to center field in feet for any team
************************************************************************/
int manageDB::getDistToCentField(const QString& team)
{

    // sets up the query to find center to distance
    int center = 0;

    QString sQuery = "select DistToCentField from TEAMS where TeamName = '" + team + "';";

    QSqlQuery query;
    query.prepare(sQuery);
    query.exec();

    // Checks if there is a value in the query
    if(query.next())
    {
        // converts the string value into an int
        QString value = query.value(0).toString();
        QString temp = value.section(" ", 0, 0);
        center = temp.toInt();
    }

    // returns the value of center
    return center;
}


/*************************************************************************
 * int getNumOpenRoofs()
 * -----------------------------------------------------------------------
 * Gets the number of teams with an open roof.
 ************************************************************************/
int manageDB::getNumOpenRoofs()
{
    int openRoofs = 0;

    // Gets all the Open Roofs
    QSqlQuery query("SELECT RoofType FROM TEAMS WHERE RoofType = 'Open'");

    // Increments the roof
    while (query.next())
    {
        openRoofs+=1;
    }
    // returns number of open roofs
    return openRoofs;
}

/*************************************************************************
 * QVector<QString> getRoofTypes()
 * -----------------------------------------------------------------------
 * Gets the distinct different roof types for all the teams.
 ************************************************************************/
QVector<QString> manageDB::getRoofTypes()
{
    // Gets the roofs from the Database
    QVector<QString> roofs;
    QSqlQuery query("SELECT DISTINCT RoofType FROM TEAMS");

    // While query is not empty
    while(query.next())
    {
        // Pushes the roof names into the QVector
        QString out = query.value(0).toString();
        roofs.push_back(out);
    }
    // returns a QVector of roof names.
    return roofs;
}

/*************************************************************************
 * QString setRoofType(const QString& team)
 * -----------------------------------------------------------------------
 * Gets the roof type for any baseball team
 ************************************************************************/
QString manageDB::setRoofType(const QString& team)
{
    // sets up the query to get the roof type
    QString roof = "";
    QString sQuery = "select RoofType from TEAMS where TeamName = '" + team + "';";

    QSqlQuery query;
    query.prepare(sQuery);
    query.exec();

    // Checks if there is a value in the query
    if(query.next())
    {
        roof = query.value(0).toString();
    }

    // returns the value of roof
    return roof;
}

/*************************************************************************
 * QVector<QString> getSurfaces()
 * -----------------------------------------------------------------------
 * Gets the distinct surface types for all the teams
 ************************************************************************/
QVector<QString> manageDB::getSurfaces()
{
    // Gets the surface types from the Database
    QVector<QString> surface;
    QSqlQuery query("SELECT DISTINCT PlayingSurface FROM TEAMS");

    // While query is not empty
    while(query.next())
    {
        // Pushes the surface names into the QVector
        QString out = query.value(0).toString();
        surface.push_back(out);
    }
    // returns a QVector of surface names.
    return surface;
}

/*************************************************************************
* QString setSurfaceType(const QString& team)
* -----------------------------------------------------------------------
* Gets the surface type for any team
************************************************************************/
QString manageDB::setSurfaceType(const QString& team)
{
    // sets up the query to get the surface type
    QString surfaces = "";
    QString sQuery = "select PlayingSurface from TEAMS where TeamName = '" + team + "';";

    QSqlQuery query;
    query.prepare(sQuery);
    query.exec();

    // Checks if there is a value in the query
    if(query.next())
    {
        surfaces = query.value(0).toString();
    }

    // returns the value of surfaces
    return surfaces;
}

/*************************************************************************
 * QVector<QString> getTypology()
 * -----------------------------------------------------------------------
 * Gets the distinct typology types for all the teams
 ************************************************************************/
QVector<QString> manageDB::getTypology()
{
    // Gets the typology types from the Database
    QVector<QString> surface;
    QSqlQuery query("SELECT DISTINCT BallparkTypology FROM TEAMS");

    // While query is not empty
    while(query.next())
    {
        // Pushes the typology names into the QVector
        QString out = query.value(0).toString();
        surface.push_back(out);
    }
    // returns a QVector of typology names.
    return surface;
}

/*************************************************************************
* QString setTypology(const QString& team)
* -----------------------------------------------------------------------
* Gets the typology for any team
************************************************************************/
QString manageDB::setTypology(const QString& team)
{
    // sets up the query to get the typology type
    QString typology = "";
    QString sQuery = "select BallparkTypology from TEAMS where TeamName = '" + team + "';";

    QSqlQuery query;
    query.prepare(sQuery);
    query.exec();

    // Checks if there is a value in the query
    if(query.next())
    {
        typology = query.value(0).toString();
    }

    // returns the value of typology
    return typology;
}

/*************************************************************************
 * QSqlQueryModel* getTeamModel(const QString& team)
 * -----------------------------------------------------------------------
 * Gets the specific information for a team such as the stadium name, location,
 * seating capacity, team league, and more from the database. Returns a model
 * containing the information for a team.
 ************************************************************************/
QSqlQueryModel* manageDB::getTeamModel(const QString& team)
{
    // creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the information for a team
    query.prepare("SELECT TeamName, StadiumName, SeatingCapacity, Location, PlayingSurface, TeamLeague, DateOpened, DistToCentField, BallparkTypology, RoofType FROM TEAMS WHERE TeamName = :TeamName");
    query.bindValue(":TeamName", team);
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getTeamsSortedByTeams()
 * -----------------------------------------------------------------------
 * Gets all the stadiums and teams from the database and sorts it by teams.
 * Returns a model containing a sorted teams and stadiums by stadium name.
 ************************************************************************/
QSqlQueryModel* manageDB::getTeamsSortedbyTeams()
{
    // creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team and stadium names from the database
    query.prepare("SELECT TeamName, StadiumName FROM TEAMS ORDER BY TeamName");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getTeamsSortedByStadiums()
 * -----------------------------------------------------------------------
 * Gets all the stadiums and teams from the database and sorts it by stadiums.
 * Returns a model containing a sorted teams and stadiums by stadium name.
 ************************************************************************/
QSqlQueryModel* manageDB::getTeamsSortedbyStadiums()
{
    // Creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team and stadium names from the database
    query.prepare("SELECT StadiumName, TeamName FROM TEAMS ORDER BY StadiumName");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getTeamsbyDate()
 * -----------------------------------------------------------------------
 * Gets all the stadiums and teams from the database and sorts it by oldest
 * date opened to newest date opened.
 ************************************************************************/
QSqlQueryModel* manageDB::getTeamsbyDate()
{
    // Creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team, stadium names, and date opened from the database
    query.prepare("SELECT TeamName, StadiumName, DateOpened FROM TEAMS ORDER BY DateOpened");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getTeamsbySmallDistToCenterField()
 * -----------------------------------------------------------------------
 * Gets all the stadiums and teams with smallest distance to center field.
 ************************************************************************/
QSqlQueryModel* manageDB::getTeamsbySmallDistToCenterField()
{
    // Creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team, stadium names, and smallest distance to center field
    query.prepare("SELECT TeamName, StadiumName, DistToCentField FROM TEAMS WHERE DistToCentField = (SELECT MIN(DistToCentField) FROM TEAMS)");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getTeamsbyLargeDistToCenterField()
 * -----------------------------------------------------------------------
 * Gets all the stadiums and teams with Largest distance to the center field
 ************************************************************************/
QSqlQueryModel* manageDB::getTeamsbyLargeDistToCenterField()
{
    // Creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team, stadium names, and largest distance to center field
    query.prepare("SELECT TeamName, StadiumName, DistToCentField FROM TEAMS WHERE DistToCentField = (SELECT MAX(DistToCentField) FROM TEAMS)");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getAmericanLeagueTeams()
 * -----------------------------------------------------------------------
 * Gets all the teams and corresponding stadium names sorted by team name
 * that play in the American League
 ************************************************************************/
QSqlQueryModel* manageDB::getAmericanLeagueTeams()
{
    // Creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team, stadium names that play in the American League
    query.prepare("SELECT TeamName, StadiumName, TeamLeague FROM TEAMS WHERE TeamLeague = 'American' ORDER BY TeamName");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getAmericanLeagueTeams()
 * -----------------------------------------------------------------------
 * Gets all the teams and corresponding stadium names sorted by stadium name
 * that play in the National League
 ************************************************************************/
QSqlQueryModel* manageDB::getNationalLeagueTeams()
{
    // Creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team, stadium names that play in the National League
    query.prepare("SELECT StadiumName, TeamName, TeamLeague FROM TEAMS WHERE TeamLeague = 'National' ORDER BY StadiumName");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getTeamsBySeatingCapacity()
 * -----------------------------------------------------------------------
 * Gets all the teams and corresponding stadium names sorted from smallest
 * seating capacity to largest seating capacity.
 ************************************************************************/
QSqlQueryModel* manageDB::getTeamsBySeatingCapacity()
{
    // Creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team, stadium names, and sorts by seating capacity for each team
    query.prepare("SELECT TeamName, StadiumName, SeatingCapacity FROM TEAMS ORDER BY SeatingCapacity");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getTeamsByBallParkTypology()
 * -----------------------------------------------------------------------
 * Gets all the teams and corresponding stadium names sorted by BallPark
 * Typology
 ************************************************************************/
QSqlQueryModel* manageDB::getTeamsByBallParkTypology()
{
    // Creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team, stadium names, and sorts by BallPark Typology for each team
    query.prepare("SELECT TeamName, StadiumName, BallparkTypology FROM TEAMS ORDER BY BallparkTypology");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getTeamsWithOpenRoof()
 * -----------------------------------------------------------------------
 * Gets all the teams and corresponding stadium names with an Open Roof Type.
 ************************************************************************/
QSqlQueryModel* manageDB::getTeamsWithOpenRoof()
{
    // Creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the team, stadium names that have an open roof
    query.prepare("SELECT TeamName, StadiumName, RoofType FROM TEAMS WHERE RoofType = 'Open' ORDER BY TeamName");
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QSqlQueryModel* getSouvenirsByTeam(const QString& team)
 * -----------------------------------------------------------------------
 * Gets all the souvenirs for a team based on the value of team.
 ************************************************************************/
QSqlQueryModel* manageDB::getSouvenirsByTeam(const QString& team)
{
    // creates a new model
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    // Gets the information for team, stadium, souvenir, and price
    query.prepare("SELECT Team, Souvenir, Price FROM SOUVENIRS WHERE Team = :Team");
    query.bindValue(":Team", team);
    query.exec();

    // Assigned to the model and is returned
    model->setQuery(query);
    return model;
}

/*************************************************************************
 * QVector<QString> getTeamSouvenirs(const QString& team)
 * -----------------------------------------------------------------------
 * This function gets all the souvenirs for a given team.
 ************************************************************************/
QVector<QString> manageDB::getTeamSouvenirs(const QString& team)
{
    QVector<QString> souvenirs;
    QSqlQuery query;

    // query database for souvenirs by campus
    query.prepare("SELECT Souvenir FROM SOUVENIRS WHERE Team = :team");
    query.bindValue(":team", team);

    query.exec();

     // add souvenir names to QVector
    while(query.next()) {
        QString out = query.value(0).toString();
        souvenirs.push_back(out);
    }

    return souvenirs;
}

/*************************************************************************
 * void getSouvenirPrice(const QString& souvenir, const QString& team)
 * -----------------------------------------------------------------------
 * This function gets the price of a given souvenir.
 ************************************************************************/
double manageDB::getSouvenirPrice(const QString& souvenir, const QString& team)
{
    QSqlQuery query;

    // Gets the price for a souvenir name and team name
    query.prepare("SELECT PRICE FROM SOUVENIRS WHERE Souvenir = :SOUVENIR AND Team = :Team");
    query.bindValue(":SOUVENIR", souvenir);
    query.bindValue(":Team", team);
    query.exec();

    // Returns the price
    if(query.next()) {

        // QString out = query.value(0).toString();
        // qDebug() << "souvenir price: " << out;

        return query.value(0).toDouble();
    }else {
        // Returns -1
        qDebug() << "No Result.";
        return -1;
    }
}

/*************************************************************************
 * void addSouvenir(const QString& team, const QString& souvenirName, const double& price)
 * -----------------------------------------------------------------------
 * This function allows the administrator to add a souvenir to the database.
 ************************************************************************/
void manageDB::addSouvenir(const QString& team, const QString& souvenirName, const double& price)
{
    QSqlQuery query;
    int maxID;
    bool success;

    QString stadium = getStadiumName(team);
    query.prepare("SELECT MAX(ID) from SOUVENIRS"); // get the maximum id from the table
    query.exec();

    // get the highest id from the bottom row of the table
    if(query.next()) {
        maxID =  query.value(0).toInt();
        maxID++;
        qDebug() << maxID;

        // Inserts the souvenir into the database
        query.prepare("INSERT INTO SOUVENIRS(ID, Team, Stadium, Souvenir, Price) VALUES(:ID, :Team, :Stadium, :Souvenir, :Price)");
        query.bindValue(":ID", maxID); // id is the id of the bottom row + 1
        query.bindValue(":Team", team);
        query.bindValue(":Stadium", stadium);
        query.bindValue(":Souvenir", souvenirName);
        query.bindValue(":Price", price);

        success = query.exec();

        if(!success) {
            qDebug() << "addSouvenir error: " << query.lastError();
        }

    } else {
        qDebug() << "Error: addSouvenir did not get an ID value from the table.";
    }

}

/*************************************************************************
 * void removeSouvenir(const QString& team, const QString& souvenirName)
 * -----------------------------------------------------------------------
 * This function removes a Souvenir from the database.
 ************************************************************************/
void manageDB::removeSouvenir(const QString& team, const QString& souvenirName)
{
    QSqlQuery query;
    bool success;

    // Removes the souvenir based on the team name and souvenirName
    query.prepare("DELETE FROM SOUVENIRS WHERE Team = :TEAM AND Souvenir = :SOUVENIRNAME");
    query.bindValue(":TEAM", team);
    query.bindValue(":SOUVENIRNAME", souvenirName);

    // qDebug() << "bound: " << query.boundValues();

    success = query.exec();

    if(!success) {
        qDebug() << "removeSouvenir error: " << query.lastError();
    }
}

/*************************************************************************
 * bool souvExists(const QString& team, const QString& souvenirName)
 * -----------------------------------------------------------------------
 * This function checks if a Souvenir is already in the database. Prevents the
 * administrator from adding duplicate souvenirs.
 ************************************************************************/
bool manageDB::souvExists(QString& team, QString& souvenirName)
{
    QSqlQuery query;
    bool success;
    bool found;

    // Selects one souvenir
    query.prepare("SELECT EXISTS(SELECT 1 FROM SOUVENIRS WHERE Team=:Team AND Souvenir=:Souvenir)");
    query.bindValue(":Team", team);
    query.bindValue(":Souvenir", souvenirName);

    success = query.exec();

    if(!success) {
          qDebug() << "souvExists error: " << query.lastError();
          return false;
    }

    // gets the first value
    query.first();
    found = query.value(0).toBool();

    // qDebug() << "found: " << found;

    return found;
}

/*************************************************************************
 * void updateSouvenirs(const QString& team, const QString& oldName, const QString& newName, const double& newPrice)
 * -----------------------------------------------------------------------
 * This function updates the souvenir's name or price. Allows the Administrator
 * to modify souvenirs
 ************************************************************************/
void manageDB::updateSouvenirs(const QString& team, const QString& oldName, const QString& newName, const double& newPrice)
{
    QSqlQuery query;
    bool success;

    // updates souvenir information
    query.prepare("UPDATE SOUVENIRS SET Price = :NEWPRICE, Souvenir = :NEWNAME WHERE Team = :TEAM AND Souvenir = :OLDNAME");
    query.bindValue(":NEWPRICE", newPrice);
    query.bindValue(":NEWNAME", newName);
    query.bindValue(":TEAM", team);
    query.bindValue(":OLDNAME", oldName);

    // qDebug() << "bound: " << query.boundValues();

    success = query.exec();

    if(!success) {
        qDebug() << "updateSouvenir error: " << query.lastError();
    }
}

/*************************************************************************
 * bool teamExists(const QString& team)
 * -----------------------------------------------------------------------
 * This function checks to see if a team is already in the database. Returns true
 * if the team is in the database. False is returned if the team is not in the
 * database. Prevents the administrator from adding a team if the team is in
 * the database.
 ************************************************************************/
bool manageDB::teamExists(const QString& team)
{
    QSqlQuery query;
    bool found;
    bool success;

    // Checks the database
    query.prepare("SELECT 1 FROM TEAMS WHERE TeamName=:TEAM");
    query.bindValue(":TEAM", team);

    success = query.exec();

    if(!success)
    {
        // team does not exist in database
        qDebug() << "teamExists error: " << query.lastError();
        found = false;
    }
    else
    {
        // team found in database
        query.first();
        found = query.value(0).toBool();
        qDebug() << found;
    }

    return found;
}

/*************************************************************************
 * void addTeam(const QString& team, const QString& stadium, const int& capacity, const QString& location, const QString& surface, const QString& league, const int& date, const QString& distance, const QString& typology, const QString& roof)
 * -----------------------------------------------------------------------
 * This function adds the team information for a new team
 ************************************************************************/
void manageDB::addTeam(const QString& team, const QString& stadium, const int& capacity, const QString& location, const QString& surface, const QString& league, const int& date, const QString& distance, const QString& typology, const QString& roof)
{
    QSqlQuery query;
    int maxID;
    bool success;

    query.prepare("SELECT max(ID) from TEAMS"); // get the maximum id from the table
    query.exec();

    // get the highest id from the bottom row of the table
    if(query.next()) {
        maxID =  query.value(0).toInt();
        maxID++;
        qDebug() << maxID;

        // Inserts the team information into the database
        query.prepare("INSERT INTO TEAMS VALUES(:ID, :TeamName, :StadiumName, :SeatingCapacity, :Location, :PlayingSurface, :TeamLeague, :DateOpened, :DistToCentField, :BallparkTypology, :RoofType)");
        query.bindValue(":ID", maxID); // id is the id of the bottom row + 1
        query.bindValue(":TeamName", team);
        query.bindValue(":StadiumName", stadium);
        query.bindValue(":SeatingCapacity", capacity);
        query.bindValue(":Location", location);
        query.bindValue(":PlayingSurface", surface);
        query.bindValue(":TeamLeague", league);
        query.bindValue(":DateOpened", date);
        query.bindValue(":DistToCentField", distance);
        query.bindValue(":BallparkTypology", typology);
        query.bindValue(":RoofType", roof);

        success = query.exec();

        if(!success) {
            qDebug() << "addTeam error: " << query.lastError();
        }

    } else {
        qDebug() << "Error: addTeam did not get an ID value from the table.";
    }
}

/*************************************************************************
 * void addTeamSouvenirs(const QString& team, const QString& souvenir, const double& price)
 * -----------------------------------------------------------------------
 * This function adds the souvenirs for each new team.
 ************************************************************************/
void manageDB::addTeamSouvenirs(const QString& team, const QString& souvenir, const double& price)
{
     QSqlQuery query;
     int maxID;
     bool success;

     query.prepare("SELECT max(ID) from SOUVENIRS"); // get the maximum id from the table
     query.exec();

     // get the highest id from the bottom row of the table
     if(query.next()) {
         maxID =  query.value(0).toInt();
         maxID++;
         qDebug() << maxID;

         // Inserts the ID, team name, souvenir name, and price
         query.prepare("INSERT INTO SOUVENIRS VALUES(:ID, :TEAM, :SOUVENIR, :PRICE)");
         query.bindValue(":ID", maxID); // id is the id of the bottom row + 1
         query.bindValue(":TEAM", team);
         query.bindValue(":SOUVENIR", souvenir);
         query.bindValue(":PRICE", price);

         success = query.exec();

         if(!success) {
             qDebug() << "addSouvenir error: " << query.lastError();
         }

     } else {
         qDebug() << "Error: addSouvenir did not get an ID value from the table.";
     }
}

/*************************************************************************
 * void addTeamDistances(const QString& startStadium, const QString& endStadium, const double& distances)
 * -----------------------------------------------------------------------
 * This function adds the distances for the new team into the database.
 ************************************************************************/
 void manageDB::addTeamDistances(const QString& startStadium, const QString& endStadium, const double& distances)
 {
     QSqlQuery query;
     int maxID;
     bool success;

     query.prepare("SELECT max(ID) from DISTANCES"); // get the maximum id from the table
     query.exec();

     // get the highest id from the bottom row of the table
     if(query.next()) {
         maxID =  query.value(0).toInt();
         maxID++;
         qDebug() << maxID;

         // Inserts the ID, starting stadium, ending stadium, and the distance between each stadium
         query.prepare("INSERT INTO DISTANCES VALUES(:ID, :STARTING, :ENDING, :DIST)");
         query.bindValue(":ID", maxID); // id is the id of the bottom row + 1
         query.bindValue(":STARTING", startStadium);
         query.bindValue(":ENDING", endStadium);
         query.bindValue(":DIST", distances);

         success = query.exec();

         if(!success) {
             qDebug() << "addDistance error: " << query.lastError();
         }

     } else {
         qDebug() << "Error: addDistance did not get an ID value from the table.";
     }
 }

/*************************************************************************
* void updateTeams(const QString& team, const QString& newStadium, const QString& newLocation, const QString& newSurface, const int& newDate, const QString& newDistToCentField, const QString& newTypology, const QString& newRoof)
* -----------------------------------------------------------------------
* This function allows the administrator to update team information for any team
* including stadium name, location, playing surface, seating capacity, date opened, distance to center
* field, ballpark typology, and roof type
************************************************************************/
void manageDB::updateTeams(const QString& team, const QString& newStadium, const int& capacity, const QString& newLocation, const QString& newLeague, const QString& newSurface, const int& newDate, const QString& newDistToCentField, const QString& newTypology, const QString& newRoof)
{
    QSqlQuery query;
    bool success;

    // updates souvenir information
    query.prepare("UPDATE TEAMS SET StadiumName = :STADIUM, SeatingCapacity = :CAPACITY, Location = :LOCATION, TeamLeague = :LEAGUE,  PlayingSurface = :SURFACE, DateOpened = :DATE, DistToCentField = :DIST, BallparkTypology = :TYPOLOGY, RoofType = :ROOF WHERE TeamName = :TEAM");
    query.bindValue(":STADIUM", newStadium);
    query.bindValue(":CAPACITY", capacity);
    query.bindValue(":LOCATION", newLocation);
    query.bindValue(":LEAGUE", newLeague);
    query.bindValue(":SURFACE", newSurface);
    query.bindValue(":DATE", newDate);
    query.bindValue(":DIST", newDistToCentField);
    query.bindValue(":TYPOLOGY", newTypology);
    query.bindValue(":ROOF", newRoof);
    query.bindValue(":TEAM", team);

    // qDebug() << "bound: " << query.boundValues();

    success = query.exec();

    if(!success) {
        qDebug() << "updateSouvenir error: " << query.lastError();
    }
}

/*************************************************************************
 * QVector<QString> startingStadiums()
 * -----------------------------------------------------------------------
 * This function gets the starting stadiums from the DISTANCES table and
 * returns a QVector containing stadium names
 ************************************************************************/
QVector<QString> manageDB::startingStadiums()
{
    // Gets the starting stadiums from the Database
    QVector<QString> start;
    QSqlQuery query("SELECT DISTINCT Starting FROM DISTANCES");

    // While query is not empty
    while(query.next())
    {
        // Pushes the stadiumsinto the QVector
        QString out = query.value(0).toString();
        start.push_back(out);
    }
    // returns a QVector of starting stadiums.
    return start;
}

/*************************************************************************
* QVector<Edge<QString>> getEdges(const QString& originStadium)
* -----------------------------------------------------------------------
* This function returns a QVector of edges containing the starting stadium,
* ending stadium, and the distance between each stadium based on the value
* of the starting stadium
 ************************************************************************/
/*
QVector<Edge<QString>> manageDB::getEdges(const QString& originStadium)
{
    // initializing variables
    QVector<Edge<QString>> edge;
    Edge<QString> edgeVal;
    QVector<QString> endStadiums;
    QVector<double> distances;
    QSqlQuery query;

    // Gets the ending stadiums based on the value of the starting stadium
    query.prepare("SELECT Ending FROM DISTANCES WHERE Starting = :START");
    query.bindValue(":START", originStadium);

    // Checks if query does not execute
    if(!query.exec())
    {
        qDebug() << "Failed to query from SQL Database";
    }

    // Pushes the ending stadiums into the QVector
    while(query.next())
    {
        if (!query.next())
        {
           break;
        }
        endStadiums.push_back(query.value(0).toString());
    }

    // Gets the distance based on the value of the starting stadium
    query.prepare("SELECT DIST FROM DISTANCES WHERE Starting = :START");
    query.bindValue(":START", originStadium);

    // Checks if query does not execute
    if(!query.exec())
    {
        qDebug() << "Failed to query from SQL Database";
    }

    // pushes the distance value into the QVector
    while(query.next())
    {
        if (!query.next())
        {
            break;
        }
        distances.push_back(query.value(0).toDouble());
    }

    // Gets the individual values of edge and pushes it into a QVector of edges
    for (int i = 0; i < endStadiums.size(); i++)
    {
        edgeVal.start = originStadium;
        edgeVal.end = endStadiums[i];
        edgeVal.weight = distances[i];
        edge.push_back(edgeVal);
    }

    // returns a QVector of edges based on the starting stadium
    return edge;
}
*/


double manageDB::getDistance(const QString& currentCampus, const QString& nextCampus)
{
    QSqlQuery query;     // query

    double distance = 0; // distance between the two campuses

    // find the cell whose starting campus is currentCampus and whose ending campus is nextCampus
    query.prepare("SELECT DIST FROM DISTANCES WHERE Starting = :CURRENTCAMPUS AND Ending = :NEXTCAMPUS");
    query.bindValue(":CURRENTCAMPUS", currentCampus);
    query.bindValue(":NEXTCAMPUS", nextCampus);

    // execute prepared query
    query.exec();

    // assign value to distance
    if (query.next())
    {
        distance = query.value(0).toDouble();
    }

    return distance;     // return distance
}

/*
QVector<QString> manageDB::DIJKSTRA(QString startStadium, QVector<QString> otherStadiums)
{
    QVector<QString> orderedStadiums;
    int dist[vNum];
    bool sptSet[vNum];
    int parent[vNum];

    for (int i = 0; i < vNum; i++)
    {
        sptSet[i] = false;
        dist[i] = MAX;
        parent[i] = -1;
        if (startingStadium == vertices[i].value)
        {
            startingID = i;
        }
    }

    dist[startingID] = 0;

    for (int i = 0; i < vNum - 1; i++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < vNum; v++)
        {
            if (!sptSet[u] && adjMat[u][v] && dist[u] < adjMat[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + adjMat[u][v];
            }
        }
    }

    selectStadiums.pop_front();

    if (selectStadiums.size() > 1)
    {
        recurDijkstra(selectStadiums);
    }

    else
    {
        return
    }
}
*/

/*
QVector<QString> manageDB::getStad(const double& distance, QVector<QString> otherStadiums)
{
    QVector<QString> results;
    QString start = otherStadiums[0];

    //double dist = 0; // distance between the two campuses

    QSqlQuery query;     // query

    // find the cell whose starting campus is currentCampus and whose ending campus is nextCampus
    query.prepare("SELECT Ending FROM DISTANCES WHERE Starting = :CURRENTCAMPUS AND DIST = :DIST");
    query.bindValue(":CURRENTCAMPUS", start);
    query.bindValue(":DIST", distance);

    for (int i = 0; i < otherStadiums.size(); i++)
    {
        query.exec();

        if (query.next())
        {
            QString name = query.value(0).toString();

            if (name == otherStadiums[i])
            {
                results.push_back(name);
            }
        }
    }

    return results;


}
*/

QVector<distanceEdge> manageDB::getDistances(const QString& teamName) const
{
    QSqlQuery query;
    QVector<distanceEdge> distances;
    distanceEdge edge;
    query.prepare("SELECT Ending, DIST FROM DISTANCES WHERE Starting=:origin");
    query.bindValue(":origin", teamName);
    query.exec();

    query.first();
    edge.team_name_origin = teamName;
    while (query.isValid()) {
        edge.team_name_destination = query.value(0).toString();
        edge.distance = query.value(1).toInt();
        distances.push_back(edge);

        query.next();
    }

    return distances;
}

QVector<QString> manageDB::getLeague()
{
    // Gets the team names from the Database
    QVector<QString> leagues;
    QSqlQuery query("SELECT DISTINCT TeamLeague FROM TEAMS");

    // While query is not empty
    while(query.next())
    {
        // Pushes the team names into the QVector
        QString out = query.value(0).toString();
        leagues.push_back(out);
    }
    // returns a QVector of team names.
    return leagues;
}

QString manageDB::setLeague(const QString& team)
{
    // sets up the query to get the location
    QString league = "";
    QString sQuery = "select TeamLeague from TEAMS where TeamName = '" + team + "';";

    QSqlQuery query;
    query.prepare(sQuery);
    query.exec();

    // Checks if there is a value in the query
    if(query.next())
    {
        league = query.value(0).toString();
    }

    // returns the value of location
    return league;
}
