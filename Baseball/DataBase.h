#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QMessageBox>
#include "manageDB.h"
#include "modifySouvenirs.h"
#include "modifyTeams.h"

namespace Ui {
class DataBase;
}

//!
//! \class DataBase
//! Class that displays team information and its souvenirs
//!
class DataBase : public QMainWindow
{
    Q_OBJECT

public:
    //!
    //! \fn DataBase constructor
    //! Sets the path to the database to view team information and souvenirs
    //! \param db - path to database
    //! \param adminUser - keeps track whether user is an administrator or not
    //! \param parent
    //!
    explicit DataBase(manageDB* db = nullptr, bool adminUser = false, QWidget *parent = nullptr);

    //!
    //! \fn ~DataBase destructor
    //!
    ~DataBase();

private slots:

    //!
    //! \fn on_viewTeam_clicked
    //! Baseball Fan or Administrator selects
    //! a Baseball team to view all of its
    //! information.
    //!
    void on_viewTeam_clicked();

    //!
    //! \fn on_TeamStadiumByTeam_clicked
    //! Displays the team names and stadium names
    //! alphabetically by team name.
    //!
    void on_TeamStadiumByTeam_clicked();

    //!
    //! \fn on_TeamStadiumByStadium_clicked
    //! Displays the team names and stadium names
    //! alphabetically by stadium name.
    //!
    void on_TeamStadiumByStadium_clicked();

    //!
    //! \fn on_TeamStadiumByDate_clicked
    //! Displays the team names and stadium names
    //! in the order of date opened. The date opened
    //! for each team is also displayed(Oldest to Newest).
    //!
    void on_TeamStadiumByDate_clicked();

    //!
    //! \fn on_TeamStadiumBySmallDistCtrField_clicked
    //! Displays the team, stadium names, and distance to
    //! center field of the smallest distance
    //!
    void on_TeamStadiumBySmallDistCtrField_clicked();

    //!
    //! \fn on_TeamStadiumByLargeDistCtrField_clicked
    //! Displays the teams and stadium names with the largest
    //! distance to the center field
    //!
    void on_TeamStadiumByLargeDistCtrField_clicked();

    //!
    //! \fn on_AmericanLeagueTeams_clicked
    //! Displays all the teams and their stadiums
    //! that play in the American League sorted by
    //! Team Name
    //!
    void on_AmericanLeagueTeams_clicked();

    //!
    //! \fn on_NationalLeagueTeams_clicked
    //! Displays all the teams and their stadiums
    //! that play in the National League sorted by
    //! Stadium Name
    //!
    void on_NationalLeagueTeams_clicked();

    //!
    //! \fn on_TeamStadiumByCapacity_clicked
    //! Displays all the teams and their stadium names
    //! by smallest to largest seating capacity. The total
    //! seating capacity of all the teams is also displayed.
    //!
    void on_TeamStadiumByCapacity_clicked();

    //!
    //! \fn on_TeamStadiumByTypology_clicked
    //! Displays all the teams and their stadium names
    //! sorted by Ballpark Typology.
    //!
    void on_TeamStadiumByTypology_clicked();

    //!
    //! \fn on_OpenRoofTeams_clicked
    //! Displays all the teams and their stadium names
    //! with an open roof type. Additionally, the total number
    //! of teams with an open roof type is also displayed.
    //!
    void on_OpenRoofTeams_clicked();

    //!
    //! \fn on_viewSouvenirs_clicked
    //! Displays the Souvenirs and their prices
    //! for any team selected
    //!
    void on_viewSouvenirs_clicked();

    //!
    //! \fn on_modifySouvenirs_clicked
    //! Allows the Administrator to add, delete,
    //! or modify the souvenir for any baseball team
    //!
    void on_modifySouvenirs_clicked();

    //!
    //! \fn on_modifyteams_clicked
    //! Allows the Administrator to
    //! modifiy team information or
    //! add a team through an input file
    //!
    void on_modifyteams_clicked();

    //!
    //! \fn on_cancelView_clicked
    //! Allows the user and Administrator
    //! to go back to the home page.
    //!
    void on_cancelView_clicked();

private:
    //!
    //! \brief ui - access ui
    //!
    Ui::DataBase *ui;

    //!
    //! \brief database - used to set path to connect database
    //!
    manageDB *database;

    //!
    //! \brief modify - used to open window for admin to add, delete, or modify souvenirs
    //!
    modifySouvenirs* modify;

    //!
    //! \brief teamModify - used to open window for admin to add or modify team information
    //!
    modifyTeams* teamModify;

    //!
    //! \brief isAdmin - keeps track of whether the user is an Admin or not
    //!
    bool isAdmin;

};

#endif // DATABASE_H
