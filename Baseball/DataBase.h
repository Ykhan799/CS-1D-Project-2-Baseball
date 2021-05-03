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

class DataBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataBase(manageDB* db = nullptr, bool adminUser = false, QWidget *parent = nullptr);
    ~DataBase();

private slots:

    //!
    //! \brief on_viewTeam_clicked
    //! Baseball Fan or Administrator selects
    //! a Baseball team to view all of its
    //! information.
    //!
    void on_viewTeam_clicked();

    //!
    //! \brief on_TeamStadiumByTeam_clicked
    //! Displays the team names and stadium names
    //! alphabetically by team name.
    //!
    void on_TeamStadiumByTeam_clicked();

    //!
    //! \brief on_TeamStadiumByStadium_clicked
    //! Displays the team names and stadium names
    //! alphabetically by stadium name.
    //!
    void on_TeamStadiumByStadium_clicked();

    //!
    //! \brief on_TeamStadiumByDate_clicked
    //! Displays the team names and stadium names
    //! in the order of date opened. The date opened
    //! for each team is also displayed(Oldest to Newest).
    //!
    void on_TeamStadiumByDate_clicked();

    //!
    //! \brief on_TeamStadiumBySmallDistCtrField_clicked
    //! Displays the team, stadium names, and distance to
    //! center field of the smallest distance
    //!
    void on_TeamStadiumBySmallDistCtrField_clicked();

    //!
    //! \brief on_TeamStadiumByLargeDistCtrField_clicked
    //! Displays the teams and stadium names with the largest
    //! distance to the center field
    //!
    void on_TeamStadiumByLargeDistCtrField_clicked();

    //!
    //! \brief on_AmericanLeagueTeams_clicked
    //! Displays all the teams and their stadiums
    //! that play in the American League sorted by
    //! Team Name
    //!
    void on_AmericanLeagueTeams_clicked();

    //!
    //! \brief on_NationalLeagueTeams_clicked
    //! Displays all the teams and their stadiums
    //! that play in the National League sorted by
    //! Stadium Name
    //!
    void on_NationalLeagueTeams_clicked();

    //!
    //! \brief on_TeamStadiumByCapacity_clicked
    //! Displays all the teams and their stadium names
    //! by smallest to largest seating capacity. The total
    //! seating capacity of all the teams is also displayed.
    //!
    void on_TeamStadiumByCapacity_clicked();

    //!
    //! \brief on_TeamStadiumByTypology_clicked
    //! Displays all the teams and their stadium names
    //! sorted by Ballpark Typology.
    //!
    void on_TeamStadiumByTypology_clicked();

    //!
    //! \brief on_OpenRoofTeams_clicked
    //! Displays all the teams and their stadium names
    //! with an open roof type. Additionally, the total number
    //! of teams with an open roof type is also displayed.
    //!
    void on_OpenRoofTeams_clicked();

    //!
    //! \brief on_viewSouvenirs_clicked
    //! Displays the Souvenirs and their prices
    //! for any team selected
    //!
    void on_viewSouvenirs_clicked();

    //!
    //! \brief on_modifySouvenirs_clicked
    //! Allows the Administrator to add, delete,
    //! or modify the souvenir for any baseball team
    //!
    void on_modifySouvenirs_clicked();

    void on_modifyTeams_clicked();

private:
    Ui::DataBase *ui;
    manageDB *database;
    modifySouvenirs* modify;
    modifyTeams* teamModify;

    bool isAdmin;

};

#endif // DATABASE_H
