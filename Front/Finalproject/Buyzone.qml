//import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.2
import QtQuick.Window 2.12

Item {
    property alias click: root
    property var check: 0
    id: root
    visible : true
    //Connections for get data of coin, pill and ampoule and also for get error messages
    Connections{
        target: doctor
        onNoticecoin:{
            coin.title.text = "Coin: " + data
        }
    }
    Connections{
        target: pilldevice
        onNoticegetpillcount:{
            pill_count.title.text = "Pill: " + data
        }
        onNoticemessage:{
            messagelb.text = note
        }

    }
    Connections{
        target: ampouledevice
        onNoticgetampoulecount:{
            ampoule_count.title.text = "Ampoule: " + data
        }
        onNoticeampoulemessage:{
            messagelb.text = note
        }
    }

    Rectangle{
        id : buyrec
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill : root
        //store image
        Image {
            id: store
            anchors.leftMargin: 159
            anchors.fill: parent
            source: "qrc:/images/store.png"
        }
        //back botton
        Buystation{
            id : back
            width: 70
            height: 70
            x : 30
            y: parent.height - 90
            z : 1
            source: "qrc:/images/icons8-left-arrow-50.png"
            onClicked :{
                stackview.pop("qrc:/Buyzone.qml")
                doctor.get_energy()
                doctor.get_coin()
                doctor.get_xp()
                doctor.get_credit()

            }
        }
        //sidebar
        Rectangle{
            id : sidebar
            width: 160
            height: root.height
            color: "gray"
            Column{
                anchors.fill: sidebar
                id : col
                spacing: 5
                Myrectangel{
                    width: 150
                    height: 35
                    id : coin
                    reccolor: "yellow"
                    title.text: "Coin"
                }
                Myrectangel{
                    width: 150
                    height: 35
                    id : pill_count
                    reccolor: "#1F75FE"
                    title.text: "Pill"

                }
                Myrectangel{
                    width: 150
                    height: 35
                    id : ampoule_count
                    reccolor: "#66FF00"
                    title.text: "Ampoule"
                }
            }
        }
        //buy pill Button
        Buystation{
            id : buypill
            colornormal: "teal"
            colorborder: "white"
            width: 100
            height: 100
            x : 25
            y : root.height - 350
            source: "qrc:/images/pills-bottle.png"
            onClicked: {
                pilldevice.buy()
                doctor.get_coin()
            }
        }
        //buy ampoule button
        Buystation{
            id : buyampoule
            colornormal: "teal"
            colorborder: "white"
            width: 100
            height: 100
            x : 25
            y : root.height - 225
            source: "qrc:/images/syringe (1).png"
            onClicked: {
                ampouledevice.buy()
                doctor.get_coin()
            }
        }
        //label for show eror message
        Row{
            id : textrow
            width: 388
            height: 94
            anchors.left: parent.left
            anchors.leftMargin: 190
            anchors.top: parent.top
            anchors.topMargin: 30
            Label{
                id : messagelb
                font.pointSize: 16
                color: "red"
                font.bold: true
                text: ""

            }
        }

        SequentialAnimation{
            loops: Animation.Infinite
            running: true
            OpacityAnimator{
                target: messagelb
                from: 0
                to : 1
                duration: 1200
            }
        }
    }
}

