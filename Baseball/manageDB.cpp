#include "manageDB.h"

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
 * vector<QString> getTeamNames()
 * -----------------------------------------------------------------------
 * Gets all the team names from the database.
 ************************************************************************/
vector<QString> manageDB::getTeamNames()
{
    // Gets the team names from the Database
    vector<QString> teamName;
    QSqlQuery query("SELECT DISTINCT TeamName FROM TEAMS");

    // While query is not empty
    while(query.next())
    {
        // Pushes the team names into the vector
        QString out = query.value(0).toString();
        teamName.push_back(out);
    }
    // returns a vector of team names.
    return teamName;
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
 * QSqlQueryModel* getTeamModel()
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
    query.prepare("SELECT TeamName, StadiumName FROM TEAMS ORDER BY StadiumName");
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
    query.prepare("SELECT TeamName, StadiumName, TeamLeague FROM TEAMS WHERE TeamLeague = 'National' ORDER BY StadiumName");
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


