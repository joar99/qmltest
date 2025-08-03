import QtQuick
import QtQuick.Controls

Rectangle {
    required property var viewModel

    anchors.fill: parent
    color: "lightblue"

    Column {
        anchors.centerIn: parent
        spacing: 20

        Button {
            text: viewModel.controlValue.toString()
            onClicked: viewModel.setControlValue(viewModel.controlValue + 1)
        }

        Button {
            text: "Navigate to Second Screen"
            onClicked: viewModel.didTapNavigateToSecondScreen()
        }
    }
}
