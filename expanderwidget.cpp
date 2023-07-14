#include <QPushButton>
#include "custombutton.h"
#include "expanderwidget.h"
#include <QDebug>

expanderWidget::expanderWidget ( QWidget *parent, QWidget *widget, QStackedWidget *stackedWidget ) :
  QWidget(parent), m_widget(widget), m_stackedWidget(stackedWidget), isFullScreen(false)
{
  m_currentIndex = m_stackedWidget->currentIndex();
  qDebug()<<m_currentIndex;
  m_fullScreenWidget = new QWidget();
  m_fullScreenLayout = new QHBoxLayout(m_fullScreenWidget);
  m_placeholderLayout = new QHBoxLayout(m_widget);
  m_placeholderLayout->addWidget(m_widget);
  m_button = new customButton( QString("\\"), QSize(20,20), m_widget );
  connect( m_button, &QPushButton::clicked, this, &expanderWidget::handleButtonClicked );
}

void expanderWidget::handleButtonClicked()
{
  if( !isFullScreen )
  {
    m_fullScreenLayout->addWidget(m_widget);
    m_stackedWidget->addWidget(m_fullScreenWidget);
    int numberOfWidgets = m_stackedWidget->count();
    qDebug()<<numberOfWidgets;
    m_stackedWidget->setCurrentIndex(numberOfWidgets-1);
    isFullScreen = !isFullScreen;
    emit goFull(true);
    qDebug()<<"Powiększam!";
  }
  else
  {
    emit goFull(false);
    qDebug()<<m_stackedWidget->count();
    m_placeholderLayout->addWidget(m_widget);
    m_stackedWidget->setCurrentIndex(m_currentIndex); 
    isFullScreen = !isFullScreen;
    qDebug()<<"Zmniejszam!";
  }
}