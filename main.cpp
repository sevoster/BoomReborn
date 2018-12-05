#include <QtQml>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "datamodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    DataModel model;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataModel", &model);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
