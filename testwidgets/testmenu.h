#ifndef TESTMENU_H
#define TESTMENU_H

#include <QWidget>

namespace Ui {
class testmenu;
}

class testmenu : public QWidget
{
    Q_OBJECT

public:
    explicit testmenu(QWidget *parent = 0);
    ~testmenu();

private:
    Ui::testmenu *ui;
};

#endif // TESTMENU_H
