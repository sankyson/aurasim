#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "core/views/mainwindow.h"
#include <QDesktopWidget>
#include <QScreen>
#include "core/chips/arduino.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("arduino", new Arduino());
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;
//    Arduino arduino;
//    arduino.start();

    MainWindow w;
    QSize desktopSize = app.screens().first()->availableGeometry().size();
    w.resize(desktopSize * 0.8);
    w.move((desktopSize.width() - w.width()) / 2, (desktopSize.height() - w.height()) / 2);
    w.show();

    return app.exec();
}
