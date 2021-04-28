#ifndef SOUVENIRSHOP_H
#define SOUVENIRSHOP_H

#include <QMainWindow>

namespace Ui {
class souvenirshop;
}

class souvenirshop : public QMainWindow
{
    Q_OBJECT

public:
    explicit souvenirshop(QWidget *parent = nullptr);
    ~souvenirshop();

private:
    Ui::souvenirshop *ui;
};

#endif // SOUVENIRSHOP_H
