#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H
#include <QObject>
#include <QFrame>
#include <QLayout>
#include <QRect>
#include <QPushButton>
#include "invisiblewidget.h"

class invisibleWidget;

class customButton: public QPushButton
{
  Q_OBJECT
  public:
    customButton( const QString &text, const QSize &size, QWidget* parent = nullptr );
};
#endif // CUSTOMBUTTON_H