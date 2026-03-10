import QtQuick 6.7
import QtQuick.Controls 6.7
import QtWebView 1.1 // <-- Важное изменение для Android

ApplicationWindow {
    id: window
    width: 1280
    height: 720
    visible: true
    title: "Nexus Browser"

    // Твой интерфейс с пазлами (я оставляю логику NexusEngine)
    // В месте, где отображается сайт, теперь используем универсальный WebView:
    
    WebView {
        id: mainBrowser
        anchors.fill: parent
        url: "https://www.google.com"
        
        onLoadingChanged: (loadRequest) => {
            if (loadRequest.status === WebView.LoadStartedStatus) {
                console.log("Загрузка пошла...")
            }
        }
    }
}
