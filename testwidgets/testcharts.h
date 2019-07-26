#ifndef TESTCHARTS_H
#define TESTCHARTS_H

#include <QWidget>

namespace Ui {
class testcharts;
}

class testcharts : public QWidget
{
    Q_OBJECT

public:
    explicit testcharts(QWidget *parent = 0);
    ~testcharts();

private:
    Ui::testcharts *ui;
};

#endif // TESTCHARTS_H
