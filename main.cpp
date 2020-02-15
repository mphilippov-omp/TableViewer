#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "TableDataReader.h"
#include "TableDataModel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    TableDataReader reader;
    reader.readTableDataFromFile("test.txt");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.rootContext()->setContextProperty("tableModel", reader.getModel());
    engine.load(url);

    return app.exec();
}
