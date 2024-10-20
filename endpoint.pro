QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/collectiondatamanager.cpp \
    src/collectionmodel.cpp \
    src/endpointmainwidget.cpp \
    src/main.cpp \
    src/endpointmainwindow.cpp \
    src/navigationwidget.cpp \
    src/viewportwidget.cpp

HEADERS += \
    src/collectiondatamanager.h \
    src/collectionmodel.h \
    src/endpointmainwidget.h \
    src/endpointmainwindow.h \
    src/navigationwidget.h \
    src/viewportwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
