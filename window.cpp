#include "window.h"
#include "tablewidget.h"
#include <QDebug>
#include <QRect>
#include <QPushButton>

MainWindow::MainWindow( QWidget *parent ) : QMainWindow(parent)
{
  auto stackedWidget=new QStackedWidget(this);
  
  //creating initialLayout
  auto initialLayoutWidget = new QWidget(this);
  auto initialLayout = new QGridLayout(initialLayoutWidget);
  auto fullScreenWidget = new QWidget(this);
  auto fullScreenLayout = new QGridLayout(fullScreenWidget);
  auto left_frame = new QFrame(initialLayoutWidget);
  left_frame->setFrameShape(QFrame::Panel);
  left_frame->setObjectName( "left_frame" );
  auto right_top_frame = new QFrame(initialLayoutWidget);
  right_top_frame->setFrameShape(QFrame::Panel);
  right_top_frame->setObjectName( "right_top_frame" );
  auto right_bottom_frame = new QFrame(initialLayoutWidget);
  right_bottom_frame->setFrameShape(QFrame::Panel);
  right_bottom_frame->setObjectName( "right_bottom_frame" );
  initialLayout->addWidget( left_frame, 0, 0, 2, 1 );
  initialLayout->addWidget( right_top_frame, 0, 1 );
  initialLayout->addWidget( right_bottom_frame, 1, 1 );

  auto nested_right_top_layout = new QGridLayout(initialLayoutWidget);
  auto right_top_left_frame = new QFrame(initialLayoutWidget);
  right_top_left_frame->setFrameShape(QFrame::Panel);
  right_top_left_frame->setObjectName( "right_top_left_frame" );
  nested_right_top_layout->addWidget( right_top_left_frame,1,0 );
  right_top_frame->setLayout(nested_right_top_layout);

  //creating placeholder 
  auto placeholder = new QWidget();
  nested_right_top_layout->addWidget( placeholder, 1, 1 );
  auto placeholderLayout = new QGridLayout(placeholder );
  auto twidget = new tableWidget( stackedWidget, fullScreenLayout, placeholderLayout, stackedWidget );
  placeholderLayout->addWidget( twidget, 0, 0 );

  auto nested_right_bottom_layout = new QGridLayout(initialLayoutWidget);
  auto right_bottom_left_frame = new QFrame(initialLayoutWidget);
  right_bottom_left_frame->setObjectName( "right_bottom_left_frame" );
  right_bottom_left_frame->setFrameShape(QFrame::Panel);
  auto right_bottom_right_frame = new QFrame(initialLayoutWidget);
  right_bottom_right_frame->setObjectName( "right_bottom_right_frame" );
  right_bottom_right_frame->setFrameShape(QFrame::Panel);
  nested_right_bottom_layout->addWidget( right_bottom_left_frame, 0, 0 );
  nested_right_bottom_layout->addWidget( right_bottom_right_frame, 0, 1 );
  right_bottom_frame->setLayout( nested_right_bottom_layout );

  //adding labels
  auto left_label = new QLabel( "Left Frame", left_frame );
  auto right_top_label = new QLabel( "Top Frame", right_top_left_frame );
  auto right_bottom_label = new QLabel( "Bottom Frame", right_bottom_left_frame );

  stackedWidget->addWidget(initialLayoutWidget);
  stackedWidget->addWidget(fullScreenWidget);
  stackedWidget->setCurrentIndex(0);
  setCentralWidget(stackedWidget);

  this->setWindowTitle("Window");
  this->resize(800,600);
}

