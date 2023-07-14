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
    expanderWidget( QWidget *parent = nullptr, QWidget *widget = nullptr, QStackedWidget *stackedWidget = nullptr, QHBoxLayout *placeholderLayout = nullptr );
  public slots:
    void handleButtonClicked();
  signals:
    void goFull(bool isFull);
  private:
    QWidget* m_widget;
    customButton* m_button;
    QStackedWidget* m_stackedWidget;
    QHBoxLayout* m_fullScreenLayout;
    QHBoxLayout* m_placeholderLayout;
    int m_currentIndex;
    bool isFullScreen;
};
#endif //EXPANDERWIDGET_H