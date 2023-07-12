Target = App
SOURCES += main.cpp \ 
            window.cpp \
            custombutton.cpp
HEADERS += window.h \
            custombutton.h
LIBS += -lQt5Gui 
QT += widgets 
CONFIG+=debug
