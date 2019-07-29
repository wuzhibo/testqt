#ifndef TESTIMAGE_H
#define TESTIMAGE_H

#include <QWidget>
#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>

namespace Ui {
class testimage;
}

class testimage : public QWidget
{
    Q_OBJECT

public:
    explicit testimage(QWidget *parent = 0);
    ~testimage();
    virtual void paintEvent(QPaintEvent *event);
    void paintImage(QString fileName, int x, int y);
private slots:
    void on_pushButton_clicked();

private:
    Ui::testimage *ui;
    bool canDraw;
    QPixmap* pix;
    QSize imageSize;
    QSize drawSize;
    QPoint drawPos;

};

#endif // TESTIMAGE_H
