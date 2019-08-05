#include "testmain.h"
#include "ui_testmain.h"

testmain::testmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testmain)
{
    ui->setupUi(this);
    ui->menuBar->setNativeMenuBar(false);
    ui->menuBar->setNativeMenuBar(false);

}

testmain::~testmain()
{
    delete ui;
}
