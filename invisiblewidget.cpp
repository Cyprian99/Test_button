#include <QPushButton>
#include "custombutton.h"
#include "invisiblewidget.h"
#include <QDebug>

invisibleWidget::invisibleWidget ( QWidget *parent, QWidget *widget, QStackedWidget *stackedWidget, QGridLayout *fullScreenLayout, QGridLayout *placeholderLayout ) :
  QWidget(parent), m_widget(widget), m_stackedWidget(stackedWidget), m_fullScreenLayout(fullScreenLayout), m_placeholderLayout(placeholderLayout), isFullScreen(false)
{
  //QWidget* frameWidget = qobject_cast<QWidget*>(placeholderLayout->parent());
  //QRect widgetGeometry = frameWidget->geometry();
  //int buttonX = widgetGeometry.right()-20;
  //int buttonY = widgetGeometry.top(); 
  m_button = new customButton( QString("\\"), QSize(20,20), this );
  //m_button->setGeometry(buttonX,buttonY,20,20);
  //m_button->move(widget->width()-m_button->width(),1);
  connect( m_button, &QPushButton::clicked, this, &invisibleWidget::handleButtonClicked );
}

void invisibleWidget::handleButtonClicked()
{
  if( !isFullScreen )
  {
    m_fullScreenLayout->addWidget(m_widget,1,0);
    m_fullScreenLayout->addWidget(m_button,0,1);
    m_stackedWidget->setCurrentIndex(1);
    isFullScreen = !isFullScreen;
    emit goFull(true);
    qDebug()<<"Powiększam!";
  }
  else
  {
    emit goFull(false);
    m_placeholderLayout->addWidget(m_widget,1,0);
    m_placeholderLayout->addWidget(m_button,0,1);
    m_stackedWidget->setCurrentIndex(0);
    isFullScreen = !isFullScreen;
    qDebug()<<"Zmniejszam!";
  }
}