#include <QWidget>
#include <QStackedWidget>
#include <QGridLayout>

class tableWidget : public QWidget
{
  Q_OBJECT
  public:
    tableWidget( QStackedWidget* stackedWidget, QGridLayout* fullScreenLayout, QGridLayout* placeholderLayout, QWidget* parent=nullptr );
  public slots:
    void handleButtonClicked();
  private:
    QStackedWidget* m_stackedWidget;
    QGridLayout* m_fullScreenLayout;
    QGridLayout* m_placeholderLayout;
    bool isFullScreen;
    
};