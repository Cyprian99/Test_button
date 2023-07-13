#include "custombutton.h"
#include "invisiblewidget.h"

customButton::customButton( const QString &text, const QSize &size, QWidget* parent )
: QPushButton(text, parent)
{
  setText(text);
  setFixedSize(size);
}
