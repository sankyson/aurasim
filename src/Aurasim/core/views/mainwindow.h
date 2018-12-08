#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "workspacewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void initUI();

signals:

public slots:

private:
    QSharedPointer<WorkspaceWidget> mWorkspace;
};

#endif // MAINWINDOW_H
