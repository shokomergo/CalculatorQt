import QtQuick
import Calculator

Window {
    width: mainScreen.width
    height: mainScreen.height

    visible: true
    title: "Calculator"

    Screen01 {
        id: mainScreen

        anchors.centerIn: parent
    }

}

