#include "aurasim.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

Aurasim::Aurasim(QObject *parent) :
    QObject(parent),
    appWindow(nullptr)
{
    initApp();
}

void Aurasim::initApp()
{
    QSize desktopSize = qApp->screens().first()->availableGeometry().size();
    appWindow.resize(desktopSize * 0.8);
    appWindow.move((desktopSize.width() - appWindow.width()) / 2, (desktopSize.height() - appWindow.height()) / 2);
    appWindow.show();
}
