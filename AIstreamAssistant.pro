QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addtype.cpp \
    httphandler.cpp \
    initconfig.cpp \
    main.cpp \
    mainwindow.cpp \
    tablewidget.cpp \
    videoimport.cpp

HEADERS += \
    addtype.h \
    httphandler.h \
    initconfig.h \
    mainwindow.h \
    tablewidget.h \
    videoimport.h

FORMS += \
    addtype.ui \
    initconfig.ui \
    mainwindow.ui \
    videoimport.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
