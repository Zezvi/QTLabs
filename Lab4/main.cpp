#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <marklist.h>
#include <QQmlContext>

int main(int argc, char* argv[]) {
auto app = QGuiApplication(argc, argv);
QLocale::setDefault(QLocale::c());
qmlRegisterType<MarkList>("MarkList", 1, 0, "MarkList");
QQmlApplicationEngine engine;
engine.load("qrc:/main.qml");
return QGuiApplication::exec();
}


