import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ControlView {
        viewModel: controlViewModel
        anchors.fill: parent

        opacity: appCoordinator.currentScreen === "ControlView" ? 1.0 : 0.0
        scale: appCoordinator.currentScreen === "ControlView" ? 1.0 : 0.95
        visible: opacity > 0

        Behavior on opacity {
            NumberAnimation { duration: 250; easing.type: Easing.InOutQuad }
        }
        Behavior on scale {
            NumberAnimation { duration: 250; easing.type: Easing.InOutQuad }
        }
    }

    SecondNavView {
        anchors.fill: parent

        opacity: appCoordinator.currentScreen === "SecondNavView" ? 1.0 : 0.0
        scale: appCoordinator.currentScreen === "SecondNavView" ? 1.0 : 0.95
        visible: opacity > 0

        Behavior on opacity {
            NumberAnimation { duration: 250; easing.type: Easing.InOutQuad }
        }
        Behavior on scale {
            NumberAnimation { duration: 250; easing.type: Easing.InOutQuad }
        }

        Button {
            text: "Go Back"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: appCoordinator.navigateBack()
        }
    }
}
