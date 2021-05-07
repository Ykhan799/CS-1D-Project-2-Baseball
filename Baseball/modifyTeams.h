#ifndef MODIFYTEAMS_H
#define MODIFYTEAMS_H

#include <QDialog>
#include "manageDB.h"
#include <string>
#include <fstream>
#include <QMessageBox>
#include <QFileDialog>
using namespace std;

namespace Ui {
class modifyTeams;
}

class modifyTeams : public QDialog
{
    Q_OBJECT

public:
    explicit modifyTeams(QWidget *parent = nullptr, manageDB* getDataBase = nullptr);
    ~modifyTeams();

private slots:
    //!
    //! \brief on_modify_clicked
    //! modifies the information for any team using UI elements
    //!
    void on_modify_clicked();

    //!
    //! \brief on_addTeam_clicked
    //! adds information for a team and souvenirs using a text file
    //!
    void on_addTeam_clicked();

    //!
    //! \brief on_teamsComboBox_currentIndexChanged
    //! Updates the team information in the modify section tab
    //! \param arg1 currently unused
    //!
    void on_teamsComboBox_currentIndexChanged(const QString& arg1);

    //!
    //! \brief on_surfaceComboBox_currentIndexChanged
    //! Allows the Admin to select a different playing surface
    //! \param arg1 - current team
    //!
    void on_surfaceComboBox_currentIndexChanged(const QString& arg1);

    //!
    //! \brief on_typologyComboBox_currentIndexChanged
    //! Allows the Admin to select a different typology
    //! \param arg1 - current team
    //!
    void on_typologyComboBox_currentIndexChanged(const QString& arg1);

    //!
    //! \brief on_roofComboBox_currentIndexChanged
    //! Allows the Admin to select a different typology
    //! \param arg1 - current team
    //!
    void on_roofComboBox_currentIndexChanged(const QString& arg1);



private:
    Ui::modifyTeams *ui;

    manageDB *database;
};

#endif // MODIFYTEAMS_H
