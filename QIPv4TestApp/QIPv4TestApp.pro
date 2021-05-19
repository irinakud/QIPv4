QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qappwidget.cpp

HEADERS += \
    mainwindow.h \
    qappwidget.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QIPv4Lib/release/ -lQIPv4Lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QIPv4Lib/debug/ -lQIPv4Lib
else:unix: LIBS += -L$$OUT_PWD/../QIPv4Lib/ -lQIPv4Lib

INCLUDEPATH += $$PWD/../QIPv4Lib
DEPENDPATH += $$PWD/../QIPv4Lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QIPv4Lib/release/libQIPv4Lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QIPv4Lib/debug/libQIPv4Lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QIPv4Lib/release/QIPv4Lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QIPv4Lib/debug/QIPv4Lib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../QIPv4Lib/libQIPv4Lib.a
