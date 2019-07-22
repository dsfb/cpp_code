/*
  see as I can slide a long text using qml property animation
  I implemented 3 ways for move the text
  I will able to combine some of them together if I want

  qt 5.7
  Aleksander Czastuchin
  rok 2019, lipiec
*/
import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    id: window

    property int seconds: 7
    property double diff: {
        var difference = window.width - longText1.width;
        if (difference < 0)
            return Math.abs(difference);
        return 0;
    }

    visible: true
    width: 640
    height: 480
    title: qsTr("moved text")


    Text {
        id: longText1
        text: qsTr("this long text will be moved correctly even if change window's width")
        font.pixelSize: 30
        Rectangle { anchors.fill: parent; color: "red"; opacity: 0.4; }
    }
    Text {
        id: longText2
        anchors.top: longText1.bottom
        text: qsTr("this long text will be moved correctly even if change window's width")
        font.pixelSize: 30
        Rectangle { anchors.fill: parent; color: "yellow"; opacity: 0.4; }
    }
    Text {
        id: longText3
        anchors.top: longText2.bottom
        text: qsTr("this long text will be moved correctly even if change window's width")
        font.pixelSize: 30
        Rectangle { anchors.fill: parent; color: "blue"; opacity: 0.4; }
    }

    PropertyAnimation
    {
        id: animation1
        target: longText1
        property: "x"
        from: 0
        // | text | text  -> text | window |
        to: (diff + longText1.width) * -1 // one way (more movement)

        duration: seconds * 1000
        loops: Animation.Infinite
    }

    PropertyAnimation
    {
        id: animation2
        target: longText2
        property: "x"
        from: 0
        // | text | text  -> text | text |
        to: (diff) * -1


        duration: seconds * 1000
        loops: Animation.Infinite
    }

    PropertyAnimation
    {
        id: animation3
        target: longText3
        property: "x"
        // | window | text  -> | text | -> text | window |
        from: window.width
        to: diff * -1
        duration: seconds * 1000
        loops: Animation.Infinite
    }

    MouseArea {
        anchors.fill: parent
        onClicked: animation1.running = false }

    Component.onCompleted:
    {
        animation1.running = true;
        animation2.running = true;
        animation3.running = true;
    }
}
