#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initUI();
    initConnections();
}

void MainWindow::initUI()
{
    this->resize(800, 500);
    mPlaground = QSharedPointer<Playground>(new Playground(this));
    this->setCentralWidget(mPlaground.data());
}

void MainWindow::initConnections()
{

}
