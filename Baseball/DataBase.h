#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QMessageBox>
#include "manageDB.h"

namespace Ui {
class DataBase;
}

class DataBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataBase(manageDB* db = nullptr, QWidget *parent = nullptr);
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


private:
    Ui::DataBase *ui;
    manageDB *database;

};

#endif // DATABASE_H
