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

        property double widthIndent: 1.2
        property double heightIndent: 1.3

        columns: 20
        rows: 10
        columnSpacing: 1
        rowSpacing: 1

        Repeater {
            model: gameField.rows * gameField.columns

            delegate: Block {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
    }
}
