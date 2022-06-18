QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attackwidget.cpp \
    big_class.cpp \
    endgamewidget.cpp \
    gamewindow.cpp \
    magic.cpp \
    main.cpp \
    mainwidget.cpp \
    mousepos.cpp \
    movewidget.cpp \
    tpwidget.cpp \
    weapon.cpp

HEADERS += \
    attackwidget.h \
    big_class.h \
    endgamewidget.h \
    gamewindow.h \
    mainwidget.h \
    mousepos.h \
    movewidget.h \
    tpwidget.h

FORMS += \
    attackwidget.ui \
    endgamewidget.ui \
    gamewindow.ui \
    mainwidget.ui \
    movewidget.ui \
    tpwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
