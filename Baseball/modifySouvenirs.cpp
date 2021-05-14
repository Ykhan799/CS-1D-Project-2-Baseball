#include "modifySouvenirs.h"
#include "ui_modifySouvenirs.h"

modifySouvenirs::modifySouvenirs(QWidget *parent, manageDB* getDataBase) :
    QDialog(parent),
    ui(new Ui::modifySouvenirs)
{
    ui->setupUi(this);
    database = getDataBase;

    // Checks if database is null
    if (database == nullptr)
    {
         // Sets new connection to database.
         const QString FILE_NAME = "mlbTeams.db";
         QString dbPath = qApp->applicationDirPath();
         dbPath.append('/' + FILE_NAME);
         database = new manageDB(dbPath);
         qDebug() << "Database should be located at: " << dbPath;
    }

    // populates the combo boxes to store the Baseball team names
    for (auto &i: database->getTeamNames())
    {
         ui->addTeamComboBox->addItem(i);
         ui->teamSouvenirComboBox->addItem(i);
    }

    // Populates the souvenir combo box for a given team
    ui->souvenirNameComboBox->clear();
    for (auto &i: database->getTeamSouvenirs(ui->teamSouvenirComboBox->currentText()))
    {
        ui->souvenirNameComboBox->addItem(i);
    }

}

modifySouvenirs::~modifySouvenirs()
{
    delete ui;
    database = nullptr; // set to null to save changes to the database.
}

/*************************************************************************
 * void on_modifyButton_clicked()
 * -----------------------------------------------------------------------
 * Allows the Administrator to modify the price or name of a souvenir
 ************************************************************************/
void modifySouvenirs::on_modifyButton_clicked()
{
    QString newSouvName;
    QString oldSouvName;
    QString team;
    double newSouvValue;

    // stores the variable names
    newSouvName = ui->nameLineEdit->text();
    oldSouvName = ui->souvenirNameComboBox->currentText();
    newSouvValue = ui->priceSpinBox->value();
    team = ui->teamSouvenirComboBox->currentText();

    // calls the updateSouvenirs function
    database->updateSouvenirs(team, oldSouvName, newSouvName, newSouvValue);

    // repopulates the souvenir combo box
    ui->souvenirNameComboBox->clear();

    for (auto &i: database->getTeamSouvenirs(ui->teamSouvenirComboBox->currentText()))
    {
        ui->souvenirNameComboBox->addItem(i);
    }

}

/*************************************************************************
 * void on_teamSouvenirComboBox_currentIndexChanged(const QString& arg1)
 * -----------------------------------------------------------------------
 * Repopulates the teams combo box when any changes occur
 ************************************************************************/
void modifySouvenirs::on_teamSouvenirComboBox_currentIndexChanged(const QString& arg1)
{
    // populates the souvenir combo box
    ui->souvenirNameComboBox->clear();
    auto temp = database->getTeamSouvenirs(ui->teamSouvenirComboBox->currentText());
    for (auto &i: temp)
    {
        ui->souvenirNameComboBox->addItem(i);
    }
}

/*************************************************************************
 * void on_souvenirNameComboBox_currentIndexChanged(const QString& arg1)
 * -----------------------------------------------------------------------
 * Repopulates the souvenir combo box when any changes occur
 ************************************************************************/
void modifySouvenirs::on_souvenirNameComboBox_currentIndexChanged(const QString& arg1)
{
    // populates the nameLine and spin box
    ui->nameLineEdit->setText(arg1);
    ui->priceSpinBox->setValue(database->getSouvenirPrice(ui->souvenirNameComboBox->currentText(), ui->teamSouvenirComboBox->currentText()));
}

/*************************************************************************
 * void on_deleteButton_clicked()
 * -----------------------------------------------------------------------
 * Allows the Administrator to delete a souvenir from the database
 ************************************************************************/
void modifySouvenirs::on_deleteButton_clicked()
{
    QString removeSouv;
    QString removeTeam;

    // Assigns variable names
    removeSouv = ui->souvenirNameComboBox->currentText();
    removeTeam = ui->teamSouvenirComboBox->currentText();

    // Deletes the souvenir
    database->removeSouvenir(removeTeam, removeSouv);

    // Repopulates the souvenir combo box
    ui->souvenirNameComboBox->clear();
    for (auto &i: database->getTeamSouvenirs(ui->teamSouvenirComboBox->currentText()))
    {
        ui->souvenirNameComboBox->addItem(i);
    }

}

/*************************************************************************
 * void on_deleteButton_clicked()
 * -----------------------------------------------------------------------
 * Allows the Administrator to add a souvenir from the database.
 ************************************************************************/
void modifySouvenirs::on_addButton_clicked()
{
    // Assigns variables
    QString team = ui->addTeamComboBox->currentText();
    QString souvenirName = ui->addNameLineEdit->text();
    double price = ui->addPriceSpinBox->value();

    // Test Cases - Case 1: Checks if Souvenir name is null
    if (souvenirName.isEmpty())
    {
        QMessageBox::information(this, "Error", "Please input the new souvenir's information");
    }

    // Case 2: Checks if the price is 0 or less
    else if (price <= 0.0)
    {
        QMessageBox::information(this, "Error", "The new souvenir's price cannot be $0.00");
    }

    // Case 3: Checks if the souvenir exists
    else if (database->souvExists(team, souvenirName))
    {
        QMessageBox::information(this, "Error", "Souvenir already exists");
    }

    // Case 4: Adds the souvenir to the database
    else
    {
        database->addSouvenir(team, souvenirName, price);
        QMessageBox::information(nullptr, "Success", "Added souvenir to the database");
    }

}
