QT       += core gui sql
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admin_adding.cpp \
    file.cpp \
    genre.cpp \
    help.cpp \
    language.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    movie.cpp \
    movielist.cpp \
    moviemenu.cpp \
    pdeletep.cpp \
    star.cpp \
    userinfo.cpp \
    users.cpp

HEADERS += \
    admin.h \
    admin_adding.h \
    file.h \
    genre.h \
    help.h \
    language.h \
    login.h \
    mainwindow.h \
    movie.h \
    movielist.h \
    moviemenu.h \
    pdeletep.h \
    star.h \
    userinfo.h \
    users.h

FORMS += \
    admin.ui \
    admin_adding.ui \
    file.ui \
    genre.ui \
    help.ui \
    language.ui \
    login.ui \
    mainwindow.ui \
    movie.ui \
    movielist.ui \
    moviemenu.ui \
    pdeletep.ui \
    star.ui \
    userinfo.ui \
    users.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

