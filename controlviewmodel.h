#ifndef CONTROLVIEWMODEL_H
#define CONTROLVIEWMODEL_H

#include <QString>
#include <QObject>

class AppCoordinator;

class ControlViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int controlValue READ fetchControlValue WRITE setControlValue NOTIFY controlValueDidChange)
    Q_PROPERTY(QString buttonName READ getButtonName CONSTANT)

private:
    int controlValue;
    QString buttonName;
    AppCoordinator* m_coordinator;

public:
    ControlViewModel(int value, const QString& name, QObject* parent = nullptr);

    void setCoordinator(AppCoordinator* coordinator);

    int fetchControlValue() const;
    QString getButtonName() const;

public slots:
    void setControlValue(int valueToUpdateWith);
    void didTapNavigateToSecondScreen();

signals:
    void controlValueDidChange();
};

#endif // CONTROLVIEWMODEL_H

