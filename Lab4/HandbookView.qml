import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import MarkList 1.0
Rectangle {
border.width: 1
border.color: "#000"
function open_add_dialog() { add_dialog.show() }
function remove_selected_rows() {
let rows = [];
let js = [];
for (let [j, i] of selector1.selection.entries()) { let row = i.row;
if (!rows.includes(row)) {
rows.unshift(row);
js.push(j);
}
}
for (let j of js)
selector1.selection.splice(j, 1);
for (let row of rows)
tableView.model.remove(row);
}
function list() {
return tableView.model;
}
ScrollView {
anchors.fill: parent
anchors.margins: 1
onWidthChanged: { tableView.forceLayout() }
TableView {
id: tableView
model: MarkList {}
delegate: HandbookDelegate { selector:
selector1 }
clip: true
anchors.fill: parent
topMargin: columnsHeader.implicitHeight
reuseItems: false
interactive: false
columnWidthProvider: function(column) {
return tableView.model ? tableView.width /
tableView.model.columnCount() : 0
}
Row {
id: columnsHeader
y: tableView.contentY
z: 2
Repeater {
model: tableView.columns > 0 ? tableView.columns
: 1
Rectangle {
width:
tableView.columnWidthProvider(modelData)
height: 30
clip: true
border.width: 1
border.color: "#000"
Text {
anchors.fill: parent
padding: 10
horizontalAlignment: Text.AlignHCenter
verticalAlignment: Text.AlignVCenter
text:
tableView.model.headerData(modelData, Qt.Horizontal)
elide: Text.ElideRight
clip: true
}
}
}
}
Window {
id: add_dialog
modality: Qt.ApplicationModal
width: 400
height: 350
Dialog {
id: invalid_message
modal: true
standardButtons: Dialog.Ok
Text {
text: "Одно из текстовых полей не заполнено"
}
}
Column {
anchors.fill: parent
anchors.margins: 10
GridLayout {
rowSpacing: 10
columnSpacing: 10
columns: 2
anchors.left: parent.left
anchors.right: parent.right
Text { text: tableView.model.headerData(0,
Qt.Horizontal) }
TextField {
id: field_name
Layout.fillWidth: true
}
Text { text: tableView.model.headerData(1,
Qt.Horizontal) }
TextField {
id: field_country
Layout.fillWidth: true
}
Text { text: tableView.model.headerData(2,
Qt.Horizontal) }
TextField {
id: field_year
Layout.fillWidth: true
validator: DoubleValidator {}
}
Text { text: tableView.model.headerData(3,
Qt.Horizontal) }
TextField {
id: field_copies
Layout.fillWidth: true
validator: DoubleValidator { bottom: 0 }
}
}
Rectangle { width: 10; height: 10 }
}
Button {
text: "OK"
anchors.left: parent.left
anchors.right: parent.right
anchors.bottom: parent.bottom
anchors.margins: 10
onClicked: {
let name = field_name.text.trim();
let country =
field_country.text.trim();
let year =
parseFloat(field_year.text);
let copies =
parseFloat(field_copies.text);
if (name === ""
|| country === "" ) {
invalid_message.open();
return;
}
tableView.model.add(
name,
country,
year,
copies);
tableView.forceLayout();
add_dialog.close();
}
}
}
MouseArea {
id: selector1
z: 100
anchors.fill: parent
propagateComposedEvents: true
property var selection: []
property bool selecting: false
onPressed: mouse => {
mouse.accepted = false;
}
onPositionChanged: mouse => {
mouse.accepted = false;
}
onReleased: mouse => {
if (selecting)
selecting = false;
else mouse.accepted = false;
}
function startSelect() {
for (let i of selection)
i.selected = false;
selection = [];
selecting = true;
}
function trySelect(i) {
if (selecting) {
if (selection.includes(i)) return;
selection.push(i);
i.selected = true;
}
}
}
}
}
}
