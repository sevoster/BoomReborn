import QtQuick 2.0

Item {
    id: mainWidget
    focus: true

    states: [
        State {
            name: "Menu"
            PropertyChanges {
                target: startMenu
                visible: true
            }
            PropertyChanges {
                target: gameView
                visible: false
            }
        },
        State {
            name: "Game"
            PropertyChanges {
                target: gameView
                visible: true
            }
            PropertyChanges {
                target: startMenu
                visible: false
            }
        }
    ]
    state: "Menu"

    Keys.onEscapePressed: state = state === "Game" ? "Menu" : "Game"

    StartMenu {
        id: startMenu
        anchors.fill: parent
        onExit: close()
        onStartNewGame: {
            console.log("Start new game...")
            mainWidget.state = "Game"
        }
    }

    GameView {
        id: gameView
        anchors.fill: parent
    }
}
