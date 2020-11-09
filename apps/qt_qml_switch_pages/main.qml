/*
it is my very fast implementation of way to show pages by turns.
i created array with elements and show them by using stack view.
i used timer to switch pages too.

Aleksander Czastuchin
qt 5.7, 2019
*/

import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.0 // for container

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property var list: []

    StackView {
        id: stack
        anchors.fill: parent

    }

    Component {
        id: page1
    Text {

        text: qsTr("page one")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 30
    }
    }

    Component {
        id: page2
    Text {

        text: qsTr("page two")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 30
    }
    }

    Component.onCompleted: {
        list.push(page1)
        list.push(page2)

    }

    Timer {
        property int index: 0
        running: true
        repeat: true
        interval: 1000
        onTriggered: {
            //console.log(list.length)

            if (list.length == 0)
                return;

            // 0 < 2 -> 1
            // 1 < 2 -> 2
	    // 2 < 2 -> 0 
            if (index < list.length) {
                stack.clear();
                console.log(index);
                stack.push(list[index]);
                index = index + 1;
                return;
            }
            else {
                index = 0;
            }

        }
    }
}
