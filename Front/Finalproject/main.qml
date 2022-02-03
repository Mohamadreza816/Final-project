import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Window {
    visible: true
    id : window
    width: 640
    height: 480
    title: qsTr("Doctor")

    //hospital Image
    Image {
        anchors.fill: parent
        anchors.margins: 25
        id: hospital
        anchors.rightMargin: 0
        anchors.topMargin: 1
        anchors.bottomMargin: 0
        anchors.leftMargin: 161
        source: "qrc:/images/Hospital building flat illustration - Kit8.png"
    }
    //Connections signal with slots
    Connections{
        target: doctor
        onNoticeenergy:{
            energy.title.text = "Energy: " + data   //show amount of energy
        }
        onNoticexp:{
            xp.title.text  = "XP: " + data          //show amount of XP
        }
        onNoticecoin:{
            coin.title.text = "Coin: " + data       //show amount of Coin
        }
        onNoticecredit:{
            credit.title.text = "Credit: " + data   //show amount of Credit
        }
    }

    //rectangle for sidebar
    Rectangle{
        id : sidebar
        width: 160
        height: parent.height
        color: "gray"
        Column{
            anchors.fill: sidebar
            id : col
            spacing: 5
            //special rectangele
            Myrectangel{
                width: 150
                height: 35
                id : energy
                reccolor: "red"
                title.text: "Energy"
                mouse.onClicked: doctor.get_energy()
            }
            Myrectangel{
                width: 150
                height: 35
                id : coin
                reccolor: "yellow"
                title.text: "Coin"
                mouse.onClicked: doctor.get_coin()
            }
            Myrectangel{
                width: 150
                height: 35
                id : xp
                reccolor: "blue"
                title.text: "XP"
                mouse.onClicked:doctor.get_xp()
            }
            Myrectangel{
                width: 150
                height: 35
                id : credit
                reccolor: "limegreen"
                title.text: "Credit"
                mouse.onClicked: doctor.get_credit()

            }

        }
    }
    //load stackweiw
    Loader
    {
        id: loader
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 1
        anchors.fill: parent
        source: "qrc:/stackveiw.qml"

    }


}

