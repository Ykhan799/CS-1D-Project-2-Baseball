#ifndef MARLINSPATH_H
#define MARLINSPATH_H

#include <QMainWindow>

namespace Ui {
class marlinsPath;
}

class marlinsPath : public QMainWindow
{
    Q_OBJECT

public:
    explicit marlinsPath(QWidget *parent = nullptr);
    ~marlinsPath();

private:
    Ui::marlinsPath *ui;
};

#endif // MARLINSPATH_H
