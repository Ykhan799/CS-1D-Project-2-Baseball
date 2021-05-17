#ifndef DISPLAYGRAPHS_H
#define DISPLAYGRAPHS_H

#include <QMainWindow>

namespace Ui {
class displayGraphs;
}

class displayGraphs : public QMainWindow
{
    Q_OBJECT

public:
    explicit displayGraphs(QWidget *parent = nullptr);
    ~displayGraphs();

private:
    Ui::displayGraphs *ui;
};

#endif // DISPLAYGRAPHS_H
