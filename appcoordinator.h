#ifndef APPCOORDINATOR_H
#define APPCOORDINATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "controlviewmodel.h"

class AppCoordinator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentScreen READ currentScreen NOTIFY currentScreenDidChange)
public:
    explicit AppCoordinator(QObject* parent = nullptr);

    void setupApplication(QQmlApplicationEngine* engine);

    QString currentScreen() const { return m_currentScreen; }

public slots:
    void navigateToSecondScreen();
    void navigateBack();

signals:
    void currentScreenDidChange();

private:
    void createViewModels();
    void registerQmlTypes();
    void exposeToQml(QQmlApplicationEngine* engine);

    ControlViewModel* m_controlViewModel;
    QQmlApplicationEngine* m_engine;

    QString m_currentScreen;
};

#endif // APPCOORDINATOR_H
