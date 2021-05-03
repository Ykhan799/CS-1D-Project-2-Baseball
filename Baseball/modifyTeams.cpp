#include "modifyTeams.h"
#include "ui_modifyTeams.h"

modifyTeams::modifyTeams(QWidget *parent, manageDB* getDataBase) :
    QDialog(parent),
    ui(new Ui::modifyTeams)
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
}

modifyTeams::~modifyTeams()
{
    delete ui;
}

void modifyTeams::on_modify_clicked()
{
    QString teams;
    QString stadName;
    QString location;
    QString roofs;
    QString surface;
    QString typology;
    int seatingCapacity;
    int dateOpened;
    int centerDistance;

    teams = ui->teamsComboBox->currentText();
    stadName = ui->stadiumLineEdit->text();
    location = ui->locationLineEdit->text();
    roofs = ui->roofComboBox->currentText();
    surface = ui->surfaceComboBox->currentText();
    typology = ui->typologyComboBox->currentText();
    seatingCapacity = ui->seatingspinBox->value();
    dateOpened = ui->datespinBox->value();
    centerDistance = ui->distancespinBox->value();
}

void modifyTeams::on_addTeam_clicked()
{

}

void modifyTeams::on_teamsComboBox_currentIndexChanged(const QString& arg1)
{
    ui->teamsComboBox->clear();
}

void modifyTeams::on_surfaceComboBox_currentIndexChanged(const QString& arg1)
{
    ui->surfaceComboBox->clear();
}

void modifyTeams::on_typologyComboBox_currentIndexChanged(const QString& arg1)
{
    ui->typologyComboBox->clear();
}

void modifyTeams::on_roofComboBox_currentIndexChanged(const QString& arg1)
{
    ui->roofComboBox->clear();
}
