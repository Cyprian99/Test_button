Target = App
SOURCES += main.cpp \ 
            window.cpp \
            custombutton.cpp \
            tablewidget.cpp \
            expanderwidget.cpp
HEADERS += window.h \
            custombutton.h \
            tablewidget.h \ 
            expanderwidget.h
LIBS += -lQt5Gui 
QT += widgets 
CONFIG+=debug
