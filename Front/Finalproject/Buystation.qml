import QtQuick 2.0
import QtGraphicalEffects 1.0
import QtLocation 5.11
Item {

    id : root
    property color colorborder: "darkred"
    property color colornormal: "red"
    property color colorhover: "orange"
    property string source: ""

    signal clicked()

    Rectangle{
        clip: true
        id : body
        radius: width
        visible: true
        color : root.colornormal
        border.width: 2
        border.color: root.colorborder
        anchors.fill: parent

        MouseArea{
            id : area
            anchors.fill: parent
            hoverEnabled: true
            onPressed: {
                root.clicked()
            }

            onEntered: {
                body.color = root.colorhover
            }
            onExited: {
                body.color = root.colornormal
            }
        }

        Image {
            id: image
            anchors.rightMargin: 15
            anchors.bottomMargin: 10
            anchors.leftMargin: 12
            anchors.topMargin: 10
            anchors.fill: parent
            source: root.source
            fillMode: Image.PreserveAspectFit
        }

    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
