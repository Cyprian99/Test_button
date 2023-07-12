#include "custombutton.h"
#include <QDebug>

customButton::customButton( const QString &text, const QSize &size, tableWidget* tablewidget )
: QPushButton(tablewidget)
{
  setText(text);
  setFixedSize(size);
  connect( this, &QPushButton::clicked, tablewidget, &tableWidget::handleButtonClicked );
}
