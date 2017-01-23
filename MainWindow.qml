import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

Item {
    id: mainPage
    width: 800
    height: 600

    ColumnLayout {
        anchors.fill: parent

        GroupBox {
            id: classDef
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: qsTr("Class definiton")

            GridLayout {
                rows: 2
                columns: 2
                anchors.fill: parent

                Label {
                    text: qsTr("&Name")
                    Layout.row: 0
                    Layout.column: 0
                }

                TextField {
                    id: name
                    font.family: "Courier"
                    placeholderText: qsTr("class name")
                    Layout.row: 0
                    Layout.column: 1
                    Layout.minimumWidth: 80
                    Layout.fillWidth: true
                    onTextChanged: {
                        m_codeGen.name = text
                    }
                }

                Label {
                    text: qsTr("&Mother class")
                    Layout.row: 1
                    Layout.column: 0
                }

                TextField {
                    id: motherClass
                    font.family: "Courier"
                    placeholderText: qsTr("mother class")
                    Layout.row: 1
                    Layout.column: 1
                    Layout.minimumWidth: 80
                    Layout.fillWidth: true
                    onTextChanged: {
                        m_codeGen.motherClass = text
                    }
                }
            }
        }

        GroupBox {
            id: options
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: qsTr("Options")
            property bool headerVisibility: false

            GridLayout {
                anchors.fill: parent
                rows: 3
                columns: 2

                CheckBox {
                    id: checkHeader
                    text: qsTr("&Header protection")
                    Layout.row: 0
                    Layout.column: 0
                    onCheckedChanged: {
                        options.headerVisibility = checked
                        m_codeGen.headerProtectionChecked = checked
                    }
                }

                CheckBox {
                    id: checkConstructor
                    text: qsTr("Generate default &constructor")
                    Layout.row: 1
                    Layout.column: 0
                    onCheckedChanged: {
                        m_codeGen.constructor = checked
                    }
                }

                CheckBox {
                    id: checkDestructor
                    text: qsTr("Generate &destructor")
                    Layout.row: 2
                    Layout.column: 0
                    onCheckedChanged: {
                        m_codeGen.destructor = checked
                    }
                }

                TextField {
                    id: headerEdit
                    font.family: "Courier"
                    Layout.row: 0
                    Layout.column: 1
                    Layout.fillHeight: false
                    Layout.fillWidth: true
                    visible: options.headerVisibility;
                    text: m_codeGen.headerProtection
                    onAccepted: {
                        m_codeGen.headerProtection = text
                    }
                }
            }
        }

        GroupBox {
            id: comments
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: qsTr("&Comments")
            checkable: true
            checked: false
            onCheckedChanged: {
                m_codeGen.comments = checked
            }

            GridLayout {
                anchors.fill: parent

                Label {
                    text: qsTr("&Author")
                    Layout.row: 0; Layout.column: 0
                }

                TextField {
                    id: author
                    font.family: "Courier"
                    Layout.fillWidth: true
                    placeholderText: qsTr("author")
                    Layout.row: 0; Layout.column: 1
                    onTextChanged: {
                        m_codeGen.author = text
                    }
                }

                Label {
                    text: qsTr("&Role")
                    Layout.alignment: Qt.AlignTop
                    Layout.row: 1; Layout.column: 0
                }

                TextArea {
                    id: classRole
                    font.family: "Courier"
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.row: 1; Layout.column: 1
                    onTextChanged: {
                        m_codeGen.classRole = text
                    }
                }


            }
        }

        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignRight

            Button {
                id: generateButton
                text: qsTr("generate")
                onClicked: {
                    m_codeGen.generateCode()
                }
            }

            Button {
                id: quitButton
                text: qsTr("quit")
                onClicked: Qt.quit()
            }
        }
    }
}
