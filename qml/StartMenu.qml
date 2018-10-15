import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

ColumnLayout {
    id: startMenu

    states: [
        State {
            name: "start"
            PropertyChanges {
                target: continueBtn
                visible: false
            }
        },
        State {
            name: "pause"
            PropertyChanges {
                target: continueBtn
                visible: true
            }
        }
    ]
    state: "start"

    signal continueGame();
    signal startNewGame();
    signal exit();

    spacing: 10

    readonly property int btnWidth: startMenu.width / 4
    readonly property int btnMinWidth: 120
    readonly property int contentAlignment: Qt.AlignCenter
    MenuLogo {
        Layout.alignment: contentAlignment
        // TODO: margins should be redesigned
        Layout.topMargin: startMenu.height / 4
        Layout.bottomMargin: startMenu.height / 6
    }
    MenuButton {
        id: continueBtn
        Layout.alignment: contentAlignment
        Layout.preferredWidth: startMenu.btnWidth
        Layout.minimumWidth: startMenu.btnMinWidth
        text: "Continue"
        onClicked: startMenu.continueGame()
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
