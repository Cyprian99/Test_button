#include <QObject>
#include <QFrame>
#include <QLayout>
#include <QRect>
#include <QPushButton>
#include <tablewidget.h>



class customButton: public QPushButton
{
  Q_OBJECT
  public:
    customButton( const QString& text, const QSize& size, tableWidget* tablewidget = nullptr);
};