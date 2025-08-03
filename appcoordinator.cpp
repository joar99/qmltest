#include "appcoordinator.h"
#include <QQmlContext>
#include <QDebug>

AppCoordinator::AppCoordinator(QObject* parent)
    : QObject(parent), m_controlViewModel(nullptr), m_engine(nullptr), m_currentScreen("ControlView")
{
    createViewModels();
}

void AppCoordinator::setupApplication(QQmlApplicationEngine* engine)
{
    m_engine = engine;
    registerQmlTypes();
    exposeToQml(engine);
}

void AppCoordinator::createViewModels()
{
    m_controlViewModel = new ControlViewModel(42, "Click Me", this);
    m_controlViewModel->setCoordinator(this);
}

void AppCoordinator::registerQmlTypes()
{

}

void AppCoordinator::exposeToQml(QQmlApplicationEngine* engine)
{
    engine->rootContext()->setContextProperty("controlViewModel", m_controlViewModel);
    engine->rootContext()->setContextProperty("appCoordinator", this);
}

void AppCoordinator::navigateToSecondScreen()
{
    m_currentScreen = "SecondNavView";
    emit currentScreenDidChange();
}

void AppCoordinator::navigateBack()
{
    m_currentScreen = "ControlView";
    emit currentScreenDidChange();
}
