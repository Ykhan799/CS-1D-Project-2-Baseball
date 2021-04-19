#ifndef CUSTOMPATH_H
#define CUSTOMPATH_H

#include <QMainWindow>

namespace Ui {
class customPath;
}

class customPath : public QMainWindow
{
    Q_OBJECT

public:
    explicit customPath(QWidget *parent = nullptr);
    ~customPath();

private:
    Ui::customPath *ui;
};

#endif // CUSTOMPATH_H
