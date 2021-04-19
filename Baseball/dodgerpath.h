#ifndef DODGERPATH_H
#define DODGERPATH_H

#include <QMainWindow>

namespace Ui {
class dodgerpath;
}

class dodgerpath : public QMainWindow
{
    Q_OBJECT

public:
    explicit dodgerpath(QWidget *parent = nullptr);
    ~dodgerpath();

private:
    Ui::dodgerpath *ui;
};

#endif // DODGERPATH_H
