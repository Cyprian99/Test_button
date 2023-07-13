#include <QPushButton>
#include "custombutton.h"
#include "invisiblewidget.h"
#include <QDebug>

invisibleWidget::invisibleWidget ( QWidget *parent, QWidget *widget, QStackedWidget *stackedWidget, QHBoxLayout *fullScreenLayout, QHBoxLayout *placeholderLayout ) :
  QWidget(parent), m_widget(widget), m_stackedWidget(stackedWidget), m_fullScreenLayout(fullScreenLayout), m_placeholderLayout(placeholderLayout), isFullScreen(false)
{
  m_button = new customButton( QString("\\"), QSize(20,20), m_widget );
  connect( m_button, &QPushButton::clicked, this, &invisibleWidget::handleButtonClicked );
}

void invisibleWidget::handleButtonClicked()
{
  if( !isFullScreen )
  {
    m_fullScreenLayout->addWidget(m_widget);
    m_stackedWidget->setCurrentIndex(1);
    isFullScreen = !isFullScreen;
    emit goFull(true);
    qDebug()<<"Powiększam!";
  }
  else
  {
    emit goFull(false);
    m_placeholderLayout->addWidget(m_widget);
    m_stackedWidget->setCurrentIndex(0); 
    isFullScreen = !isFullScreen;
    qDebug()<<"Zmniejszam!";
  }
}