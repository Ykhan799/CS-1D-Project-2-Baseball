#ifndef MARLINSPATH_H
#define MARLINSPATH_H

#include <QMainWindow>
#include <souvenirshop.h>
namespace Ui {
class marlinsPath;
}

class marlinsPath : public QMainWindow
{
    Q_OBJECT

public:
    explicit marlinsPath(QWidget *parent = nullptr);
    ~marlinsPath();

private slots:
    void on_startTrip_button_clicked();

private:
    Ui::marlinsPath *ui;


};

#endif // MARLINSPATH_H
