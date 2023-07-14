#include <QLabel>
#include "tablewidget.h"

tableWidget::tableWidget( QWidget* parent ) : QWidget(parent)
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
  setLayout(gLayout);
  gLayout->setContentsMargins( 5, 5, 5, 5 );
}
void tableWidget::handlegoFull()
{

}