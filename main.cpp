#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "appcoordinator.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    AppCoordinator coordinator(&app);

    QQmlApplicationEngine engine;

    coordinator.setupApplication(&engine);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Qtie", "Main");

    return app.exec();
}
