import QtQuick 2.0

Component {
    id: block

    Rectangle {
        color: "red"

        width: (startMenu.width / (gameField.columns * gameField.widthIndent)) - gameField.spacing
        height: (startMenu.height / (gameField.rows * gameField.heightIndent)) - gameField.spacing
    }
}
