import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

Item {
    width: 200
    height: 100
    property alias message: message.text

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        Text {
            id: message
            Layout.fillHeight: true
            Layout.fillWidth: true
            font.pixelSize: 12
        }

        RowLayout {
            id: rowLayout
            width: 100
            height: 100
            Layout.alignment: Qt.AlignRight
            Layout.fillWidth: true

            Button {
                id: acceptButton
                text: qsTr("Accept")
                isDefault: true
                onClicked: popup.visible = false
            }

            Button {
                id: rejectButton
                text: qsTr("Reject")
                isDefault: false
            }
        }
    }

}
