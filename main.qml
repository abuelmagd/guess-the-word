import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.VirtualKeyboard 2.4
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Shapes 1.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Guess The Word")
    signal newGameButtonClick()
    ColumnLayout {
        id: layout
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        Row {
            Layout.alignment: "AlignHCenter"
            Label {
                id: label
                objectName: "label"
                //text: This label is for debugging and text is set from C++ side
                Layout.alignment: "AlignHCenter"
            }
        }
        Row {
            Layout.alignment: "AlignHCenter"
            Button {
                text: "New Game"
                onClicked: newGameButtonClick()
            }
        }

        Row {
            Layout.alignment: "AlignHCenter"
            Shape {
                id: hangedMan
                Layout.alignment: "AlignHCenter"
                ShapePath {
                    strokeWidth: 5
                    strokeColor: "black"
                    startX: 20
                    startY: layout.height
                    PathLine {
                        id: firstLine
                        x: 100
                        y: 100
                    }
                    PathLine {
                        x: 20
                        y: 100
                    }
                    PathLine {
                        x: 20
                        y: 20
                    }
                }
            }
        }
    }

    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}
