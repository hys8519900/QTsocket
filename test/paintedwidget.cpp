#include "paintedwidget.h"
#include <QPainter>
#include <QImage>

PaintedWidget::PaintedWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(400,300);
    setWindowTitle(tr("Paint Demo"));
}

void PaintedWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    /*
    painter.setWindow(-50,-50,100,100);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(QPen(Qt::black,2,Qt::DashDotLine,Qt::RoundCap));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(0,0,30,45);
    */
    /*
    QFont font("Courier",24);
    painter.setFont(font);
    painter.drawText(50,50,"Hello World");
    QTransform transform;
    transform.rotate(+45.0);
    painter.setWorldTransform(transform);
    painter.drawText(60,60,"Hello World");
    */
    QPixmap pixmap;
    pixmap.loadFromData((const uchar *)strpic_.c_str(),(int)strpic_.size());
    painter.drawPixmap(0,0,pixmap);
}

void PaintedWidget::getStrPic(const std::string& strpic)
{
     strpic_ = strpic;
}
