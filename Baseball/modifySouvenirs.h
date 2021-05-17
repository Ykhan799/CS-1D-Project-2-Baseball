#ifndef MODIFYSOUVENIRS_H
#define MODIFYSOUVENIRS_H

#include <QDialog>
#include <QMessageBox>
#include "manageDB.h"

namespace Ui {
class modifySouvenirs;
}

//!
//! \fn modifySouvenirs
//! Allows the Administrator to
//! modify, add, or delete souvenirs
//!
class modifySouvenirs : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \fn modifySouvenirs Constructor
    //! \param parent - sets up ui
    //! \param getDataBase - gets the database
    //!
    explicit modifySouvenirs(QWidget *parent = nullptr, manageDB* getDataBase = nullptr);

    //!
    //! \fn ~modifySouvenirs Destructor
    //!
    ~modifySouvenirs();

private slots:
    //!
    //! \fn on_modifyButton_clicked
    //! modifies a souvenir for any team using data from UI elements.
    //!
    void on_modifyButton_clicked();

    //!
    //! \fn on_teamSouvenirComboBox_currentIndexChanged
    //! updates the souvenir names in the modify/delete tab combo box
    //! \param arg1 currently unused
    //!
    void on_teamSouvenirComboBox_currentIndexChanged(const QString& arg1);

    //!
    //! \fn on_souvenirNameComboBox_currentIndexChanged
    //! updates the souvenir's price in the spin box.
    //! \param arg1 currently unused
    //!
    void on_souvenirNameComboBox_currentIndexChanged(const QString& arg1);

    //!
    //! \fn on_deleteButton_clicked
    //! deletes the souvenir selected in the combo box.
    //!
    void on_deleteButton_clicked();

    //!
    //! \fn on_addButton_clicked
    //! adds a souvenir based on the information given in the add souvenir tab
    //!
    void on_addButton_clicked();

private:
    //!
    //! \brief ui - sets up the ui
    //!
    Ui::modifySouvenirs *ui;

    //!
    //! \brief database - sets up the database to modify souvenirs
    //!
    manageDB* database;
};

#endif // MODIFYSOUVENIRS_H
