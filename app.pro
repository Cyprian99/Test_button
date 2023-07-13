Target = App
SOURCES += main.cpp \ 
            window.cpp \
            custombutton.cpp \
            tablewidget.cpp \
            invisiblewidget.cpp
HEADERS += window.h \
            custombutton.h \
            tablewidget.h \ 
            invisiblewidget.h
LIBS += -lQt5Gui 
QT += widgets 
CONFIG+=debug
