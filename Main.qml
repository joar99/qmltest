import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ControlView {
        viewModel: controlViewModel
        visible: appCoordinator.currentScreen === "ControlView"
        anchors.fill: parent
    }

    SecondNavView {
        visible: appCoordinator.currentScreen === "SecondNavView"
        anchors.fill: parent

        Button {
            text: "Go Back"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: appCoordinator.navigateBack()
        }
    }
}
