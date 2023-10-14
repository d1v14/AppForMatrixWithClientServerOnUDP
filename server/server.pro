QT += core network
QT -= gui
CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../ConnectionClass/common.cpp \
        ../ConnectionClass/communicator.cpp \
        application.cpp \
        complex.cpp \
        main.cpp \
        rational.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../ConnectionClass/common.h \
    ../ConnectionClass/communicator.h \
    application.h \
    matrix.h \
    complex.h \
    rational.h
