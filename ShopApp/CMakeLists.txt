cmake_minimum_required(VERSION 3.5)

project(ShopApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network Xml)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    customer.h
    customer.cpp
    item.h
    item.cpp
    transaction.h
    transaction.cpp
    additemdialog.h
    additemdialog.cpp
    addtransactiondialog.h
    addtransactiondialog.cpp
    broadcast.h
    broadcast.cpp
    datastore.h
    datastore.cpp
    addcustomerdialog.h
    addcustomerdialog.cpp
    Resource.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ShopApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(ShopApp SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ShopApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ShopApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Network Qt6::Xml)

set_target_properties(ShopApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ShopApp)
endif()
