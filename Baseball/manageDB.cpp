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

