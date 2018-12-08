#include <QApplication>
#include <QDesktopWidget>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "core/aurasim.h"

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

    Aurasim aurasim;
    aurasim.initApp();

    return app.exec();
}
