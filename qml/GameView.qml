import QtQuick 2.0


Item {
    Grid {
        id: gameField

        width: startMenu.width - 20
        height: startMenu.height - 10
        x: 0
        y: 0
        columns: 20
        rows: 10
        spacing: 1

        Repeater {
            model: gameField.rows * gameField.columns

            Rectangle {
                color: "red"
                width: if(gameField.width > 2 * gameField.height) {gameField.height/10} else {gameField.width/20}
                height: if(gameField.width > 2 * gameField.height) {gameField.height/10} else {gameField.width/20}
            }
        }

}
}
