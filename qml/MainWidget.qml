import QtQuick 2.0

import "menu"

Item {
    id: mainWidget
    focus: true
    property alias gameFieldModel: gameView.gameFieldModel

    states: [
        State {
            name: "start"
            PropertyChanges {
                target: startMenu
                visible: true
                state: "start"
            }
            PropertyChanges {
                target: gameView
                visible: false
            }
        },
        State {
            name: "game"
            PropertyChanges {
                target: startMenu
                visible: false
            }
            PropertyChanges {
                target: gameView
                visible: true
            }
        },
        State {
            name: "pause"
            PropertyChanges {
                target: startMenu
                visible: true
                state: "pause"
            }
            PropertyChanges {
                target: gameView
                visible: false
            }
        }
    ]
    state: "start"

    Keys.onEscapePressed: {
        if (state === "start")
            return
        state = state === "game" ? "pause" : "game"
    }

    StartMenu {
        id: startMenu
        anchors.fill: parent
        onExit: close()
        onStartNewGame: {
            console.log("Start new game...")
            mainWidget.state = "game"
            // GameView start new game
        }
        onContinueGame: {
            console.log("Continue game...")
            mainWidget.state = "game"
        }
    }

    GameView {
        id: gameView
        anchors.fill: parent
        visible: false
    }
}
