#include "testimage.h"
#include "ui_testimage.h"

testimage::testimage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testimage)
{
    ui->setupUi(this);
    canDraw = false;
    pix = NULL;

}

testimage::~testimage()
{
    delete ui;
}

void testimage::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::currentPath(), tr("Iamge Files (*.jpg *jpeg)"));
    if(!fileName.isEmpty())
    {
        QPixmap *newPix = new QPixmap(fileName);
        if(!newPix->isNull())
        {
            if(newPix->width() < 150 || newPix->height() < 150)
            {
                QMessageBox::warning(this, tr("Invali Size"), tr("Image size too small. Please use an image larger than 150 x 150."));
                return;
            }
            pix = newPix;
            imageSize = pix->size();
            drawSize = pix->size();
            canDraw = true;
        }
    }else
    {
        canDraw = false;
        QMessageBox::warning(this, tr("Invalid Image"), tr("Invalid or corrupted file. Please try again with another image file."));
    }
}


void testimage::paintEvent(QPaintEvent *event)
{
    if(canDraw)
    {
        paintImage("", ui->prouctImage->pos().x(), ui->prouctImage->pos().y());
    }
}

void testimage::paintImage(QString fileName, int x, int y)
{
    QPainter painter;
    QImage saveIamge(150, 150, QImage::Format_RGB16);
    if(!fileName.isEmpty())
    {
        painter.begin(&saveIamge);
    }else{
        painter.begin(this);
    }
    if(!pix->isNull())
    {
        painter.setClipRect(x, y, 150, 150);
        painter.fillRect(QRect(x, y, 150, 150), Qt::SolidPattern);
        painter.drawPixmap(x - drawPos.x(), y - drawPos.y(), drawSize.width(), drawSize.height(), *pix);
    }

    painter.end();
    if(fileName != "")
    {
        saveIamge.save(fileName);
        QMessageBox::information(this, "Success", "Image has been successfully saved!");
    }
}

void testimage::on_pushButton_2_clicked()
{
    if(canDraw)
    {
        if(!pix->isNull())
        {
            paintImage(QCoreApplication::applicationDirPath() + "/image.jpg", 0, 0);
        }
    }
}

void testimage::on_scale_valueChanged(int value)
{
    drawSize = imageSize * value / 100;
    update();
}

void testimage::on_horizontal_valueChanged(int value)
{
    drawPos.setX(value * drawSize.width() / 100 * 0.5);
    update();
}

void testimage::on_vertical_valueChanged(int value)
{
    drawPos.setY(value * drawSize.height() / 100 * 0.5);
    update();
}
