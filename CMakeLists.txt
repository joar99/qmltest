cmake_minimum_required(VERSION 3.16)

project(Qtie VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appQtie
    main.cpp
)

qt_add_qml_module(appQtie
    URI Qtie
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES ControlView.qml
        SOURCES controlviewmodel.h controlviewmodel.cpp
        SOURCES appcoordinator.h appcoordinator.cpp
        QML_FILES SecondNavView.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQtie PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQtie
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQtie
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appQtie
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
