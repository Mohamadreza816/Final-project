import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: element
    //Connections for get error message
    Connections{
        target: doctor
        onNoticemessagedoctor:{
            meesage.text = note
        }
    }
    //label for show error messages
    Row {
        id: row1
        x: parent.width/2 - 60
        y: parent.height - 70

        width: 400
        height: 80

        Label{
            id : meesage
            text: ""
            //anchors.fill: parent
            font.pointSize: 18
            color: "black"
            font.bold: true
        }
    }
    //special buttons
    Buystation {
        id: btnbuy
        x: 30
        y: parent.height - 250
        width: 90
        height: 90
        colornormal: "red"
        source: "qrc:/images/34627.png"
        onClicked: {
            stackview.push("qrc:/Buyzone.qml")
            doctor.get_coin()
            pilldevice.get_count()
            ampouledevice.get_count()
        }
    }
    Buystation {
        id: btntreat
        x: 30
        y: parent.height - 120
        width: 90
        height: 90
        source: "qrc:/images/game.png"
        onClicked: {
            stackview.push("qrc:/Treatment.qml")
            doctor.get_coin()
            pilldevice.get_count()
            ampouledevice.get_count()
            person.get_health_count()
            person.get_sick_count()
        }
    }
    Buystation{
        id : btnboost
        width: 90
        height: 90
        colornormal: "#5DADEC"
        x : parent.width - 120
        y : 35
        source: "qrc:/images/energy-drink.png"
        onClicked: {
            doctor.boost_energy()

        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
