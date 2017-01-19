import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

Item {
    id: outputPage

    TabView {
        anchors.fill: parent
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

}
