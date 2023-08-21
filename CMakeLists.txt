cmake_minimum_required(VERSION 3.12)

project(ProjectName)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Gui Network Widgets REQUIRED)


add_executable(${PROJECT_NAME}
    addtype.cpp
    httphandler.cpp
    initconfig.cpp
    main.cpp
    mainwindow.cpp
    tablewidget.cpp
    videoimport.cpp

    addtype.ui
    initconfig.ui
    mainwindow.ui
    videoimport.ui
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Network
        Qt5::Widgets
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# Deployment rules
if(QNX)
    set(target_path "/tmp/${TARGET}/bin")
else()
    if(UNIX AND NOT ANDROID)
        set(target_path "/opt/${TARGET}/bin")
    endif()
endif()

if(NOT ${target_path} STREQUAL "")
    install(TARGETS ${PROJECT_NAME} DESTINATION ${target_path})
endif()
