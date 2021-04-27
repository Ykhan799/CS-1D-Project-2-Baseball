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


private:

    //!
    //! \brief DB
    //! QSQLDatabase object which manages the Database of Teams
    //!
    QSqlDatabase DB;
};

#endif // DBMANAGER_H
