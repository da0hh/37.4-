import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: "Simple Video Player (Qt 5.12)"

    Column {
        anchors.fill: parent

        Rectangle {
            id: videoZone
            width: parent.width
            height: parent.height - controlsArea.height
            color: "black"

            Text {
                anchors.centerIn: parent
                text: "ВИДЕОЭКРАН"
                color: "#555555"
                font.pixelSize: 30
            }
        }

        Rectangle {
            id: controlsArea
            width: parent.width
            height: 120
            color: "#eeeeee"

            Column {
                anchors.centerIn: parent
                spacing: 20
                width: parent.width * 0.9

                Row {
                    anchors.horizontalCenter: parent
                    spacing: 15

                    Button {
                        text: "⏪️"
                        width: 60
                    }

                    Button {
                        text: "▶️"
                        width: 60
                    }

                    Button {
                        text: "⏸️"
                        width: 60
                    }

                    Button {
                        text: "⏹"
                        width: 60
                    }

                    Button {
                        text: "⏩️"
                        width: 60
                    }
                }

                ProgressBar {
                    id: playbackSlider
                    width: parent.width
                    value: 0.5

                    Text {
                        anchors.top: parent.bottom
                        anchors.right: parent.right
                        text: "01:30 / 03:00"
                        font.pixelSize: 10
                        color: "gray"
                    }
                }
            }
        }
    }
}
