import QtQuick 2.15
Rectangle {
id: root
border.width: 1
border.color: "#000"
required property var selector
property bool selected: false
color: selected ? "#aaf" : "#fff"
function get() {
switch (column) {
case 0:
return model.name;
case 1:
return model.country;
case 2:
return model.year;
case 3:
return model.copies;
}
}
function set(v) {
switch (column) {
case 0:
model.name = v;
break;
case 1:
model.country = v;
break;
case 2:
model.year = v;
break;
case 3:
model.copies = v;
break;
}
}
implicitWidth: 100
implicitHeight: 25
property bool editing: false
Component {
id: component_display
Text
{
anchors.fill: parent
padding: 10
verticalAlignment: Text.AlignVCenter
clip: true
}
}
Component {
id: component_edit
TextInput {
anchors.fill: parent
padding: 10
verticalAlignment: Text.AlignVCenter
clip: true
}
}
Component {
id: component_edit1
TextInput {
anchors.fill: parent
padding: 10
verticalAlignment: Text.AlignVCenter
clip: true
validator: DoubleValidator {}
}
}
Component {
id: component_edit2
TextInput {
anchors.fill: parent
padding: 10
verticalAlignment: Text.AlignVCenter
clip: true
validator: DoubleValidator { bottom: 0 }
}
}
Loader {
id: loader
anchors.fill: parent
sourceComponent: editing ? (column == 3 ? component_edit2 : (column == 2 ? component_edit1 : component_edit)) : component_display
onSourceComponentChanged: {
loader.item.text = root.get();
if (sourceComponent !== component_display) {
loader.item.editingFinished.connect(onEditingFinished); loader.item.forceActiveFocus();
}
}
function onEditingFinished() {
root.set(loader.item.text);
editing = false;
}
MouseArea {
anchors.fill: parent
onDoubleClicked: mouse => {
if (mouse.button & Qt.LeftButton) editing = true; }
onPressed: mouse => {
if (mouse.button & Qt.LeftButton) {
selector.startSelect();
onPositionChanged(mouse);
}
}
onPositionChanged: mouse => {
selector.trySelect(root);
}
}
}
}
