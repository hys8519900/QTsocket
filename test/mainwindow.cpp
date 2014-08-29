#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QKeySequence>
#include <QToolBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QFileDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    openAction = new QAction(tr("&Open"),this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a file."));
    openAction->setIcon(QIcon(":/s.png"));
    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    msgLabel = new QLabel;
    msgLabel->setMinimumSize(msgLabel->sizeHint());
    msgLabel->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(msgLabel);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    /*
   QString path = QFileDialog::getOpenFileName(this,tr("Open Image"),
                    ".",tr("Image Files(*.jpg *.png)"));
   if(path.length() == 0)
   {
       QMessageBox::information(NULL,tr("Path"),tr("You didn't select any files."));
   }
   else
   {
       QMessageBox::information(NULL,tr("Path"),tr("You selected ")+path);
   }
   */
   QColor color = QColorDialog::getColor(Qt::white,this);
   QString msg = QString("r: %1,g: %2,b: %3").arg(QString::number(color.red()),
                                                  QString::number(color.green()),
                                                  QString::number(color.blue()));
   QMessageBox::information(NULL,"Selected color",msg);

}
