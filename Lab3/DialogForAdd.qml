import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0 // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Добавление информации о марке")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    GridLayout {
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: buttonCancel.top; margins: 10 }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Название марки:")
        }
        TextField {
            id: textName
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Страна:")
        }
        TextField {
            id: textCountry
            Layout.fillWidth: true
            placeholderText: qsTr("Введите страну")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Год выпуска:")
        }
        TextField {
            id: textYear
            Layout.fillWidth: true
            placeholderText: qsTr("Введите год выпуска")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Тираж:")
        }
        TextField {
            id: textCopies
            Layout.fillWidth: true
            placeholderText: qsTr("Введите тираж")
        }
    }

    Button {
        visible: {textName.length>0 && textCountry.length>0}
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Добавить в список")
        width: 100
        onClicked: {
            root.hide()
            add(textName.text, textCountry.text, textYear.text, textCopies.text)
        }
    }
    Button {
        id: buttonCancel
        anchors { right: parent.right; bottom: parent.bottom; rightMargin: 10; bottomMargin: 10 }
        text: qsTr("Отменить")
        width: 100
        onClicked: {
             root.hide()
        }
    }

    // изменение статуса видимости окна диалога
    onVisibleChanged: {
      if (visible) {
          textName.text = ""
          textCountry.text = ""
          textYear.text = ""
          textCopies.text = ""
      }
    }
 }
