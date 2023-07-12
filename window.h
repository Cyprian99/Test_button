#include<QLabel>
#include<QFrame>
#include<QPushButton>
#include<QWidget>
#include<QStackedWidget>
#include<QGridLayout>
#include<QMainWindow>


class MainWindow : public QMainWindow 
{
    Q_OBJECT
public:
    MainWindow( QWidget *parent = nullptr);
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