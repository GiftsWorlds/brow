cmake_minimum_required(VERSION 3.22)
project(NexusBrowser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick WebView)
if(WIN32)
    find_package(Qt6 REQUIRED COMPONENTS WebEngineQuick)
endif()

qt_add_executable(NexusBrowser
    main.cpp
    NexusEngine.h
    NexusEngine.cpp
    qml.qrc
)

target_link_libraries(NexusBrowser PRIVATE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Qml 
    Qt6::Quick 
    Qt6::WebView
)

if(WIN32)
    target_link_libraries(NexusBrowser PRIVATE Qt6::WebEngineQuick)
endif()

if(ANDROID)
    set_target_properties(NexusBrowser PROPERTIES
        QT_ANDROID_TARGET_SDK_VERSION 34
        QT_ANDROID_MIN_SDK_VERSION 28
    )
endif()
