import QtQuick 2.12
import QtQuick.Controls 2.12
Item {
    anchors.fill : parent
    StackView{
        id : stackview
        anchors.fill: parent
        initialItem: "qrc:/MyButton.qml"
    }
}
