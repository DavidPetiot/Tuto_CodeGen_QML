import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("Code generator")

    MainWindow{
        id: configWindow
        anchors.fill: parent
    }

    Dialog{
        id: outputDialog
        width: 400
        height: 300
        visible: m_codeGen.outputDialogVisibility

        contentItem: CodeOutput{
            onCloseWindow: outputDialog.close()
        }
    }

    MessageDialog{
        id: popup
        title: m_codeGen.errorTitle
        text: m_codeGen.errorMessage
    }

    Connections{
        target: m_codeGen
        onErrorChanged: popup.open()
    }

}
