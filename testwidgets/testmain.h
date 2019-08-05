#ifndef TESTMAIN_H
#define TESTMAIN_H

#include <QMainWindow>

namespace Ui {
class testmain;
}

class testmain : public QMainWindow
{
    Q_OBJECT

public:
    explicit testmain(QWidget *parent = 0);
    ~testmain();

private:
    Ui::testmain *ui;
};

#endif // TESTMAIN_H
