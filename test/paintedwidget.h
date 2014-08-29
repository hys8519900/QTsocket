#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>
#include <string>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintedWidget(QWidget *parent = 0);
    void getStrPic(const std::string& strpic);

protected:
    void paintEvent(QPaintEvent *event);

private:
    std::string strpic_;

signals:

public slots:

};

#endif // PAINTEDWIDGET_H
