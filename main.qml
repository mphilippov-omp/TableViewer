import QtQuick 2.13
import QtQuick.Controls 2.13

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    ScrollView {
        anchors.fill: parent

        TableView {
            id: table
            anchors.fill: parent
            model: tableModel

            delegate: Rectangle {
                implicitHeight: 50
                implicitWidth: 200
                border.color: "black"
                border.width: 1
                Text {
                    text: display
                }
            }
        }
    }
}
