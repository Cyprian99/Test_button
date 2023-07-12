#include <QObject>
#include <QFrame>
#include <QLayout>
#include <QRect>
#include <QPushButton>
#include <window.h>



class customButton: public QPushButton
{
    Q_OBJECT
    public:
        customButton( const QString& text, const QSize& size, MainWindow* mainWindow = nullptr );
};