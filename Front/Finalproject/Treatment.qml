import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.2

Item {
    id: root
    visible : true
    //Connections for update data and show messages
    Connections{
        target: doctor
        onNoticecoin:{
            coin.title.text = "Coin: " + data
        }
        onGameover:{
            gameover.source = "qrc:/images/DD-Game-Over-Illustration-34432-Preview.jpg"
            area.anchors.fill = gameover
        }
    }
    Connections{
        target: pilldevice
        onNoticegetpillcount:{
            pill_count.title.text = "Pill: " + data
        }

    }
    Connections{
        target: ampouledevice
        onNoticgetampoulecount:{
            ampoule_count.title.text = "Ampoule: " + data
        }

    }
    Connections{
        target: person
        onNoticehealth:{
            health_count.title.text = "Healthy: " + data
        }
        onNoticesick:{
            sick_count.title.text = "Sick: " + data
        }
        onNoticetreatmessage:{
            messagelb.text = note
        }
    }

    Rectangle{

        id : treatrec
        anchors.fill: parent
        visible: true
        //bed image
        Image {
            id: treat
            source: "qrc:/images/vecteezy_old-man-patient-sleeping-on-the-bed-with-modern-isometric-style_.jpg"
            anchors.fill: parent
        }
        // back Button
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
        Rectangle{
            id : sidebar
            width: 155
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
                Myrectangel{
                    width: 150
                    height: 35
                    id : health_count
                    reccolor: "green"
                    title.text: "Healthy"
                }
                Myrectangel{
                    width: 150
                    height: 35
                    id : sick_count
                    reccolor: "red"
                    title.text: "Sick"
                }
            }
        }
        Row{
            id : row
            width: 200
            height: 400
            anchors.verticalCenterOffset: 202
            anchors.horizontalCenterOffset: -14
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            spacing: 25
            //special bouttons
            Buystation{
                id : easy
                width: 120
                height: 120
                colornormal: "yellow"
                source: "qrc:/images/grade1.png"
                onClicked: {
                    person.treatment(1)
                    pilldevice.use()
                    pilldevice.get_count()
                    doctor.get_coin()
                    doctor.get_energy()
                }
            }
            Buystation{
                id : normal
                width: 120
                height: 120
                colornormal: "orange"
                source: "qrc:/images/grade2.png"
                onClicked: {
                    person.treatment(2)
                    ampouledevice.use()
                    ampouledevice.get_count()
                    doctor.get_coin()
                    doctor.get_energy()
                }
            }
            Buystation{
                id : hard
                width: 120
                height: 120
                colornormal: "red"
                source: "qrc:/images/grade3.png"
                onClicked: {
                    person.treatment(3)
                    ampouledevice.use()
                    pilldevice.use()
                    pilldevice.get_count()
                    ampouledevice.get_count()
                    doctor.get_coin()
                    doctor.get_energy()
                }
            }

        }
        //label for show message
        Row{
            id : textrow
            width: 458
            height: 74
            anchors.verticalCenterOffset: 165
            anchors.horizontalCenterOffset: 70
            anchors.centerIn: parent
            Label{
                id : messagelb
                font.pointSize: 14
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
        //gameover image
        Image {
            id: gameover
            anchors.fill: parent
            source: ""
            MouseArea{
                id:area
                onClicked: {
                    gameover.source = ""

                }
            }
        }

    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:6;anchors_x:49}
}
##^##*/
