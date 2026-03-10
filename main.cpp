#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebView/QtWebView.h>
#include "NexusEngine.h"

#ifdef Q_OS_WIN
#include <QtWebEngineQuick/qtwebenginequick.h>
#endif

int main(int argc, char *argv[]) {
    // Инициализация WebView для мобилок
    QtWebView::initialize();
    
    #ifdef Q_OS_WIN
    // Для Windows используем быстрый движок
    QtWebEngineQuick::initialize();
    #endif

    QGuiApplication app(argc, argv);
    app.setApplicationName("Nexus Browser");

    // Регистрируем твой движок
    qmlRegisterSingletonType<NexusEngine>("NexusBrowser", 1, 0, "NexusEngine", &NexusEngine::create);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qml/Main.qml"_qs);
    engine.load(url);

    if (engine.rootObjects().isEmpty()) return -1;
    return app.exec();
}
