#include "custombutton.h"
#include <QDebug>
#include <QRect>
#include <QPushButton>

MainWindow::MainWindow( QWidget *parent ) : QMainWindow(parent), isFullScreen(false)
{
  stackedWidget=new QStackedWidget(this);
  //creating initialLayout
  initialLayoutWidget = new QWidget(this);
  auto initialLayout = new QGridLayout( initialLayoutWidget 
  fullScreenWidget = new QWidget(this);
  fullScreenLayout = new QGridLayout( fullScreenWidget 
  auto left_frame = new QFrame(initialLayoutWidget);
  left_frame->setFrameShape(QFrame::Panel);
  left_frame->setObjectName("left_frame"
  auto right_top_frame = new QFrame(initialLayoutWidget);
  right_top_frame->setFrameShape(QFrame::Panel);
  right_top_frame->setObjectName("right_top_frame"
  auto right_bottom_frame = new QFrame(initialLayoutWidget);
  right_bottom_frame->setFrameShape(QFrame::Panel);
  right_bottom_frame->setObjectName("right_bottom_frame"
  initialLayout->addWidget( left_frame, 0, 0, 2, 1 );
  initialLayout->addWidget( right_top_frame, 0, 1 );
  initialLayout->addWidget( right_bottom_frame, 1, 1 
  nested_right_top_layout = new QGridLayout(initialLayoutWidget);
  auto right_top_left_frame = new QFrame(initialLayoutWidget);
  right_top_left_frame->setFrameShape(QFrame::Panel);
  right_top_left_frame->setObjectName("right_top_left_frame"
  right_top_right_frame = new QFrame(initialLayoutWidget);
  right_top_right_frame->setFrameShape(QFrame::Panel);
  right_top_right_frame->setObjectName("right_top_right_frame"
  nested_right_top_layout->addWidget( right_top_left_frame,1,0 );
  nested_right_top_layout->addWidget( right_top_right_frame,1,1 );
  right_top_frame->setLayout( nested_right_top_layout 
  auto nested_right_bottom_layout = new QGridLayout(initialLayoutWidget);
  auto right_bottom_left_frame = new QFrame(initialLayoutWidget);
  right_bottom_left_frame->setObjectName("right_bottom_left_frame");
  right_bottom_left_frame->setFrameShape(QFrame::Panel);
  auto right_bottom_right_frame = new QFrame(initialLayoutWidget);
  right_bottom_right_frame->setObjectName("right_bottom_right_frame");
  right_bottom_right_frame->setFrameShape(QFrame::Panel
  nested_right_bottom_layout->addWidget( right_bottom_left_frame,0,0 );
  nested_right_bottom_layout->addWidget( right_bottom_right_frame,0,1 );
  right_bottom_frame->setLayout( nested_right_bottom_layout 
  //adding array
  auto rightTopLayout = new QGridLayout(right_top_right_frame);
  auto label1 = new QLabel( "1", right_top_right_frame );
  auto label2 = new QLabel( "2", right_top_right_frame );
  auto label3 = new QLabel( "3", right_top_right_frame );
  auto label4 = new QLabel( "4", right_top_right_frame );
  auto label5 = new QLabel( "5", right_top_right_frame );
  auto label6 = new QLabel( "6", right_top_right_frame );
  auto label7 = new QLabel( "7", right_top_right_frame );
  auto label8 = new QLabel( "8", right_top_right_frame );
  right_top_right_frame->setLayout(rightTopLayout);
  rightTopLayout->addWidget( label1, 0, 0 );
  rightTopLayout->addWidget( label2, 1, 0 );
  rightTopLayout->addWidget( label3, 2, 0 );
  rightTopLayout->addWidget( label4, 3, 0 );
  rightTopLayout->addWidget( label5, 0, 2 );
  rightTopLayout->addWidget( label6, 1, 2 );
  rightTopLayout->addWidget( label7, 2, 2 );
  rightTopLayout->addWidget( label8, 3, 2 )
  //nested_right_top_layout->addWidget(right_top_right_frame,1,1);
  //adding labels
  auto left_label = new QLabel( "Left Frame", left_frame );
  auto right_top_label = new QLabel( "Top Frame", right_top_left_frame );
  auto right_bottom_label = new QLabel( "Bottom Frame", right_bottom_left_frame 
  stackedWidget->addWidget(initialLayoutWidget);
  stackedWidget->addWidget(fullScreenWidget
  auto buttonA = new customButton( "\\", QSize(20,20), this );
  nested_right_top_layout->addWidget( buttonA,0,3 );
  auto buttonB = new customButton( "\\", QSize(20,20), this );
  fullScreenLayout->addWidget( buttonB, 0, 1 );
  
  stackedWidget->setCurrentIndex(0);
  setCentralWidget(stackedWidget);
  this->setWindowTitle("Window");
  this->resize(800,600)
}

void MainWindow::handleButtonClicked()
{
  if( !isFullScreen )
  {
    fullScreenLayout->addWidget( right_top_right_frame, 1, 0 );
    isFullScreen=!isFullScreen;
    stackedWidget->setCurrentIndex(1);
  }
  else
  {
    nested_right_top_layout->addWidget( right_top_right_frame, 1, 1 );
    isFullScreen=!isFullScreen;
    stackedWidget->setCurrentIndex(0);
  }
}
