import QtQuick 2.9
import QtQuick.Controls 2.0

Column {
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Boom Reborn"
        font.family: "Helvetica"
        font.pointSize: 28
        color: "red"
    }
    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Start New Game"
    }
}