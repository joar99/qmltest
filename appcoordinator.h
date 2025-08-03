#ifndef APPCOORDINATOR_H
#define APPCOORDINATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "controlviewmodel.h"

class AppCoordinator : public QObject
{
    Q_OBJECT
public:
    explicit AppCoordinator(QObject* parent = nullptr);

    void setupApplication(QQmlApplicationEngine* engine);

public slots:
    void navigateToSecondScreen();

private:
    void createViewModels();
    void registerQmlTypes();
    void exposeToQml(QQmlApplicationEngine* engine);

    ControlViewModel* m_controlViewModel;
    QQmlApplicationEngine* m_engine;
};

#endif // APPCOORDINATOR_H
