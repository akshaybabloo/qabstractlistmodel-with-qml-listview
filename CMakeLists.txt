cmake_minimum_required(VERSION 3.16)

project(qabstractlistmodel-with-qml-listview VERSION 0.1 LANGUAGES CXX)

# Check if in CLion
if ($ENV{CLION_IDE})
    set(CMAKE_PREFIX_PATH "/home/akshay/Qt/6.5.3/gcc_64")
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appqabstractlistmodel-with-qml-listview
        main.cpp
        animalabstractlistmodel.h animalabstractlistmodel.cpp
)

qt_add_resources(appqabstractlistmodel-with-qml-listview "config"
        PREFIX "/"
        FILES
        "qtquickcontrols2.conf"
)

qt_add_qml_module(appqabstractlistmodel-with-qml-listview
        URI qabstractlistmodel-with-qml-listview
        VERSION 1.0
        QML_FILES Main.qml
        SOURCES
        animalmodel.h
        printservice.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appqabstractlistmodel-with-qml-listview PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.gollahalli.appqabstractlistmodel-with-qml-listview
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqabstractlistmodel-with-qml-listview
        PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appqabstractlistmodel-with-qml-listview
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
