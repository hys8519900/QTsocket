#ifndef EVENTLABEL_H
#define EVENTLABEL_H

#include <QLabel>
#include <QApplication>
#include <QWidget>
#include <QMouseEvent>

//test for mouse Event

class EventLabel : public QLabel
{
    Q_OBJECT
public:
    explicit EventLabel(QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:

};

#endif // EVENTLABEL_H
