import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Shapes 1.12

Window {
    id: window
    width: 800
    height: 600
    visible: true
    title: qsTr("Guess The Word")
    signal newGameButtonClick()
    signal newLetterGuess(string k)
    ColumnLayout {
        id: layout
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        Keys.onPressed: {
            newLetterGuess(event.text);
            event.accepted = true;
        }
        Row {
            Layout.alignment: "AlignHCenter"
            Label {
                id: label
                objectName: "TheWord"
                Layout.alignment: "AlignHCenter"
                font.pixelSize: 64
            }
        }
        Row {
            Layout.alignment: "AlignHCenter"
            Label {
                id: wrongGuesses
                objectName: "WrongGuesses"
                Layout.alignment: "AlignHCenter"
                font.pixelSize: 64
            }
        }

        Row {
            Layout.alignment: "AlignHCenter"
            Button {
                text: "New Game"
                onClicked: newGameButtonClick()
                focus: true
                Keys.forwardTo: layout
            }
        }

//        Row {
//            Layout.alignment: "AlignHCenter"
//            Shape {
//                id: hangedMan
//                Layout.alignment: "AlignHCenter"
//                ShapePath {
//                    strokeWidth: 5
//                    strokeColor: "black"
//                    startX: 20
//                    startY: layout.height
////                    PathLine {
////                        id: firstLine
////                        x: 100
////                        y: 100
////                    }
//                }
//            }
//        }
    }
}
