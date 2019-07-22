/*
  look at my progress bar in qt 5 point 7 by using qml language!
  it is my modern progress bar that I designed to
  show you my skills.

  my progress bar is a curcle which change color from red to green
  and have a small rotated spot.

  i have write code for 30 minuts. code has magic numbers and I know
  that in real project those numbers is bad to understand logic. I wanted
  show you what I can and nothing more

  Aleksander Czastuchin
  2019, lato, lipiec
*/
import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    id: main

    visible: true
    width: 300
    height: 300
    title: qsTr("my progress bar")
    color: "black"

    //property int progressSize:
    property int spotSize: 30
    property double angle: 0
    property int circleRadius: (width - spotSize * 2) / 2
    property int centerx: width / 2
    property int centery: height / 2
    property int procent: 0

    Timer {
        id: timer

        running: true
        repeat: true
        interval: 50 / 4
        onTriggered: {
            if (angle < 360)
                angle = angle + 0.1;
            else {
                angle = 0;
                anima.restart();
            }
            console.log(angle);
            circle.x = circleRadius * Math.cos(angle) + centerx - 15;
            circle.y = circleRadius * Math.sin(angle) + centery - 15;
            circle.visible = true;
            procent = (100 / 360) * angle;
        }
    }


    Rectangle {
        id: circleStatic

        x: (parent.width / 2) - circleRadius
        y: (parent.height / 2) - circleRadius
        width: circleRadius * 2
        height: circleRadius * 2
        radius: circleRadius
        color: "red"
        visible: true
        //border.width: 3
        //border.color: "grey"


        Text {
            id: name
            text: procent
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 150
        }
    }

    Rectangle {
        id: circle

        width: 30
        height: 30
        radius: 30 / 2
        color: "black"
        visible: false
    }
    Rectangle {
        id: center
        width: 10
        height: 10
        radius: 10 / 2
        x: parent.width / 2
        y: parent.height / 2
        color: "black"
        visible: false
    }


    ColorAnimation {
        id: anima
        target: circleStatic
        property: "color"
        from: "red"
        to: "green"
        duration: (50 / 4) * (360 / 0.1)
        //easing.type: Easing.InOutElastic
        //running: true
    }

    Component.onCompleted:
      {
        timer.start();
        anima.start();
    }
}
