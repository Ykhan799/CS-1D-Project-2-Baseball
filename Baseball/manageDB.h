#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>
using namespace std;

class manageDB
{
public:

    //!
    //! \brief manageDB
    //! \param path - path to SQLite database
    //!
    manageDB(const QString& path);

    //!
    //! \brief getTeamNames
    //! \return vector containing team names
    //!
    vector<QString> getTeamNames();

    //!
    //! \brief getSeatingCapacity
    //! \return int representing
    //! the sum of the seating capacity
    //! for the entire team
    //!
    int getSeatingCapacity();

    //!
    //! \brief getNumOpenRoofs
    //! \return int representing
    //! the total number of teams
    //! with an open roof
    //!
    int getNumOpenRoofs();

    //!
    //! \brief getTeamModel
    //! \param team - QString indicating the team information being accessed.
    //! \return model containing the information specific to the value of team.
    //!
    QSqlQueryModel* getTeamModel(const QString& team);

    //!
    //! \brief getTeamsSortedbyTeams
    //! \return model containing teams and stadiums
    //! sorted by team name.
    //!
    QSqlQueryModel* getTeamsSortedbyTeams();

    //!
    //! \brief getTeamsSortedbyStadiums
    //! \return model containing teams and stadiums
    //! sorted by team name
    //!
    QSqlQueryModel* getTeamsSortedbyStadiums();

    //!
    //! \brief getTeamsbyDate
    //! \return model containing teams and stadiums
    //! sorted by oldest date opened to newest date opened
    //!
    QSqlQueryModel* getTeamsbyDate();

    //!
    //! \brief getTeamsbySmallDistToCenterField
    //! \return model containing team with the smallest
    //! distance to the center field
    //!
    QSqlQueryModel* getTeamsbySmallDistToCenterField();

    //!
    //! \brief getTeamsbyLargeDistToCenterField
    //! \return model containing teams with the largest
    //! distance to the center field
    //!
    QSqlQueryModel* getTeamsbyLargeDistToCenterField();

    //!
    //! \brief getAmericanLeagueTeams
    //! \return model containing the teams
    //! and stadiums sorted by team name that
    //! play in the American League
    //!
    QSqlQueryModel* getAmericanLeagueTeams();

    //!
    //! \brief getNationalLeagueTeams
    //! \return model containing the teams
    //! and stadiums sorted by stadium name
    //! that play in the National League
    //!
    QSqlQueryModel* getNationalLeagueTeams();

    //!
    //! \brief getTeamsBySeatingCapacity
    //! \return model containing the team names
    //! and their stadium names by smallest to largest
    //! seating capacity.
    //!
    QSqlQueryModel* getTeamsBySeatingCapacity();

    //!
    //! \brief getTeamsByBallParkTypology
    //! \return model containing the team
    //! names and their stadium names
    //! sorted by ballPark typology.
    //!
    QSqlQueryModel* getTeamsByBallParkTypology();

    //!
    //! \brief getTeamsWithOpenRoof
    //! \return model containing all the teams
    //! and their stadiums with an open roof sorted
    //! by team name
    //!
    QSqlQueryModel* getTeamsWithOpenRoof();


private:

    //!
    //! \brief DB
    //! QSQLDatabase object which manages the Database of Teams
    //!
    QSqlDatabase DB;
};

#endif // DBMANAGER_H
