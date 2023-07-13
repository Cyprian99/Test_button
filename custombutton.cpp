#include "custombutton.h"
#include "invisiblewidget.h"
#include <QEvent>
#include <QResizeEvent>
#include <QRect>

customButton::customButton( const QString &text, const QSize &size, QWidget* parent )
: QPushButton( text, parent )
{
  setText(text);
  setFixedSize(size);
  parent->installEventFilter( this );
}
bool customButton::eventFilter( QObject *obj, QEvent *event )
{
  if ( event->type() == QEvent::Resize ) 
  {
    if ( obj == parent() ) 
    {
      QResizeEvent *resizeEvent = static_cast<QResizeEvent *>(event);
      const QSize &parentSize = resizeEvent->size();
      int buttonX = parentSize.width()-width();
      int buttonY = 0;
      QRect buttonRect( buttonX, buttonY, width(), height() );
      setGeometry(buttonRect);
      return true;
    }
  }
  return QPushButton::eventFilter( obj, event );
}
