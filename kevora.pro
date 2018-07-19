# -------------------------------------------------
# Project created by QtCreator 2009-10-17T16:17:36
# -------------------------------------------------
QT += widgets \
    sql \
    xml \
    concurrent \
    printsupport
TARGET = kevora
TEMPLATE = app
SOURCES += main.cpp \
    kvmainwindow.cpp \
    kvaboutwindow.cpp \
    kvcreditswidget.cpp \
    kvsettings.cpp \
    kvwaitanimation.cpp \
    kvtreewidget.cpp \
    kvsqlsession.cpp \
    kvsqlsessionoracle.cpp \
    kvsqlsessionpostgresql.cpp \
    kvsqlsessionsqlite.cpp \
    kvsqlsessionmysql.cpp \
    kvsqlsessionfirebird.cpp \
    kvthread.cpp \
    kvdbutil.cpp \
    kvsettingsdialog.cpp \
    kvxml.cpp \
    kvdbdefinitiondialog.cpp \
    kvuserpassdialog.cpp \
    kvsqldialog.cpp \
    kvsqlwindow.cpp \
    kvtnshighlighter.cpp \
    kvcodeeditor.cpp \
    kvsqlhighlighter.cpp \
    kvoraclehighlighter.cpp \
    kvsqldata.cpp \
    kvexportobjects.cpp \
    kvsolver.cpp \
    kvmdiarea.cpp \
    kvsqlsessioncubrid.cpp
HEADERS += kvmainwindow.h \
    kvaboutwindow.h \
    kvcreditswidget.h \
    kvsettings.h \
    kvwaitanimation.h \
    kvtreewidget.h \
    kvsqlsession.h \
    kvsqlsessionoracle.h \
    kvsqlsessionpostgresql.h \
    kvsqlsessionsqlite.h \
    kvsqlsessionmysql.h \
    kvsqlsessionfirebird.h \
    kvthread.h \
    kvdbutil.h \
    kvsettingsdialog.h \
    kvxml.h \
    kvdbdefinitiondialog.h \
    kvuserpassdialog.h \
    kvsqldialog.h \
    kvsqlwindow.h \
    kvtnshighlighter.h \
    kvcodeeditor.h \
    kvsqlhighlighter.h \
    kvoraclehighlighter.h \
    kvsqldata.h \
    kvexportobjects.h \
    kvsolver.h \
    kvsqlobject.h \
    kvmdiarea.h \
    kvsqlsessioncubrid.h
FORMS += kvmainwindow.ui \
    kvaboutwindow.ui \
    kvsettingsdialog.ui \
    kvdbdefinitiondialog.ui \
    kvuserpassdialog.ui \
    kvsqldialog.ui \
    kvsqlwindow.ui \
    kvsqldata.ui \
    kvexportobjects.ui
RESOURCES += ui/kevora.qrc
TRANSLATIONS += translations/kevora_cn.ts \
    translations/kevora_de.ts \
    translations/kevora_es.ts \
    translations/kevora_fr.ts \
    translations/kevora_gr.ts \
    translations/kevora_it.ts \
    translations/kevora_jp.ts \
    translations/kevora_pl.ts \
    translations/kevora_pt.ts \
    translations/kevora_pt_BR.ts \
    translations/kevora_ru.ts
RC_FILE = ui/kevora.rc
OTHER_FILES += ui/kevora.rc


