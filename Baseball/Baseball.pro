QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataBase.cpp \
    custompath.cpp \
    displaygraphs.cpp \
    dodgerpath.cpp \
    grapher.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    manageDB.cpp \
    marlinspath.cpp \
    modifySouvenirs.cpp \
    modifyTeams.cpp \
    orderedpath.cpp \
    souvenirshop.cpp \
    tripsummary.cpp

HEADERS += \
    DataBase.h \
    custompath.h \
    dijkstra.h \
    displaygraphs.h \
    dodgerpath.h \
    grapher.h \
    login.h \
    mainwindow.h \
    manageDB.h \
    marlinspath.h \
    modifySouvenirs.h \
    modifyTeams.h \
    orderedpath.h \
    pqueue.h \
    souvenirshop.h \
    tripsummary.h

FORMS += \
    DataBase.ui \
    custompath.ui \
    displaygraphs.ui \
    dodgerpath.ui \
    login.ui \
    mainwindow.ui \
    marlinspath.ui \
    modifySouvenirs.ui \
    modifyTeams.ui \
    orderedpath.ui \
    souvenirshop.ui \
    tripsummary.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
