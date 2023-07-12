#include<QVBoxLayout>
#include<QLabel>
#include<QFrame>
#include<QPushButton>
#include<QPalette>
#include<QFont>
#include<QGraphicsOpacityEffect>
#include<QPropertyAnimation>
#include<QSplitter>
#include<QTableWidget>
#include<QWidget>
#include<QStackedWidget>
#include "fullScreenButton.h"
#include <QMainWindow>
#include<QList>

class MainWindow : public QMainWindow 
{
    Q_OBJECT
public:
    MainWindow( QWidget *parent = nullptr );
public slots:
    void handleButtonClicked();
private:
    QStackedWidget* stackedWidget;
    QWidget* initialLayoutWidget;
    QWidget* fullScreenWidget;
    QFrame* right_top_right_frame;
    QGridLayout* nested_right_top_layout;
    QGridLayout* fullScreenLayout;
    bool isFullScreen;
};