#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "dijkstra.h"

using namespace std;


struct distanceEdge {
    QString team_name_origin;
    QString team_name_destination;
    int distance;
};

//!
//! \class manageDB
//! Provides all the functions needed to extract
//! information from the database
//!
class manageDB
{
public:

    //!
    //! \fn manageDB constructor
    //! \param path - path to SQLite database
    //!
    manageDB(const QString& path);

    //!
    //! \fn getTeamNames
    //! \return QVector containing team names
    //!
    QVector<QString> getTeamNames();

    QVector<QString> getStadiumNames();

    //!
    //! \fn getSeatingCapacity
    //! \return int representing
    //! the sum of the seating capacity
    //! for the entire team
    //!
    int getSeatingCapacity();

    //!
    //! \fn seatingCapacity
    //! \param team - QString representing team name.
    //! \return an int value representing the seating capacity for the stadium
    //!
    int seatingCapacity(const QString& team);

    //!
    //! \fn dateOpened
    //! \param team - QString representing team name
    //! \return an int value representing date opened for the stadium
    //!
    int dateOpened(const QString& team);

    //!
    //! \fn getDistToCentField
    //! \param team - QString representing team name
    //! \return an int value representing the distance to center field for the team
    //!
    int getDistToCentField(const QString& team);

    //!
    //! \fn getRoofTypes
    //! \return QVector of different roof types
    //!
    QVector<QString> getRoofTypes();

    //!
    //! \fn setRoofType
    //! \param team - QString representing team name
    //! \return returns the roof type based on the team value
    //!
    QString setRoofType(const QString& team);

    //!
    //! \fn getSurfaces
    //! \return QVector of different playing surfaces
    //!
    QVector<QString> getSurfaces();

    //!
    //! \fn setSurfaceType
    //! \param team - QString representing team name
    //! \return returns the surface type based on team value
    //!
    QString setSurfaceType(const QString& team);

    //!
    //! \fn getTypology
    //! \return QVector of different typology types
    //!
    QVector<QString> getTypology();

    //!
    //! \fn setTypology
    //! \param team
    //! \return typology type based on team value
    //!
    QString setTypology(const QString& team);

    //!
    //! \fn getNumOpenRoofs
    //! \return int representing
    //! the total number of teams
    //! with an open roof
    //!
    int getNumOpenRoofs();

    //!
    //! \fn getStadiumName
    //! \param team - QString indicating the team location being searched.
    //! \return QString representing the stadium name of the team.
    //!
    QString getStadiumName(const QString& team);

    //!
    //! \fn getLocation
    //! \param team - QString indicating the team location being searched.
    //! \return location based on the value of team
    //!
    QString getLocation(const QString& team);

    //!
    //! \fn getTeamModel
    //! \param team - QString indicating the team information being accessed.
    //! \return model containing the information specific to the value of team.
    //!
    QSqlQueryModel* getTeamModel(const QString& team);

    //!
    //! \fn getTeamsSortedbyTeams
    //! \return model containing teams and stadiums
    //! sorted by team name.
    //!
    QSqlQueryModel* getTeamsSortedbyTeams();

    //!
    //! \fn getTeamsSortedbyStadiums
    //! \return model containing teams and stadiums
    //! sorted by team name
    //!
    QSqlQueryModel* getTeamsSortedbyStadiums();

    //!
    //! \fn getTeamsbyDate
    //! \return model containing teams and stadiums
    //! sorted by oldest date opened to newest date opened
    //!
    QSqlQueryModel* getTeamsbyDate();

    //!
    //! \fn getTeamsbySmallDistToCenterField
    //! \return model containing team with the smallest
    //! distance to the center field
    //!
    QSqlQueryModel* getTeamsbySmallDistToCenterField();

    //!
    //! \fn getTeamsbyLargeDistToCenterField
    //! \return model containing teams with the largest
    //! distance to the center field
    //!
    QSqlQueryModel* getTeamsbyLargeDistToCenterField();

    //!
    //! \fn getAmericanLeagueTeams
    //! \return model containing the teams
    //! and stadiums sorted by team name that
    //! play in the American League
    //!
    QSqlQueryModel* getAmericanLeagueTeams();

    //!
    //! \fn getNationalLeagueTeams
    //! \return model containing the teams
    //! and stadiums sorted by stadium name
    //! that play in the National League
    //!
    QSqlQueryModel* getNationalLeagueTeams();

    //!
    //! \fn getTeamsBySeatingCapacity
    //! \return model containing the team names
    //! and their stadium names by smallest to largest
    //! seating capacity.
    //!
    QSqlQueryModel* getTeamsBySeatingCapacity();

    //!
    //! \fn getTeamsByBallParkTypology
    //! \return model containing the team
    //! names and their stadium names
    //! sorted by ballPark typology.
    //!
    QSqlQueryModel* getTeamsByBallParkTypology();

    //!
    //! \fn getTeamsWithOpenRoof
    //! \return model containing all the teams
    //! and their stadiums with an open roof sorted
    //! by team name
    //!
    QSqlQueryModel* getTeamsWithOpenRoof();

    //!
    //! \fn getSouvenirsByTeam
    //! \param team - QString indicating the souvenirs being accessed
    //! \return model containing all the souvenirs for a given team
    //!
    QSqlQueryModel* getSouvenirsByTeam(const QString& team);

    //!
    //! \fn getTeamSouvenirs
    //! \param team - QString indicating the souvenirs being accessed.
    //! \return QVector of strings containing all the souvenirs for a team
    //!
    QVector<QString> getTeamSouvenirs(const QString& team);

    //!
    //! \fn getSouvenirPrice
    //! \param souvenir - QString representing the name of a souvenir
    //! \param team - QString representing the team name of the souvenir.
    //! \return A double representing the price of a given souvenir.
    //!
    double getSouvenirPrice(const QString& souvenir, const QString& team);

    //!
    //! \fn addSouvenir
    //! \param team - team that souvenir belongs to
    //! \param souvenirName - name of new souvenir being added
    //! \param price - Price of the new souvenir
    //!
    void addSouvenir(const QString& team, const QString& souvenirName, const double& price);

    //!
    //! \fn removeSouvenir
    //! \param team - team that the souvenir belongs to
    //! \param souvenirName - The name of the souvenir being removed.
    //!
    void removeSouvenir(const QString& team, const QString& souvenirName);

    //!
    //! \fn souvExists
    //! Checks if a souvenir exists
    //! \param team - team that souvenir belongs to
    //! \param souvenirName - souvenir to check
    //! \return true if souvenir exists for a given team
    //!
    bool souvExists(QString& team, QString& souvenirName);

    //!
    //! \fn updateSouvenirs
    //! \param team - team that souvenir belongs to
    //! \param oldName - Original Souvenir's Name
    //! \param newName - New Souvenir's Name
    //! \param newPrice - New Price of the souvenir
    //!
    void updateSouvenirs(const QString& team, const QString& oldName, const QString& newName, const double& newPrice);

    //!
    //! \fn teamExists
    //! \param team - name of team being checked
    //! \return True if the team is in the database. False otherwise
    //!
    bool teamExists(const QString& team);

    //!
    //! \fn addTeam
    //! \param team - represents the new team name being added
    //! \param stadium - stadium name for the new team
    //! \param capacity - capacity of the team's stadium
    //! \param location - Where the new team is located
    //! \param surface - What the team plays on
    //! \param league - Team plays in either National or American
    //! \param date - Represents when the stadium opened
    //! \param distance - Represents distance to center field
    //! \param typology - Represents the typology of the baseball field
    //! \param roof - Represents the type of roof for the team
    //!
    void addTeam(const QString& team, const QString& stadium, const int& capacity, const QString& location, const QString& surface, const QString& league, const int& date, const QString& distance, const QString& typology, const QString& roof);

    //!
    //! \fn addTeamSouvenirs
    //! \param team - name of the new team for the souvenirs being added
    //! \param souvenir - name of the souvenir being added for the team
    //! \param price - price of the souvenir
    //!
    void addTeamSouvenirs(const QString& team,const QString& stadium, const QString& souvenir, const double& price);

    //!
    //! \fn addTeamDistances
    //! \param startStadium - Represents the starting stadium
    //! \param endStadium - Represents the ending stadium
    //! \param distances - Represents the distance between the starting and ending stadiums
    //!
    void addTeamDistances(const QString& startStadium, const QString& endStadium, const double& distances);

    //!
    //! \fn updateTeams
    //! \param team - team name of information being modified
    //! \param newStadium - represents the new stadium name of the team
    //! \param capacity - represents the seating capacity of the team
    //! \param newLocation - represents the new location of the team
    //! \param newLeague - represents the league that the team plays on
    //! \param newSurface - represents the new playing surface of the team
    //! \param newDate - represents the new date opened for the team
    //! \param newDistToCentField - represents the new distance to center field for a team
    //! \param newTypology - represents the new typology of the team
    //! \param newRoof - represents the new roof type of the team.
    //!
    void updateTeams(const QString& team, const QString& newStadium, const int& capacity, const QString& newLocation, const QString& newLeague, const QString& newSurface, const int& newDate, const QString& newDistToCentField, const QString& newTypology, const QString& newRoof);

    //!
    //! \fn startingStadiums
    //! \return QVector containing all the starting stadiums for the distances between each stadiums
    //!
    QVector<QString> startingStadiums();

    //!
    //! \fn getEdges
    //! \param originStadium - QString representing the starting stadium between two stadiums
    //! \return QVector containing the all the edges(starting, ending, distance) for all the stadiums
    //!
    //QVector<Edge<QString>> getEdges(const QString& originStadium);

    double getDistance(const QString& currentCampus, const QString& nextCampus);

    QVector<distanceEdge> getDistances(const QString& teamName) const;

    QVector<QString> getLeague();

    QString setLeague(const QString& team);

    //QVector<QString> getStad(const double& distance, QVector<QString> otherStadiums);




    //QVector<QString> DIJKSTRA(QString startStadium, QVector<QString> otherStadiums);



private:

    //!
    //! \brief DB
    //! QSQLDatabase object which manages the Database of Teams
    //!
    QSqlDatabase DB;
};

#endif // DBMANAGER_H
