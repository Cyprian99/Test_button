#ifndef EXPANDERWIDGET_H
#define EXPANDERWIDGET_H
#include <QWidget>
#include <QStackedWidget>
#include <QGridLayout>
#include <QFrame>
#include "custombutton.h"

class customButton;

class expanderWidget : public QWidget
{
  Q_OBJECT
  public: 
    expanderWidget( QWidget *parent = nullptr, QWidget *widget = nullptr, QStackedWidget *stackedWidget = nullptr );
    QHBoxLayout* m_placeholderLayout;
  public slots:
    void handleButtonClicked();
  signals:
    void goFull(bool isFull);
  private:
    QWidget* m_widget;
    QWidget* m_fullScreenWidget;
    customButton* m_button;
    QStackedWidget* m_stackedWidget;
    QHBoxLayout* m_fullScreenLayout;
    int m_currentIndex;
    bool isFullScreen;
};
#endif //EXPANDERWIDGET_H