import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

ColumnLayout {
    id: startMenu

    signal startNewGame();
    signal exit();

    spacing: 20

    property int btnWidth: startMenu.width / 4
    property int btnMinWidth: 120
    property int contentAlignment: Qt.AlignCenter
    MenuLogo {
        Layout.alignment: contentAlignment
        // TODO: margins should be redesigned
        Layout.topMargin: startMenu.height / 4
        Layout.bottomMargin: startMenu.height / 6
    }
    MenuButton {
        Layout.alignment: contentAlignment
        Layout.preferredWidth: startMenu.btnWidth
        Layout.minimumWidth: startMenu.btnMinWidth
        text: "Start New Game"
        onClicked: startMenu.startNewGame()
    }
    MenuButton {
        Layout.alignment: contentAlignment
        Layout.preferredWidth: startMenu.btnWidth
        Layout.minimumWidth: startMenu.btnMinWidth
        text: "Settings"
    }
    MenuButton {
        Layout.alignment: startMenu.contentAlignment
        Layout.preferredWidth: startMenu.btnWidth
        Layout.minimumWidth: startMenu.btnMinWidth
        text: "Exit"
        onClicked: startMenu.exit()
    }
    Item {
        Layout.fillHeight: true
    }
}
