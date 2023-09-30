import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 400
    height: 550
    visible: true
    title: qsTr("QAbstractListModel Example")

    PrintService {
        id: printService
    }

    // Footer with input fields and buttons
    footer: ToolBar {
        RowLayout {
            anchors.fill: parent
            TextField {
                id: nameField
                placeholderText: "Name"
                clip: true
                Layout.fillWidth: true
            }

            TextField {
                id: typeField
                placeholderText: "Type"
                clip: true
                Layout.fillWidth: true
            }

            ToolButton {
                text: "Add"
                enabled: nameField.text.length > 0 && typeField.text.length > 0
                onClicked: {
                    animalModel.push(nameField.text, typeField.text)
                    nameField.text = ""
                    typeField.text = ""
                }
            }

            ToolButton {
                text: "Print"
                onClicked: {
                    console.log("-------------------------------------------")
                    animalModel.print()
                    printService.print(animalModel.getAnimalsForQML())
                }
            }
        }
    }

    // List of animals and their types
    ListView {
        model: animalModel
        anchors.fill: parent
        delegate: RowLayout {
            width: parent?.width
            Text {
                text: name + " (" + type + ")"
                font.pixelSize: 24
                color: "white"
            }
            Item {
                Layout.fillWidth: true
            }
            ToolButton {
                text: "x"
                onClicked: {
                    animalModel.remove(index)
                }
            }
        }
    }
}
