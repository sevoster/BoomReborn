import QtQuick 2.0

Item {
    Item {
        Text {
            text: "Score: ---"
        }
    }

    Grid {
        id: gameField

        property double widthIndent: 1.2
        property double heightIndent: 1.3
        width: startMenu.width / widthIndent
        height: startMenu.height / heightIndent

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        columns: 20
        rows: 10
        spacing: 1


        Repeater {
            model: gameField.rows * gameField.columns

            delegate: Block {}
        }

}
}
