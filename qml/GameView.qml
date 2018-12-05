import QtQuick 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    id: _gameView
    property var gameFieldModel: null

    Text {
        Layout.alignment: Qt.AlignLeft
        text: "Score: ---"
    }

    GridLayout {
        id: gameField

        Layout.alignment: Qt.AlignCenter
        Layout.margins: 20

        columns: gameFieldModel.columnCount()
        rows: gameFieldModel.rowCount()
        columnSpacing: 1
        rowSpacing: 1

        Repeater {
            model: dataModel

            Repeater {
                property int rowIndex: index
                model: gameField.columns

                delegate: Block {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: gameFieldModel.getColor(rowIndex, index)
                }
            }
        }
    }
}
