#include "testcharts.h"
#include "ui_testcharts.h"

testcharts::testcharts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testcharts)
{
    ui->setupUi(this);
}

testcharts::~testcharts()
{
    delete ui;
}
