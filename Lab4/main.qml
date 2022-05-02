import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

Window {
    width: 400
    height: 200
    title: qsTr("Справочник филателиста")
    visible: true
    GridLayout {
    id: grid
    rowSpacing: 10
    columnSpacing: 10
    columns: 3
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.margins: 10
    Text { text: "Тираж <" }
    TextInput {
    id: count
    property int result: 0
    Layout.fillWidth: true
    validator: DoubleValidator {}
    onTextEdited: {
    let val = parseFloat(text);
    let mod = view.list();
    result = Array.from(
    { length: mod.rowCount() },
    (_, i) => mod.get(i, 3))
    .filter(s => s < val)
    .length;
    }
    }
    Text { text: ": " + count.result }
    }
    HandbookView {
    id: view
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: grid.bottom
    anchors.bottom: btn_add.top
    anchors.margins: 10
    }
    Button {
    id: btn_add
    text: "Добавить"
    anchors.left: parent.left
    anchors.right: parent.horizontalCenter
    anchors.bottom: parent.bottom
    anchors.margins: 10
    anchors.rightMargin: 2
    onClicked: { view.open_add_dialog() }
    }
    Button {
    id: btn_rem
    text: "Удалить"
    anchors.right: parent.right
    anchors.left: parent.horizontalCenter
    anchors.bottom: parent.bottom
    anchors.margins: 10
    anchors.leftMargin: 2
    onClicked: { view.remove_selected_rows() } }
    }





