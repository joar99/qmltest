#include "controlviewmodel.h"
#include "appcoordinator.h"
#include <QString>

ControlViewModel::ControlViewModel(int value, const QString& name, QObject* parent)
    : QObject(parent), controlValue(value), buttonName(name), m_coordinator(nullptr)
{
}

int ControlViewModel::fetchControlValue() const
{
    return controlValue;
}

void ControlViewModel::setControlValue(int valueToUpdateWith)
{
    if (controlValue != valueToUpdateWith) {
        controlValue = valueToUpdateWith;
        emit controlValueDidChange();
    }
}

QString ControlViewModel::getButtonName() const
{
    return buttonName;
}

void ControlViewModel::setCoordinator(AppCoordinator* coordinator)
{
    m_coordinator = coordinator;
}

void ControlViewModel::didTapNavigateToSecondScreen()
{
    qDebug() << "ControlViewModel: User tapped navigate button";
    if (m_coordinator) {
        m_coordinator->navigateToSecondScreen();
    }
}
