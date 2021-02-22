QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alien.cpp \
    consoleWindow_Stand_22.02.21/ConsoleWindow.cpp \
    main.cpp \
    mainmenu.cpp \
    map.cpp \
    player.cpp

HEADERS += \
    alien.h \
    consoleWindow_Stand_22.02.21/ConsoleWindow.h \
    mainmenu.h \
    map.h \
    player.h

FORMS += \
    mainmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
