/*****************************************************************************/
/* Project: Guess The Word                                                   */
/* Module: Main                                                              */
/* Description: Program entry point and launcher of the QML UI               */
/* Author: Ali Abu-El-Magd                                                   */
/*****************************************************************************/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "gamemanager.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    // get access to the root object

    QObject *rootObject = engine.rootObjects().first();

    // Start our Game Engine
    GameManager *gameEngine = new GameManager(rootObject);

    return app.exec();
}
