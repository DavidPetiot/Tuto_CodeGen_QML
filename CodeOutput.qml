import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

Item {
    id: outputPage
    signal closeWindow()

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        TabView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            tabsVisible: true
            Tab{
                id: tab
                title: qsTr("Hpp")
                TextArea {
                    id: hppOutput
                    anchors.fill: parent
                    text: m_codeGen.hppCode
                }

            }

            Tab{
                title: qsTr("Cpp")
                TextArea {
                    id: cppOutput
                    anchors.fill: parent
                    text: m_codeGen.cppCode
                }

            }
        }

        RowLayout {
            id: rowLayout
            Layout.alignment: Qt.AlignRight

            Button {
                id: saveButton
                text: qsTr("save")
                onClicked: m_codeGen.saveCode()
            }

            Button {
                id: closeButton
                text: qsTr("close")
                onClicked: outputPage.closeWindow()
            }
        }
    }

}
