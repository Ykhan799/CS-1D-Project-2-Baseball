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

    QString getLocation(const QString& team);

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

    //!
    //! \brief getSouvenirsByTeam
    //! \param team - QString indicating the souvenirs being accessed
    //! \return model containing all the souvenirs for a given team
    //!
    QSqlQueryModel* getSouvenirsByTeam(const QString& team);

    //!
    //! \brief getTeamSouvenirs
    //! \param team - QString indicating the souvenirs being accessed.
    //! \return vector of strings containing all the souvenirs for a team
    //!
    vector<QString> getTeamSouvenirs(const QString& team);

    //!
    //! \brief getSouvenirPrice
    //! \param souvenir - QString representing the name of a souvenir
    //! \param team - QString representing the team name of the souvenir.
    //! \return A double representing the price of a given souvenir.
    //!
    double getSouvenirPrice(const QString& souvenir, const QString& team);

    //!
    //! \brief addSouvenir
    //! \param team - team that souvenir belongs to
    //! \param souvenirName - name of new souvenir being added
    //! \param price - Price of the new souvenir
    //!
    void addSouvenir(const QString& team, const QString& souvenirName, const double& price);

    //!
    //! \brief removeSouvenir
    //! \param team - team that the souvenir belongs to
    //! \param souvenirName - The name of the souvenir being removed.
    //!
    void removeSouvenir(const QString& team, const QString& souvenirName);

    //!
    //! \brief souvExists
    //! Checks if a souvenir exists
    //! \param team - team that souvenir belongs to
    //! \param souvenirName - souvenir to check
    //! \return true if souvenir exists for a given team
    //!
    bool souvExists(QString& team, QString& souvenirName);

    //!
    //! \brief updateSouvenirs
    //! \param team - team that souvenir belongs to
    //! \param oldName - Original Souvenir's Name
    //! \param newName - New Souvenir's Name
    //! \param newPrice - New Price of the souvenir
    //!
    void updateSouvenirs(const QString& team, const QString& oldName, const QString& newName, const double& newPrice);

    //!
    //! \brief teamExists
    //! \param team - name of team being checked
    //! \return True if the team is in the database. False otherwise
    //!
    bool teamExists(const QString& team);

    //!
    //! \brief addTeam
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
    //! \brief addTeamSouvenirs
    //! \param team - name of the new team for the souvenirs being added
    //! \param souvenir - name of the souvenir being added for the team
    //! \param price - price of the souvenir
    //!
    void addTeamSouvenirs(const QString& team, const QString& souvenir, const double& price);

    //!
    //! \brief addTeamDistances
    //! \param startStadium - Represents the starting stadium
    //! \param endStadium - Represents the ending stadium
    //! \param distances - Represents the distance between the starting and ending stadiums
    //!
    void addTeamDistances(const QString& startStadium, const QString& endStadium, const double& distances);


private:

    //!
    //! \brief DB
    //! QSQLDatabase object which manages the Database of Teams
    //!
    QSqlDatabase DB;
};

#endif // DBMANAGER_H
