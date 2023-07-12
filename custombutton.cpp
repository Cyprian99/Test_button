#include "custombutton.h"
#include <QDebug>
//commented so can test hide options
customButton::customButton( const QString &text, const QSize &size, MainWindow* mainWindow)
: QPushButton(mainWindow)
{
    setText(text);
    setFixedSize(size);
    connect(this, &QPushButton::clicked, mainWindow, &MainWindow::handleButtonClicked);
}
