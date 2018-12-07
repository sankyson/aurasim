import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListModel{
        id: digListModel
    }

    ListModel{
        id: anaListModel
    }

    Column{
        anchors.centerIn: parent
        spacing: 60

        Row{
            spacing: 20
            Text{
                text: "analog pins: "
            }

            Repeater{
                id: anaRepeat
                model: anaListModel
                Rectangle{
                    width: 20
                    height: 20
                    radius: 10
                    color: Qt.rgba(val / 255, 0.2, 0.2, 1)
                }
            }
        }

        Row{
            spacing: 20
            Text{
                text: "digital pins:"
            }

            Repeater{
                id: digRepeat
                model: digListModel
                Rectangle{
                    width: 20
                    height: 20
                    radius: 10
                    color: Qt.rgba(val / 255, 0.3, 0.3, 1)

                }
            }
        }

    }
    Connections{
        target: arduino
        onDigValsChanged: {
            for (var i = 0; i < arduino.digVals.length; i++) {
                digListModel.setProperty(i, 'val', arduino.digVals[i])
            }
        }
        onAnaValsChanged:{
            for (var i = 0; i < arduino.anaVals.length; i++) {
                anaListModel.setProperty(i, 'val', arduino.anaVals[i])
            }
//            console.log(arduino.anaVals)
        }
    }

    Component.onCompleted: {
        for(var i = 0; i < 20; i++) {
            anaListModel.append({'val':0})
            digListModel.append({'val':0})
        }
        arduino.start();
    }


}
