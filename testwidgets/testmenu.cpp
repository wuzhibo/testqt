#include "testmenu.h"
#include "ui_testmenu.h"

testmenu::testmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testmenu)
{
    ui->setupUi(this);
}

testmenu::~testmenu()
{
    delete ui;
}
