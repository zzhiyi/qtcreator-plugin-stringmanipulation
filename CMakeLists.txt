cmake_minimum_required(VERSION 3.10)

# Remove when sharing with others.
list(APPEND CMAKE_PREFIX_PATH "/home/eric/build/build-qt-creator-Replacement_for_Desktop_Qt_GCC_64bit-Release")

project(StringManipulation)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(QtCreator REQUIRED COMPONENTS Core)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
set(QtX Qt${QT_VERSION_MAJOR})

add_qtc_plugin(StringManipulation
  PLUGIN_DEPENDS
    QtCreator::Core
    QtCreator::TextEditor
  DEPENDS
    ${QtX}::Widgets
    QtCreator::ExtensionSystem
    QtCreator::Utils
  SOURCES
    README.md
    stringmanipulation.cpp
    stringmanipulation.h
    stringmanipulation_global.h
    stringmanipulationconstants.h
    stringmanipulationcore.h
    stringmanipulationcore.cpp
)
