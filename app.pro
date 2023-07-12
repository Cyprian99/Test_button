Target = App
SOURCES += main.cpp \ 
            window.cpp \
            custombutton.cpp \
            tablewidget.cpp
HEADERS += window.h \
            custombutton.h \
            tablewidget.h
LIBS += -lQt5Gui 
QT += widgets 
CONFIG+=debug
