#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mWorkspace(QSharedPointer<WorkspaceWidget>(new WorkspaceWidget(this)))
{
    initUI();
}

void MainWindow::initUI()
{
    this->setCentralWidget(mWorkspace.data());
}
