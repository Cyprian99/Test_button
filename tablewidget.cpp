#include <QLabel>
#include "custombutton.h"


tableWidget::tableWidget( QStackedWidget* stackedWidget, QGridLayout* fullScreenLayout, QGridLayout* placeholderLayout, QWidget* parent ) : QWidget(parent), m_stackedWidget(stackedWidget), m_fullScreenLayout(fullScreenLayout), m_placeholderLayout(placeholderLayout), isFullScreen(false)
{
  //adding array
  auto gLayout = new QGridLayout(this);
  auto label1 = new QLabel( "1", this );
  auto label2 = new QLabel( "2", this );
  auto label3 = new QLabel( "3", this );
  auto label4 = new QLabel( "4", this );
  auto label5 = new QLabel( "5", this );
  auto label6 = new QLabel( "6", this );
  auto label7 = new QLabel( "7", this );
  auto label8 = new QLabel( "8", this );
  gLayout->addWidget( label1, 0, 0 );
  gLayout->addWidget( label2, 1, 0 );
  gLayout->addWidget( label3, 2, 0 );
  gLayout->addWidget( label4, 3, 0 );
  gLayout->addWidget( label5, 0, 2 );
  gLayout->addWidget( label6, 1, 2 );
  gLayout->addWidget( label7, 2, 2 );
  gLayout->addWidget( label8, 3, 2 );

  //adding button
  auto buttonFullScreen = new customButton( "\\", QSize(20,20), this );
  gLayout->addWidget( buttonFullScreen, 0, 3 );
  setLayout(gLayout);
}
void tableWidget::handleButtonClicked()
{
  if( !isFullScreen )
  {
    m_fullScreenLayout->addWidget(this);
    isFullScreen=!isFullScreen;
    m_stackedWidget->setCurrentIndex(1);
  }
  else
  {
    m_placeholderLayout->addWidget(this);
    isFullScreen=!isFullScreen;
    m_stackedWidget->setCurrentIndex(0);
  }
}
