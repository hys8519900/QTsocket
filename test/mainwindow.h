#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLabel>

class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QAction *openAction;
    QLabel *msgLabel;

signals:

private slots:
    void open();
};

#endif // MAINWINDOW_H
