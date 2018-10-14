import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

ColumnLayout {
    id: startMenu

    signal startNewGame();
    signal exit();

    spacing: 20

    property int btnWidth: width / 4
    property int contentAlignment: Qt.AlignCenter
    Text {
        Layout.alignment: contentAlignment
        // TODO: margins should be redesigned
        Layout.topMargin: parent.height / 4
        Layout.bottomMargin: parent.height / 6
        text: "Boom Reborn"
        font.family: "Helvetica"
        font.pointSize: 40
        color: "red"
    }
    Button {
        Layout.alignment: contentAlignment
        Layout.preferredWidth: btnWidth
        text: "Start New Game"
        onClicked: startMenu.startNewGame()
    }
    Button {
        Layout.alignment: contentAlignment
        Layout.preferredWidth: btnWidth
        text: "Settings"
    }
    Button {
        Layout.alignment: contentAlignment
        Layout.preferredWidth: btnWidth
        text: "Exit"
        onClicked: startMenu.exit()
    }
    Item {
        Layout.fillHeight: true
    }
}
