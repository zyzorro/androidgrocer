SOURCES = src/main.cpp \
    src/panda.cpp \
    src/frame.cpp \
    src/border.cpp \
    src/dockbar.cpp \
    src/launcher.cpp \
    src/dockicon.cpp \
    src/desk.cpp \
    src/header.cpp \
    src/systray.cpp \
    src/manager.cpp \
    src/filedialog.cpp \
    src/colordialog.cpp \
    src/colorsel.cpp \
    src/msgbox.cpp \
    src/runner.cpp \
    src/dateclock.cpp \
    src/sysicon.cpp \
    src/deskapp.cpp \
    src/utils.cpp \
    src/deskdev.cpp \
    src/deskfile.cpp \
    src/deskfolder.cpp \
    src/dockapp.cpp \
    src/trash.cpp \
    src/trashdialog.cpp \
    src/deskicon.cpp \
    src/dockmenu.cpp \
    src/settings.cpp \
    src/starter.cpp \
    src/starterdialog.cpp
HEADERS = src/defs.h \
    src/panda.h \
    src/frame.h \
    src/border.h \
    src/dockbar.h \
    src/launcher.h \
    src/dockicon.h \
    src/desk.h \
    src/header.h \
    src/systray.h \
    src/manager.h \
    src/filedialog.h \
    src/colordialog.h \
    src/colorsel.h \
    src/msgbox.h \
    src/runner.h \
    src/dateclock.h \
    src/sysicon.h \
    src/deskapp.h \
    src/utils.h \
    src/deskdev.h \
    src/deskfile.h \
    src/deskfolder.h \
    src/dockapp.h \
    src/trash.h \
    src/trashdialog.h \
    src/deskicon.h \
    src/dockmenu.h \
    src/settings.h \
    src/starter.h \
    src/starterdialog.h
OBJECTS_DIR += build
MOC_DIR += build
QMAKE_INCDIR += /usr/include
QMAKE_CLEAN += panda
TEMPLATE = app
CONFIG += warn_on \
    release
QT += dbus
TRANSLATIONS = language/it_IT.ts \
    language/cs_CZ.ts \
    language/ru_RU.ts \
    language/pl_PL.ts \
    language/de_DE.ts \
    language/es_ES.ts
DEFINES = QT_FATAL_WARNINGS
LIBS += -L/usr/local/fontconfig/lib

//DEFINES = QT_NO_DEBUG_OUTPUT
