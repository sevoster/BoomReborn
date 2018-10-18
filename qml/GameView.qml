import QtQuick 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    id: _gameView

    Text {
        Layout.alignment: Qt.AlignLeft
        text: "Score: ---"
    }

    GridLayout {
        id: gameField

        Layout.alignment: Qt.AlignCenter
        Layout.margins: 20

        columns: 20
        rows: 10
        columnSpacing: 1
        rowSpacing: 1

        Repeater {
            model: gameField.rows

            Repeater {
                property int rowIndex: index
                model: gameField.columns

                delegate: Block {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    // magic of field generation
                    color: getColor(rowIndex, index, gameField.rows, gameField.columns)
                }
            }
        }
    }

    function getColor(row, column, rows, columns)
    {
        if (row === 0 || row === rows - 1 || column === 0 || column === columns - 1)
            return "black"
        if ((Math.random() * 100) % 2 < 1) return "grey"
        return "white"
    }
}
