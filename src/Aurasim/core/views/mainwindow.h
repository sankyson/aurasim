#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../widgets/playground.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void initUI();
    void initConnections();

signals:

public slots:

private:
    QSharedPointer<Playground> mPlaground;
};

#endif // MAINWINDOW_H
