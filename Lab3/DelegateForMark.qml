import QtQuick 6.0
import QtQuick.Controls 6.0  // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0

Rectangle {
    id: markItem
    readonly property color evenBackgroundColor: "#FF00FF"  // цвет для четных пунктов списка
    readonly property color oddBackgroundColor: "#800080"   // цвет для нечетных пунктов списка
    readonly property color selectedBackgroundColor: "#C0C0C0"  // цвет выделенного элемента списка

    property bool isCurrent: markItem.ListView.view.currentIndex === index   // назначено свойство isCurrent истинно для текущего (выделенного) элемента списка
    property bool selected: markItemMouseArea.containsMouse || isCurrent // назначено свойство "быть выделенным",
    //которому присвоено значение "при наведении мыши,
    //или совпадении текущего индекса модели"

    property variant markData: model // свойство для доступа к данным конкретной марки

    width: parent ? parent.width : markList.width
    height: 160

    // состояние текущего элемента (Rectangle)
    states: [
        State {
            when: selected
            // как реагировать, если состояние стало selected
            PropertyChanges { target: markItem;  // для какого элемента должно назначаться свойство при этом состоянии (selected)
                color: isCurrent ? palette.highlight : selectedBackgroundColor  /* какое свойство целевого объекта (Rectangle)
                                                                                                  и какое значение присвоить*/
            }
        },
        State {
            when: !selected
            PropertyChanges { target: markItem;  color: isCurrent ? palette.highlight : index % 2 == 0 ? evenBackgroundColor : oddBackgroundColor }
        }
    ]

    MouseArea {
        id: markItemMouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            markItem.ListView.view.currentIndex = index
            markItem.forceActiveFocus()
        }
    }
    Item {
        id: itemOfMarks
        width: parent.width
        height: 160
        Column{
            id: t2
            anchors.left: parent.left
            anchors.leftMargin: 10
            width: 240
            anchors.verticalCenter: parent.verticalCenter
            Text {
                id: t1
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Название марки:"
                color: "White"
                font.pointSize: 12
            }
            Text {
                id: textName
                anchors.horizontalCenter: parent.horizontalCenter
                text: nameOfMark
                color: "White"
                font.pointSize: 18
                font.bold: true
            }
        }
        Column{
            anchors.left: t2.right
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            Text {
                text: "Страна:"
                color: "White"
                font.pointSize: 10
            }
            Text {
                id: textCountry
                text: countryOfMark
                color: "White"
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: "Year:"
                color: "White"
                font.pointSize: 10
            }
            Text {
                id: textYear
                color: "White"
                text: yearOfMark
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: "Тираж:"
                color: "White"
                font.pointSize: 10
            }
            Text {
                id: textCopies
                text: copiesOfMark
                color: "White"
                font.pointSize: 12
                font.bold: true
            }

        }

    }
}
