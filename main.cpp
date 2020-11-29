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

    // Step 1: get access to the root object
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->findChild<QObject*>("label");

    // Step 2: set or get the desired property value for any qml object
    qmlObject->setProperty("text", "Hello from C++!");
    //qDebug() << qmlObject->property("visible");

    // Start our Game Engine
    GameManager *gameEngine = new GameManager();
    gameEngine->newGame();
    // Step 3: Connect QML signals to C++ slots
    QQuickWindow *window = qobject_cast<QQuickWindow *>(rootObject);
    QObject::connect(window, SIGNAL(newGameButtonClick()), gameEngine, SLOT(newGame()));
    return app.exec();
}
