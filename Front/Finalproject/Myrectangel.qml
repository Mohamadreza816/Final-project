import QtQuick 2.0

Item {
    id: root
    property color reccolor: "red"
    property alias title: display
    property alias mouse: mousearea

    Rectangle{
        width: 150
        height: 35
        color: reccolor

        border.color: "#000000"
        border.width: 3
        radius: 20
        Text {
            id: display
            anchors.centerIn: parent
            font.bold: true
            text: ""
        }
        MouseArea{
            id: mousearea
            anchors.fill: parent
            onClicked:{

            }
        }
        Rectangle{
            id : col
            height: 35
            width: 0
        }
    }
}
