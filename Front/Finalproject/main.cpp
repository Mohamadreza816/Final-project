#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "pill.h"
#include "doctor.h"
#include "ampoule.h"
#include "patient.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    doctor d("doc");
    engine.rootContext()->setContextProperty("doctor", &d);
    pill P{"pill"};
    engine.rootContext()->setContextProperty("pilldevice", &P);
    ampoule a{"ampoule"};
    engine.rootContext()->setContextProperty("ampouledevice", &a);
    patient patient;
    engine.rootContext()->setContextProperty("person", &patient);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
