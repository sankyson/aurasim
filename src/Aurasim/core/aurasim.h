#ifndef AURASIM_H
#define AURASIM_H

#include <QObject>
#include "views/mainwindow.h"

class Aurasim : public QObject
{
    Q_OBJECT
public:
    explicit Aurasim(QObject *parent = nullptr);

    void initApp();

signals:

public slots:

private:
    MainWindow appWindow;
};

#endif // AURASIM_H
